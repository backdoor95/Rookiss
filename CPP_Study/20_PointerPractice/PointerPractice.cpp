#include<iostream>
using namespace std;

// 오늘의 주제 : 포인터 실습.

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
	cout << "로비에 입장했습니다" << endl;

	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defence = 0xbbbbbbbb;

	// [매개변수][RET][지역변수(temp(100,10,2) ,player(100,10,2)] [매개변수(&temp)][RET][지역변수(ret(100,10,2))]
	// 복사가 복잡하게 일어남... 만약 mmoRPG 였다면, playerInfo가 어마어마하게 커질수 있다.
	// 중간중간 복사가 일어나면 성능적인 부하를 야기한다.
	player = CreatePlayer();// 리턴값 반환
	/*
	player = CreatePlayer();// 리턴값 반환
0066255D  lea         eax,[ebp-110h]   강의와 다르게 나는 이부분이 c,c,c가 아니라 
00662563  push        eax  // 이게 temp의 주[&temp]를 stack에 넣어줌.
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

	//[매개변수][RET][지역변수(monster(40,8,1)] [매개변수(&monster)][RET][지역변수]
	CreateMonster(&monster);// 포인터를 받아서 세팅
	// 이렇게 하는게 위에 방식보다 더 좋다. 복사하는 과정이 없다.
	/*
	
	CreateMonster(&monster);// 포인터를 받아서 세팅
009D25B6  lea         eax,[monster]  
009D25B9  push        eax  
009D25BA  call        CreateMonster (09D1091h)  
009D25BF  add         esp,4  
	
	
	*/

	// 번외편 1)
	// 구조체끼리 복사할 때 무슨 일이 벌어질까?
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
		cout << "승리!" << endl;
	else
		cout << "패배!" << endl;

}

StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "플레이어 생성" << endl;
	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;

}

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

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

		cout << "몬스터 HP : " << monster->hp << endl;

		if (monster->hp == 0)
			return true;

		damage = monster->attack - player->defence;
		if (damage < 0)
			damage = 0;

		cout << "플레이어 HP : " << monster->hp << endl;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		if (player->hp == 0)
			return false;
	}
}