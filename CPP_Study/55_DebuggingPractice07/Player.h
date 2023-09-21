#pragma once



class Player
{
public:
	Player();
	Player(int hp);

	// �� Ǯ�� : �θ�Ŭ������ �Ҹ��ڰ� �����Լ� ������ ���ؼ� �׷���?
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

