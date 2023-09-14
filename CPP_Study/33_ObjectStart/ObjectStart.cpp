#include<iostream>
using namespace std;

// ������ ���� ; ��ü������ ����
// ����(procedural) ���� ���α׷���
// -procedure = �Լ�

// ������ + ����(����, ����)

// ��ü���� = ��ü
// ��ü��? -> �÷��̾�, ����, GameRoom

// Knight�� �����غ���
// - �Ӽ�(������): hp, attack, position(y,x)
// - ���(����): Move, Attack, Die


// C++������ ����ü�� Ŭ���� ���̴� public �� ����
// class�� ������ ���赵

class Knight// �ؾ Ʋ
{
public:
	// ��� �Լ� ����
	// ���� Ŭ������ �ִ� ��� �Լ��� ��������� ������ �����ϴ�.
	void Move(int y, int x);
	void Attack();
	void Die() //���Ǹ� class �ȿ����� �ص���
	{
		hp = 0;
		cout << "Die" << endl;
	}

public:
	// ��� ����
	int hp;
	int attack;
	int posY;
	int posX;



};

void Move(Knight *knight, int y, int x)
{
	knight->posY = y;
	knight->posX = x;
}

void Knight::Move(int y, int x)// ���Ǹ� �̷��� �ۿ��� �ص���. ��� ��� Ŭ���� �Ҽ������� �˷��ֱ� ���ؼ� ' :: '�� ����Ѵ�.
{
	posY = y;
	posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << attack << endl;
}


// Instantiate = ��ü�� �����!
int main()
{
	Knight k1;
	k1.hp = 100;
	k1.attack = 10;
	k1.posY = 0;
	k1.posX = 0;

	// k1�� sizeof(k1) = 16 --> ��������� �����Ϳ� �����ִ�. , ����Լ��� ���� �޸𸮴� ������ �ʴ´�.

	Knight k2;
	k2.hp = 80;
	k2.attack = 5;
	k2.posY = 1;
	k2.posX = 1;

	Move(&k1, 2, 2);

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;

}