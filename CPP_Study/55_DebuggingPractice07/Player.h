#pragma once



class Player
{
public:
	Player();
	Player(int hp);

	// 내 풀이 : 부모클래스의 소멸자가 가상함수 적용을 안해서 그런듯?
	virtual ~Player();

	void PrintInfo();

	void AddHp(int value);
	bool IsDead();

	int GetAttackDamage();

	void OnDamaged(Player* attacker);

public:

	int _hp;
	int _maxHp;
	int _attack;
};

