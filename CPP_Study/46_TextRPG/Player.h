#pragma once
#include "Creature.h"

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};
// 실제로 구현부는 cpp 파일에 하는게 일반적
/// 그러나 짧은 부분은 헤더에 만들어도된긴함.

// Player는 Creature가 누군지 모름. include 해야함.
class Player : public Creature
{
public:
	Player(int playerType) : Creature(CT_PLAYER), _playerType(playerType)
	{

	}

	// 부모클래스의 소멸자는 항상 virtual로 만들어준다.
	virtual ~Player()
	{

	}
protected:
	int _playerType;
	
};

class Knight : public Player
{
public:
	Knight() :Player(PT_Knight)
	{
		_hp = 150;
		_attack = 10;
		_defence = 5;
	}
};

class Archer : public Player
{
public:
	Archer() :Player(PT_Archer)
	{
		_hp = 80;
		_attack = 15;
		_defence = 3;
	}
};

class Mage : public Player
{
public:
	Mage() :Player(PT_Mage)
	{
		_hp = 50;
		_attack = 25;
		_defence = 0;
	}
};