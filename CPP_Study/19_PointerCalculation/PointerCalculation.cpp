#include<iostream>
using namespace std;

// ������ ���� : ������ ����

// 1. �ּ� ������(&)
// 2. ��� ������(+ -)
// 3. ���� ������(*)
// 4. ���� ��� ������(->)

struct Player
{
	int hp;// 0 offset
	int damage;// 4
};

int main()
{

	int number = 1;
	// 1) �ּ� ������(&)
	// - �ش� ������ �ּҸ� �˷��ּ���~
	// - �� ��Ȯ�� ���ϸ� �ش� ���� Ÿ��(TYPE)�� ���� TYPE* ��ȯ
	int* pointer = &number;

	// 2) ��� ������ (+ -)[���ϱ�, ������� ����]
	// �̷��Ե� �����͵� �����ϴ�.
	//pointer++;
	number += 1;// 1 ����.

	// int*
	// - * : ������ Ÿ���̳�! (8����Ʈ) �ּҸ� ��� �ٱ���!
	// - int : �ּҸ� ���󰡸� int(4����Ʈ ������ �ٱ���)�� �ִٰ� �����ض�!

	// [!] �����Ϳ��� + , - �� ��� �������� 1�� ���ϰų� ����,
	// ���� ' �� ����'�� ���ϰ� ����� �ǹ̰� �ƴϴ�.
	// �ѹ��� TYPE�� ũ�⸸ŭ�� �̵��϶�!
	// ����/���� �ٱ��Ϸ� �̵��ϰ� �ʹ�. << [�ٱ��� ����]�� �̵�����
	// ��, 1�� ���ϸ� = �ٱ��� 1�� �̵����Ѷ�
	// 3�� ���ϸ� �ٱ��� 3�� �̵����Ѷ�

	pointer += 1;// 4 ����. why? - ��������� 1�� �����϶�� ���� �ƴ϶�. ���� �ٱ��Ϸ� �̵����� ��� ��

	// 3) ����������(*)
	// - ��Ż�� Ÿ�� �ش� �ּҷ� ��~ �̵�
	*pointer = 3;
	number = 3;

	Player player;
	player.hp = 100;
	player.damage = 10;

	Player* playerPtr = &player;

	(*playerPtr).hp = 200;
	(*playerPtr).damage = 200;
	
	/*
	
		Player* playerPtr = &player;
			lea         eax,[player]
			mov         dword ptr [playerPtr],eax

		(*playerPtr).hp = 200;
			mov         eax,dword ptr [playerPtr]
			mov         dword ptr [eax],0C8h
		(*playerPtr).damage = 200;
			mov         eax,dword ptr [playerPtr]
			mov         dword ptr [eax+4],0C8h // ������(OFFSET)�� �������� ���������� ��.
	
	*/


	// 4) ���� ��� ������(->)
	//  * :  ���� ������ (��Ż Ÿ�� �ش� �ּҷ� ����.)
	//  . :  ����ü�� Ư�� ����� �ٷ� �� ���(����� ���� ��� . ��ǻ� �׳� ����)
	// -> :  [(*) + (.)] �� �濡!
	playerPtr->hp = 200;
	playerPtr->damage = 200;



	return 0;
}