#include "Knight.h"
#include <iostream>
using namespace std;

// [사양서] 기본값 Hp=100, Attack=10
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
	int damage = _attack;

	if (_maxHp > 0)
	{
		int percentage = (100 * _hp) / _maxHp;
		if (percentage <= 50)
			damage *= 2;
	}

	return damage;
}

void Knight::PrintInfo()
{
	cout << "HP: " << _hp << endl;
	cout << "ATT: " << _attack << endl;
}

void Knight::OnDamaged(Knight* attacker)
{
	if (attacker == nullptr)
		return;

	// 내 체력 깎는다
	int damage = attacker->GetAttackDamage();
	AddHp(-damage);



	// 무한 루프에 빠져서 못나옴
	// OnDamaged 함수를 계속 시키기 때문이다. -> 함수를 재귀적으로 호출
	// 무한 반격!!
	// 스택이 고갈되어서 스택오버플로우가 발생!!
	// 이렇게 나오는 조건을 추가해야할듯
	if (_hp == 0)// 내 풀이
	{
		cout << "경기 종료" << endl;
		return;
	}

	if (IsDead())// Rookiss 풀이
		return;

	// 반격!
	attacker->OnDamaged(this);	
}