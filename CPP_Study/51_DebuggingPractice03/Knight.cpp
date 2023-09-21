#include "Knight.h"
#include <iostream>
using namespace std;

// [사양서] 기본값 Hp=100, Attack=10
Knight::Knight() : _hp(100), _attack(10)
{

}

Knight::Knight(int hp) : _hp(hp), _attack(10)
{

}

Knight::~Knight()
{

}

void Knight::AddHp(int value)
{
	_hp += value;
	if (_hp < 0) _hp = 0;//1. 0 으로 해줘야. 아니면
}

bool Knight::IsDead()
{
	//return (_hp == 0);
	return (_hp <= 0);// 2. 0이거나 음수일때!
}

void Knight::PrintInfo()
{
	cout << _hp << endl;
	cout << _attack << endl;
}