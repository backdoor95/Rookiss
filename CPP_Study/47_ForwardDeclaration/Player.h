#pragma once

// #include "Monster.h"

//�̰Ŵ� ������ �Ұ���.
class Monster;

// class�� ���赵
class Player
{
public:

	void KillMonster();

	void KillMonster2();

	//void KillMonster2()
	//{
	//	_target2->_hp = 0;//�̰� ���� ������, �����߻�
	//	// ���� Monster�� ���赵�� �𸣱� ����.
	//	// �׷��� ���漱�� �������� ���������� �����߻�.
	//	// �ᱹ #include "Monster.h"�� ����� ����� �ȴ�.
	//	// �׷��� cpp ���� �����ϴ°� ��õ
	//}

public:
	int _hp;
	int _attack;

	//Monster _target;
	Monster* _target2;
	// class Monster* _target2;// �̷��� �ص���.!


	//Player _target3;// �̰� �ȵ�. ��ü���� �޸� ũ�⸦ �𸣱� ����
	Player* _target3;// �̰� ��. �����ʹ� ���� ũ���̱� ������ ��ü �޸� ũ�⸦ �˼� �ֱ� ����

};

