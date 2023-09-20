#pragma once

enum CreatureType
{
	CT_PLAYER = 0,
	CT_MONSTER = 1
};

class Creature
{
public:
	Creature(int creatureType) : _creatureType(creatureType), _hp(0), _attack(0), _defence(0)
	{

	}

	virtual ~Creature()
	{

	}

	virtual void PrintInfo() = 0;//" = 0 "의 의미는 가상함수는 가상함수인데
	//추상적인 가상함수라는 의미 
	// 반드시 Creature를 상속받은 놈이 재정의를 해야함.

	void OnAttacked(Creature* attacker);
	bool IsDead() { return _hp <= 0; }// 인라인 함수와 관련

protected: 
	int _creatureType;
	int _hp;
	int _attack;
	int _defence;

};

