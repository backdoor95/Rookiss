#include "Player.h"
#include "Monster.h"

void Player::KillMonster()
{

	_target2->_hp = 0;// Monster의 설계도를 모르기 때문에 빨간물이뜸.
	// 그래서 include"Monster.h" 해야함.

	// [ 주소 ] -> [ [monsterId][hp][defence] ]
	(*_target2)._hp = 0;

	// push push
	_target2->KillMe();// 이게 정상 작동되려면 
	// 1. 어떤 함수인지
	// 2. 이 함수의 형태를 알아야함.

}

void Player::KillMonster2()
{
	_target2->_hp = 0;
}