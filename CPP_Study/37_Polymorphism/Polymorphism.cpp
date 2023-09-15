#include<iostream>
using namespace std;

// ������ ���� : ������

// ��ü���� (OOP)
// - ��Ӽ�
// - ���м� = ĸ��ȭ
// - ������

// ������ (Polymorphism = Poly + morph) : ���°� �پ��ϰ� �ִ°�. ���� �Ȱ�����, ����� �ٸ��� �����Ѵ�.

// - �����ε�(Overloading) = �Լ� �ߺ� ���� = �Լ� �̸��� ����

// - �������̵�(Overriding) = ������ = �θ� Ŭ������ �Լ��� �ڽ� Ŭ�������� ������

// ���ε�(Binding) = ���´�.
// - ���� ���ε�(Static Binding) : ������ ������ ����
// - ���� ���ε�(Dynamic Binding) : ���� ������ ����  ---> ���� �ܰ� ����

// �Ϲ� �Լ��� ���� ���ε��� ���
// ���� ���ε��� ���Ѵٸ�? -> ���� �Լ�(virtual function)

class Player
{
public:
	void Move() { cout << "Move Player !" << endl; }
	//void Move(int a){ cout << "Move Player (int) !" << endl; }
	virtual void VMove(){ cout << "VMove Player !" << endl; }// ���� �Լ��� ����� ���ؼ��� virtual�� �ٿ������. ��쿡 ���� �빮�� V�� �Լ��̸� �տ� �ٿ��ش�.

public:
	int _hp;
};

class Knight : public Player
{
public:
	void Move() { cout << "Move Knight !" << endl; }

	// ���� �Լ��� �����Ǹ� �ϴ��� ���� �Լ���!  ���⼭ virtual�� ���ֵ� �����Լ��̴�.
	virtual void VMove() { cout << "VMove Knight !" << endl; }// ���� �Լ��� ����� ���ؼ��� virtual�� �ٿ������. ��쿡 ���� �빮�� V�� �Լ��̸� �տ� �ٿ��ش�.

public:
	int _stamina;
};
class Mage : public Player
{
public:
	int _mp;
};

void MovePlayer(Player* player)
{
	//player->Move(); // ������ player, knight ���� ���� ����. �׷��� player�� �Լ��� ȣ����.


	player->VMove(); // ���� ���ε�
}

void MoveKnight(Knight* knight)
{
	knight->Move();
}

class Animal
{
	 
};

class Cat : public Animal
{

};

class Dog : public Animal
{

};

int main()
{
	Player p;
	//p.Move();
	//MovePlayer(&p);// �÷��̾�� �÷��̾�� ? YES
	//MoveKnight(&p); // �÷��̾�� ����? NO

	Knight k;
	//k.Move();
	//MoveKnight(&k);// ���� ���� ? YES
	MovePlayer(&k);// ���� �÷��̾��? YES   --> player�� move �Լ� ȣ��


	return 0;
}