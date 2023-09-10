#include<iostream>
using namespace std;

// ������ ���� : �迭

struct StatInfo
{
	int hp = 0xAAAAAAAA;// �̷��� �ʱⰪ�� ������ �� �ִ�.
	int attack= 0xBBBBBBBB;
	int defence=0xDDDDDDDD;
};

int main()
{
	// �ٵ� ���Ͱ� �ִ� 1�� ����!
	// ���� ���͸� ���ϰ� ������ �� ������?
	
	//TYPE �̸�[����];

	// �迭�� ũ��� ������� ��. (VS �����Ϸ� ����)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];// ������ ����� �־����.


	// ���²� �������� [�̸�]�� �ٱ����� �̸��̾���.
	int a = 10;
	int b = a;

	// �׷��� �迭�� [�̸�] ���� �ٸ��� �����Ѵ�
	//StatInfo players[10];
	// players = monsters;

	// �׷� �迭�� �̸��� ����?
	// �迭�� �̸��� �� �迭�� ���� �ּ�
	// ��Ȯ���� ���� ��ġ�� ����Ű�� TYPE* ������
	auto WhoAmI = monsters;

	// �ּ�[ (100,10,1) ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ....
	// monster_0[ �ּ� ]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// �������� ����
	// ��¥ 1�� ���϶�°� �ƴ϶�, StatInfo Ÿ�� �ٱ��� �Ѱ��� �̵��϶�� �ǹ�
	// StatInfo[ ] �ּ�[ (200,20,2) ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ....
	// monster_1[ �ּ� ]
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// �����Ϳ� ������ ��������� ��ȯ �����ϴ�.
	// StatInfo[ ] StatInfo[ ] monster_2,�ּ�[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ....
	// monster_2[ �ּ� ]
	StatInfo&monster_2 = *(monsters + 2);// * �̰� ������ �ش� �ּҷ� �̵��϶�� ��
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	//[����] �̰Ŵ� ���� �ٸ� �ǹ̴�.
	// StatInfo[ ] StatInfo[ ] �ּ�[ ���빰 ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ....
	// temp[ ���빰 ]---> 3��° ���빰�� '����'�϶�� �ǹ̴�.
	// �迭�� �ִ� ���� �����͸� '����'�ϴ°� �ƴϴ�.
	StatInfo temp = *(monsters + 2);// * �̰� ������ �ش� �ּҷ� �̵��϶�� ��
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	// �̸� ���� �� �ڵ�ȭ �Ѵ�!
	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);// * �̰� ������ �ش� �ּҷ� �̵��϶�� ��
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = (i + 1);
	}

	// �ٵ� *(monster+i) �ʹ� �����ϰ� �������� ��������.. �� ���� ���?
	// �ε���!
	// �迭�� 0�� ���� ����. N��° �ε����� �ش��ϴ� �����Ϳ� �����Ϸ��� �迭�̸�[N]
	// *(monsters+i) = monsters[i]


	monsters[0].hp = 100;
	monsters[0].attack = 10;
	monsters[0].defence = 1;
	for (int i = 0; i < 10; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = (i + 1);
	}

	// �迭 �ʱ�ȭ ���� ���
	int numbers[5] = {};// ��� ���� 0���� ����
	/*
		int numbers[5] = {};// ��� ���� 0���� ����
00B654E8  xor         eax,eax  
00B654EA  mov         dword ptr [numbers],eax  
00B654F0  mov         dword ptr [ebp-124h],eax  
00B654F6  mov         dword ptr [ebp-120h],eax  
00B654FC  mov         dword ptr [ebp-11Ch],eax  
00B65502  mov         dword ptr [ebp-118h],eax  
	*/
	int numbers1[10] = { 1,2,3,4,5 };// ������ �ֵ��� ������ �����, ������ ������ 0���� �ʱ�ȭ
	/*
		int numbers1[10] = { 1,2,3,4,5 };
00955508  mov         dword ptr [numbers1],1  
00955512  mov         dword ptr [ebp-154h],2  
0095551C  mov         dword ptr [ebp-150h],3  
00955526  mov         dword ptr [ebp-14Ch],4  
00955530  mov         dword ptr [ebp-148h],5  
0095553A  xor         eax,eax  
0095553C  mov         dword ptr [ebp-144h],eax  
00955542  mov         dword ptr [ebp-140h],eax  
00955548  mov         dword ptr [ebp-13Ch],eax  
0095554E  mov         dword ptr [ebp-138h],eax  
00955554  mov         dword ptr [ebp-134h],eax  

	*/

	int numbers2[] = { 1,2,3,4,11,245,666,73,2,1 };// ������ ������ŭ�� ũ�⿡ �ش��ϴ� �迭�� ������ش�.

	char helloStr[]={'H','e','l','l','o','\0'};

	// �迭 ���:
	// 1) �����Ѵ�.
	int arr[10] = {};
	// 2) �ε����� �����ؼ� ���
	arr[1] = 1;
	


	return 0;
}