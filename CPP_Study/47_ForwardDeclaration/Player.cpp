#include "Player.h"
#include "Monster.h"

void Player::KillMonster()
{

	_target2->_hp = 0;// Monster�� ���赵�� �𸣱� ������ �������̶�.
	// �׷��� include"Monster.h" �ؾ���.

	// [ �ּ� ] -> [ [monsterId][hp][defence] ]
	(*_target2)._hp = 0;

	// push push
	_target2->KillMe();// �̰� ���� �۵��Ƿ��� 
	// 1. � �Լ�����
	// 2. �� �Լ��� ���¸� �˾ƾ���.

}

void Player::KillMonster2()
{
	_target2->_hp = 0;
}