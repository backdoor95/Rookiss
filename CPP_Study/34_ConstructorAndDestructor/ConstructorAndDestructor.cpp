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

	// [3] �⺻ �����ڰ� �ƴҶ�. = ��Ÿ ������
	Knight(int hp)// �����ڴ� �̷��� �����ε� �� �� �ִ�.
	{
		cout << "Knight(int) ������ ȣ��" << endl;
		_hp = hp;
		_attack = 10;
		_posY = 0;
		_posX = 0;
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


// Instantiate = ��ü�� �����!
int main()
{
	Knight k1;

	/*
		Knight k1;
00F86247  lea         ecx,[k1]  
00F8624A  call        Knight::Knight (0F81451h)  // ������ ȣ��
00F8624F  mov         dword ptr [ebp-4],0  
	
	*/

	k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	// k1�� sizeof(k1) = 16 --> ��������� �����Ϳ� �����ִ�. , ����Լ��� ���� �޸𸮴� ������ �ʴ´�.


	Knight k2(k1);// �̶� ���� �����ڰ� ���������.





	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;
	/*
	0056628E  mov         dword ptr [ebp-0F0h],0  
00566298  mov         dword ptr [ebp-4],0FFFFFFFFh  
0056629F  lea         ecx,[k1]  
005662A2  call        Knight::~Knight (056144Ch)  // �Ҹ��� ȣ��
005662A7  mov         eax,dword ptr [ebp-0F0h]  
	*/
}