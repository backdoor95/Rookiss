#include<iostream>
using namespace std;

// ������ ���� : �Լ� ��ü

void HelloWorld()
{
	cout << "Hello World" << endl;
}

void HelloNumber(int number)
{
	cout << "Hello Number" << number << endl;
}

class Knight
{
public:
	void AddHp(int addHp)
	{
		_hp += addHp;
	}

private:
	int _hp = 100;
};

class Functor
{
public:
	void operator() ()
	{
		// () �� �����ε�
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	bool operator() (int num)
	{
		cout << "Functor Test" << endl;
		_value += num;
		cout << _value << endl;
		return true;
	}

private:
	int _value = 0;
};

class MoveTask
{
public:
	void operator()()
	{
		// TODO
		cout << "�ش� ��ǥ�� �÷��̾� �̵�" << endl;
	}

public:
	int _playerId;
	int _posX;
	int _posY;
};

int main()
{
	// �Լ� ��ü (Functor) : �Լ�ó�� �����ϴ� ��ü
	// �Լ� �������� ����

	// �Լ� ������ ����

	void (*pfunc)(void);

	// ������ �Ѱ��� �� �����ϴ�
	pfunc = &HelloWorld;
	(*pfunc)();

	// �Լ� ������ ����
	// 1) �ñ״�ó�� �� ������ ����� �� ����.
	//pfunc = &HelloNumber;

	// 2) ���¸� ���� �� ����.
	// �Լ��� � ���¸� ���Ҽ� ����.

	

	// �Լ� ��ü��?
	// [�Լ�ó�� ����]�ϴ� ��ü
	HelloWorld();// �Լ�ó�� �����Ϸ��� ()�� ���ؼ� ȣ���Ѵ�.

	// () ������ �����ε��� �ؾ���.

	Functor functor;

	functor();// ������ �����ε��� �Ѵٸ� �̷��� �Լ�ó�� ����� ������.
	// ���� : �Լ� �����Ϳʹ� �ٸ��� �츮�� ���� � ���°��� ��������鼭
	// �Ϲ� �Լ�ó�� ȣ���� �� �ִ�.

	bool ret1 = functor(3);
	bool ret2 = functor(3);
	bool ret3 = functor(3);

	/*
	Functor Test
	0
	Functor Test
	3
	Functor Test
	6
	Functor Test
	9
	
	*/

	// MMO���� �Լ� ��ü�� ����ϴ� ����
	// Ŭ�� <-> ����
	// ���� : Ŭ�� ������ ��Ʈ��ũ ��Ŷ�� �޾Ƽ� ó��
	// ex) Ŭ��: ��(5,0) ��ǥ�� �̵�������!

	// 1. �������� �ϰ��� ������ִ� �κ�
	MoveTask task;
	task._playerId = 100;
	task._posX = 5;
	task._posY = 0;


	// ���߿� ���� �ɶ� �ϰ��� ����
	task();// 2. ������ �����ϴ� �κ� ���� �и�

	// ���߿� �̰� [Ŀ��� ����] �̶�� �Ҹ���.

	return 0;
}