#include<iostream>
using namespace std;
#include"Player.h"

// ������ ���� : ���漱��

int main()
{
	//�÷��̾��� ���谡 �ϼ��� �Ǿ�� ���尡 �����.
	//�޸𸮿� �÷��̾ ������ֱ� ���ؼ��� �÷��̾� ũ�Ⱑ �� ����Ʈ������ �˾ƾ���.
	//
	// �ٽ� : Player�� �� ����Ʈ?
	// int 2�� = 2* 4����Ʈ= 8����Ʈ
	// Monster -- ?
	// sizeof(Monster*) = 4or8

	Player p1; // �������� (Stack)

	Player* p2 = new Player();// �����Ҵ�(Heap)

	return 0;
}