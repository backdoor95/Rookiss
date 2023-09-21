#include "Knight.h"
#include <iostream>
using namespace std;

// [��缭] �⺻�� Hp=100, Attack=10
Knight::Knight() : _hp(100), _maxHp(100), _attack(10)
{

}

Knight::Knight(int hp) : _hp(hp), _maxHp(hp), _attack(10)
{

}

Knight::~Knight()
{

}

void Knight::AddHp(int value)
{
	_hp += value;
	if (_hp < 0)
		_hp = 0;
	if (_hp > _maxHp)
		_hp = _maxHp;
}

bool Knight::IsDead()
{
	return (_hp <= 0);
}

int Knight::GetAttackDamage()
{
	// hp 50% ���� => maxHp / hp�� 2 �̻�
	int damage = _attack;

	if (_hp == 0)
		return 0;

	int percentage = (double)_hp / _maxHp * 100;
	// or  int percentage = (100*_hp) / _maxHp;// ���������� ������ �׻� �����ض�! �ִ� ������ �ʰ��Ҽ� ������ �ִ�.


	if (percentage <= 50)
	{
		return damage * 2;
	}

	int ratio = _maxHp / _hp;// ������ ���� 0�϶� ũ���ð� �߻�.!
	if (ratio > 2)
		damage *= 2;

	return damage;
}

void Knight::PrintInfo()
{
	cout << "HP: " << _hp << endl;
	cout << "ATT: " << _attack << endl;
}