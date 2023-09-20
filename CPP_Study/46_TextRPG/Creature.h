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

	virtual void PrintInfo() = 0;//" = 0 "�� �ǹ̴� �����Լ��� �����Լ��ε�
	//�߻����� �����Լ���� �ǹ� 
	// �ݵ�� Creature�� ��ӹ��� ���� �����Ǹ� �ؾ���.

	void OnAttacked(Creature* attacker);
	bool IsDead() { return _hp <= 0; }// �ζ��� �Լ��� ����

protected: 
	int _creatureType;
	int _hp;
	int _attack;
	int _defence;

};

