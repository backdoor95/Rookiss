#include<iostream>
using namespace std;

// ������ ���� : ��ü���� ������
// C++������ struct�� class�� ���� �� �� ���̴�.

// 1) struct vs class 
// struct�� �⺻ ���� �����ڰ� public�̰�, class�� private�̴�.
// �� �̷��� ������? c++�� c���� �Ļ��Ǿ� �����߱� ������, ȣȯ���� ��Ű�� ����.
// -> struct�� �׳� ����ü (������ ����)�� ǥ���ϴ� �뵵
// -> class�� ��ü ���� ���α׷����� Ư¡�� ��Ÿ���� �뵵

struct TestStruct
{
	int _a;
	int _b;
};

class TestClass
{
	int _a;
	int _b;
};

// 2) static ����, static �Լ� (static = ���� = ������)

class Marine
{
public:
	// Ư�� ���� ��ü�� ������
	int _hp;

	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	static void SetAttack() // ���⼭ static ��� ������ ��ĥ�� �ִ�. �ٸ��� �� ��ħ.
	{
		s_attack = 100;
	}

	// Ư�� ���� ��ü�� ����
	// �����̶�� 'Ŭ����' ��ü�� ����
	static int s_attack;// ���赵 �����θ� ���� , Ư�� ��ü�� �����ִ°� �ƴ϶� Ŭ������ �����ְ� �ȴ�.
	// �޸𸮿� �� �ϳ��� ��������� �������� ����ϰ� ��.
};

// static ������ � �޸�?
// �ʱ�ȭ �ϸ� .data
// �ʱ�ȭ �� �ϸ� .bss
int Marine::s_attack =0;

class Player
{
public:
	int _id;
};

int GenerateId()
{

	// �����ֱ� : ���α׷� ����/����(�޸𸮿� �׻� �ö� ����)
	// ���ù��� : static�� ���� ���� ��ü�� ����� �ָ� �ش� �Լ� �������� ����� ����.! -> [�Լ� ����]

	// ���� ���� ��ü -> ������ �ƴ϶� ������ ������ ������.
	static int s_id = 1;
	// ���࿡ int s_id = 1;�� �ڵ带 �ۼ��� �Ź� 1�� ��ȯ
	// �ٵ�  static�� ���̴� ����, �ʱ�ȭ�� �Լ��� ȣ��ɶ� �� 1���� ������ ��.
	// �� ���� ȣ�⿡���� �ʱ�ȭ�� ����.

	return s_id++;
}

int main()
{
	Marine m1;
	m1._hp = 40;
	//m1.s_attack = 6;
	m1.TakeDamage(10);
	Marine::s_attack = 6;

	Marine m2;
	m2._hp = 40;
	//m2.s_attack = 6;

	// ���� ���ݷ� ���׷��̵� �Ϸ�! (Academy���� ���׷��̵� ��)
	//m1.s_attack = 7;
	//m2.s_attack = 7;
	Marine::s_attack = 7;
	Marine::SetAttack();

	// id �� ���� �޸𸮿� ����� ���� �ʴ´�. -> .data ������ �������.
	static int id = 10;
	int a = id;

	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;


	return 0;
}