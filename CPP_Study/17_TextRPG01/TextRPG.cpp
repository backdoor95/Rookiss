#include<iostream>
using namespace std;

// ������ ���� : TextRPG
enum PlayerType
{
	PT_Knight =1,
	PT_Archer =2,
	PT_Mage=3
};

enum MonsterType
{
	MT_Slime =1,
	MT_Orc=2,
	MT_Skeleton=3
};


int playerType;
int hp;
int attack;
int defence;

int monsterType;
int monsterHp;
int monsterAttack;
int monsterDefence;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();

int main()
{
	// random seed�� �ѹ��� ���ָ��.--main�� �ѹ����ش�.
	srand(time(0));
	EnterLobby();


	return 0;
}

void EnterLobby()
{
	while (true)
	{
		cout << "---------------------" << endl;
		cout << "�κ� �����߽��ϴ�!" << endl;
		cout << "---------------------" << endl;
		// �÷��̾� ���� ����
		SelectPlayer();

		cout << "---------------------" << endl;
		cout << "(1) �ʵ� ���� (2) ���� ����" << endl;
		cout << "---------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();

		}
		else
		{
			return;// �κ� ��������.
		}

	}
}

void SelectPlayer()
{
	while (true)
	{

		cout << "---------------------" << endl;
		cout << "������ ����ּ���!" << endl;
		cout << "(1) ��� (2) �ü� (3)����" << endl;
		cout << "> ";

		cin >> playerType;

		if (playerType == PT_Knight)
		{
			cout << "��� ������....!" << endl;
			hp = 150;
			attack = 10;
			defence = 5;
			break;
		}
		else if (playerType == PT_Archer)
		{
			cout << "�ü� ������....!" << endl;
			hp = 100;
			attack = 15;
			defence = 3;
			break;
		}
		else if (playerType == PT_Mage)
		{
			cout << "������ ������....!" << endl;
			hp = 80;
			attack = 25;
			defence = 0;
			break;
		}
	}

}

void EnterField()
{
	while (true)
	{
		cout << "---------------------" << endl;
		cout << "�ʵ忡 �����߽��ϴ�!" << endl;
		cout << "---------------------" << endl;

		cout << "[PLAYER] HP : " << hp << " /ATT : " << attack << " /DEF : " << defence << endl;
		CreateRandomMonster();
	}
}

void CreateRandomMonster()
{
	// 1~3
	monsterType = 1 + (rand() % 3);

	switch (monsterType)
	{
	case MT_Slime:
		cout << "������ ������...!(HP:15 / ATT:5 / DEF:0)" << endl;
		monsterHp = 15;
		monsterAttack = 5;
		monsterDefence = 0;
		break;
	case MT_Orc:
		cout << "��ũ ������...!(HP:40 / ATT:10 / DEF:3)" << endl;
		monsterHp = 40;
		monsterAttack = 10;
		monsterDefence = 3;
		break;
	case MT_Skeleton:
		cout << "������ ������...!(HP:80 / ATT:15 / DEF:5)" << endl;
		monsterHp = 80;
		monsterAttack = 15;
		monsterDefence = 5;
		break;
	}

}