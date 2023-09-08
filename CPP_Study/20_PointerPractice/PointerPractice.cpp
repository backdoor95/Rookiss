#include<iostream>
using namespace std;

// ������ ���� : ������ �ǽ�.

struct StatInfo
{
	int hp; //+0
	int attack;//+4
	int defence;//+8
};
void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo*info);
bool StartBattle(StatInfo* player, StatInfo* monster);
int main()
{
	EnterLobby();
	return 0;
}

void EnterLobby()
{
	cout << "�κ� �����߽��ϴ�" << endl;

	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defence = 0xbbbbbbbb;

	// [�Ű�����][RET][��������(temp(100,10,2) ,player(100,10,2)] [�Ű�����(&temp)][RET][��������(ret(100,10,2))]
	// ���簡 �����ϰ� �Ͼ... ���� mmoRPG ���ٸ�, playerInfo�� ���ϰ� Ŀ���� �ִ�.
	// �߰��߰� ���簡 �Ͼ�� �������� ���ϸ� �߱��Ѵ�.
	player = CreatePlayer();// ���ϰ� ��ȯ
	/*
	player = CreatePlayer();// ���ϰ� ��ȯ
0066255D  lea         eax,[ebp-110h]   ���ǿ� �ٸ��� ���� �̺κ��� c,c,c�� �ƴ϶� 
00662563  push        eax  // �̰� temp�� ��[&temp]�� stack�� �־���.
00662564  call        CreatePlayer (06612FDh)  
00662569  add         esp,4  
0066256C  mov         ecx,dword ptr [eax]  
0066256E  mov         dword ptr [ebp-0FCh],ecx  
00662574  mov         edx,dword ptr [eax+4]  
00662577  mov         dword ptr [ebp-0F8h],edx  
0066257D  mov         eax,dword ptr [eax+8]  
00662580  mov         dword ptr [ebp-0F4h],eax  
00662586  mov         ecx,dword ptr [ebp-0FCh]  
0066258C  mov         dword ptr [player],ecx  
0066258F  mov         edx,dword ptr [ebp-0F8h]  
00662595  mov         dword ptr [ebp-10h],edx  
00662598  mov         eax,dword ptr [ebp-0F4h]  
0066259E  mov         dword ptr [ebp-0Ch],eax  
	*/


	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.attack = 0xbbbbbbbb;
	monster.defence = 0xbbbbbbbb;

	//[�Ű�����][RET][��������(monster(40,8,1)] [�Ű�����(&monster)][RET][��������]
	CreateMonster(&monster);// �����͸� �޾Ƽ� ����
	// �̷��� �ϴ°� ���� ��ĺ��� �� ����. �����ϴ� ������ ����.
	/*
	
	CreateMonster(&monster);// �����͸� �޾Ƽ� ����
009D25B6  lea         eax,[monster]  
009D25B9  push        eax  
009D25BA  call        CreateMonster (09D1091h)  
009D25BF  add         esp,4  
	
	
	*/

	// ������ 1)
	// ����ü���� ������ �� ���� ���� ��������?
	//
	player = monster;
	/*
		player = monster;
00C625C2  mov         eax,dword ptr [monster]  
00C625C5  mov         dword ptr [player],eax  
00C625C8  mov         ecx,dword ptr [ebp-24h]  
00C625CB  mov         dword ptr [ebp-10h],ecx  
00C625CE  mov         edx,dword ptr [ebp-20h]  
00C625D1  mov         dword ptr [ebp-0Ch],edx  
	*/

	bool victory = StartBattle(&player, &monster);

	if (victory)
		cout << "�¸�!" << endl;
	else
		cout << "�й�!" << endl;

}

StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "�÷��̾� ����" << endl;
	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;

}

void CreateMonster(StatInfo* info)
{
	cout << "���� ����" << endl;

	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
	while (true)
	{
		int damage = player->attack - monster->defence;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		cout << "���� HP : " << monster->hp << endl;

		if (monster->hp == 0)
			return true;

		damage = monster->attack - player->defence;
		if (damage < 0)
			damage = 0;

		cout << "�÷��̾� HP : " << monster->hp << endl;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		if (player->hp == 0)
			return false;
	}
}