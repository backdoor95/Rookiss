#include<iostream>
using namespace std;

// ctrl + shift + b = �����ϴ¹�
// 
// ������ ���� : �����ڿ� �Ҹ���

// [������(Constructor)�� �Ҹ���(Destructor)]
// Ŭ������ '�Ҽ�'�� �Լ����� ��� �Լ���� ��
// �� �߿��� ������ Ư���� �Լ� 2���� �ִµ�, �ٷ� [����]�� [��]�� �˸��� �Լ���
// - ���� (ź��) -> ������(������ ���� ����)
// - ��( �Ҹ�) -> �Ҹ��� (���� 1����)

// [�Ͻ���(Implicit) ������]
// �����ڸ� ��������� ������ ������,
// �ƹ� ���ڵ� ���� �ʴ� [�⺻ ������]�� �����Ϸ��� ���� �ڵ����� �������.
//  -> �׷��� �츮�� �����(Explicit)���� �ƹ� ������ �ϳ� �����,
// �ڵ����� ��������� [�⺻ ������]�� �� �̻� ��������� ����!

class Knight// �ؾ Ʋ
{
public:
	//[1] �⺻ ������(���ڰ� ����)
	Knight()
	{
		cout << "Knight() �⺻ ������ ȣ��" << endl;

		_hp = 100;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}



	// [2] ���� ������(�ڱ� �ڽ��� Ŭ���� ���� Ÿ���� ���ڷ� ����)
	// (�Ϲ������� '�Ȱ���' �����͸� ���� ��ü�� �����Ǳ� ����Ѵ�.
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_attack = knight._attack;
		_posX = knight._posX;
		_posY = knight._posY;
	}
	// �Ͻ����� ���� ������(���� ���� �����ڸ� �� ���������)�� ��� �����͸� ���縦 �Ѵ�. 
	// 

	// [3] �⺻ �����ڰ� �ƴҶ�. = ��Ÿ ������
	// �� �߿��� ���ڸ� 1���� �޴� [��Ÿ ������]�� 
	// [Ÿ�� ��ȯ ������]��� �θ��⵵ ��. --> �̰� �Ͻ������� �����Ϸ��� ���ش�. 
	// ��������� ���ֱ� ���ؼ��� explicit �� �ٿ������.
	Knight(int hp)// �����ڴ� �̷��� �����ε� �� �� �ִ�.
	{
		cout << "Knight(int) ������ ȣ��" << endl;
		_hp = hp;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}
	
	// ��������� ���ֱ� ���ؼ��� explicit �� �ٿ������
	//explicit Knight(int hp)// �����ڴ� �̷��� �����ε� �� �� �ִ�.
	//{
	//	cout << "Knight(int) ������ ȣ��" << endl;
	//	_hp = hp;
	//	_attack = 10;
	//	_posY = 0;
	//	_posX = 0;
	//}


	Knight(int hp, int attack, int posX, int posY)
	{
		_hp = hp;
		_attack = attack;
		_posX = posX;
		_posY = posY;
	}

	// �Ҹ��� : �Ҹ��ڴ� ���� 1���� ����
	~Knight()
	{
		cout << "~Knight() �Ҹ��� ȣ��" << endl;
	}




	// ��� �Լ� ����
	// ���� Ŭ������ �ִ� ��� �Լ��� ��������� ������ �����ϴ�.
	void Move(int y, int x);
	void Attack();
	void Die() //���Ǹ� class �ȿ����� �ص���
	{
		// this�� ��ü�� �ִ� �������� �ǹ�.
		_hp = 0;// this->_hp=0;
		cout << "Die" << endl;
	}

public:
	// ��� ������ ǥ���ϴ¹�
	int _hp;// m_hp, mHp, _hp �̷��� 3������ ��ǥ��
	int _attack;
	int _posY;
	int _posX;



};

void Move(Knight* knight, int y, int x)
{
	knight->_posY = y;
	knight->_posX = x;
}

void Knight::Move(int y, int x)// ���Ǹ� �̷��� �ۿ��� �ص���. ��� ��� Ŭ���� �Ҽ������� �˷��ֱ� ���ؼ� ' :: '�� ����Ѵ�.
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

void HelloKnight(Knight k)
{
	cout << "Hello Knight" << endl;
}


// Instantiate = ��ü�� �����!
int main()
{
	//Knight k1;
	//Knight k1(10);
	//Knight k1(100, 10, 0, 0);

	/*
		Knight k1;
00F86247  lea         ecx,[k1]  
00F8624A  call        Knight::Knight (0F81451h)  // ������ ȣ��
00F8624F  mov         dword ptr [ebp-4],0  
	
	*/

	//k1._hp = 100;
	//k1._attack = 10;
	//k1._posY = 0;
	//k1._posX = 0;

	// k1�� sizeof(k1) = 16 --> ��������� �����Ϳ� �����ִ�. , ����Լ��� ���� �޸𸮴� ������ �ʴ´�.


	//Knight k2(k1);//  (1) �̶� ���� �����ڰ� ���������.

	//Knight k3 = k1;// (2)������ �԰� ���ÿ� ���� --> ���� �����ڷ� �������.

	//Knight k4; // (3) �⺻�����ڷ� ���������
	//k4 = k1;// ����, k1�� k4�� ����



	//k1.Move(2, 2);
	//k1.Attack();
	//k1.Die();


	// �Ͻ��� ����ȯ -> �����Ϸ��� �˾Ƽ� �ٲ�ġ��
	int num = 1;

	float f = (float)num;// ����� < �츮�� �ڵ�� num�� float �ٱ��Ͽ� ������� �ֹ��ϰ� ����
	double d = num;// �Ͻ��� << ���� ���ߴµ� �����Ϸ��� �˾Ƽ� ó���ϰ� ����.

	// Ÿ�� ��ȯ ������
	cout << "Ÿ�� ��ȯ ������" << endl;
	Knight k5; // �⺻ �����ڷ� ����
	k5 = 1;// ����  �Ͻ������� hp �Ķ���Ϳ� '1'�� ���� ��Ÿ �����ڰ� ȣ���.
	// 1�� ���� Knight(int) �����ڰ� ȣ���̵ǰ� k5�� ���� �����ѵڿ�
	// 1�� ���� Knight(int)�� �Ҹ��ڰ� ȣ���̵ȴ�.!!!!!!!!!!!!!!
	// k5 = (Knight)1;// explicit�� �ٿ����� ��������� �ڷ����� �ٿ��� Ÿ�Ժ�ȯ�����ڸ� ȣ���� �� �ִ�.

	cout << "K5 hp = " << k5._hp << endl;
	cout << "K5 attack = " << k5._attack << endl;
	cout << "K5 posY = " << k5._posY << endl;
	cout << "K5 posX = " << k5._posX << endl;
	/*
	* OUTPUT 
K5 hp = 1
K5 attack = 10
K5 posY = 0
K5 posX = 0
	*/

	HelloKnight(5);// �̰� �� ��? ---> �׳� �����Ϸ��� �Ͻ������� ���ֱ� ����.
	//HelloKnight((Knight)5);//
	// explicit�� �ٿ����� ��������� �ڷ����� �ٿ��� Ÿ�Ժ�ȯ�����ڸ� ȣ���� �� �ִ�.


	return 0;
	/*
	0056628E  mov         dword ptr [ebp-0F0h],0  
00566298  mov         dword ptr [ebp-4],0FFFFFFFFh  
0056629F  lea         ecx,[k1]  
005662A2  call        Knight::~Knight (056144Ch)  // �Ҹ��� ȣ��
005662A7  mov         eax,dword ptr [ebp-0F0h]  
	*/
}