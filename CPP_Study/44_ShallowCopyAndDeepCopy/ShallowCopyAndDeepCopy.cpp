#include<iostream>
using namespace std;

// ������ ���� : ���� ���� vs ���� ����

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}
	~Pet()
	{
		cout << "~Pet()" << endl;
	}
	Pet(const Pet& pet)// ���������
	{
		cout << "Pet(const Pet&)" << endl;
	}

	Pet& operator=(const Pet& pet)
	{
		cout << "operator=(const Pet&)" << endl;
		return *this;
	}
};

class RabbitPet : public Pet
{

};

class TuttlePet : public Pet
{

};

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}

	// ���� ������
	Player(const Player& player)
	{
		cout << "Player(const Player& player)" << endl;
		_level = player._level;
	}

	// ���� ���� ������
	Player& operator=(const Player& player)
	{
		cout << "operator=(const Player&)" << endl;
		_level = player._level;
		return *this;
	}

public:
	int _level = 0;
};

class Knight : public Player
{
public:
	Knight()
	{
		//_pet = new Pet();
		cout << "Knight()" << endl;
	}

	Knight(const Knight& knight) : Player(knight), _pet2(knight._pet2)
	{
		cout << "Knight(const Knight&)" << endl;
		_hp = knight._hp;
		//_pet = new Pet(*(knight._pet)); // ���� ���� - 1. ���ο� ��ü�� ���� 2. ���ο� ��ü�� ���빰 ���� --> ���� �ٸ� �ּҰ��� ����.
	}

	Knight& operator=(const Knight& knight)
	{
	  cout << "operator=(const Knight& knight)" << endl;
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet));// ���� ����

		_pet2 = knight._pet2;
		Player::operator=(knight);
		return *this;
	}

	~Knight()
	{
		cout << "~Knight()" << endl;
		//delete _pet; // �̷��� �ϸ� �̹� delete�� ���� �� �ٽ� delete ���ִ� ���� �߻�
	}

public:
	int _hp = 100;
	//Pet _pet; // � Ŭ�������� �ٸ� Ŭ������ ��� �������� ��ü�� ������� �ʰ� �����͸� ��� �ִ�.!!!
	Pet* _pet;
	Pet _pet2;
};

int main()
{
	Pet* pet = new Pet();

	Knight knight; // �⺻ ������
	knight._hp = 200;
	knight._pet = pet;
	
	
	cout << "------------- ���� ������ --------------" << endl;
	Knight knight2 = knight; // ���� ������
	// Knight knight3(knight);

	Knight knight3;// �⺻ ������
	cout << "------------- ���� ���� ������ ---------------" << endl;
	knight3 = knight;// ���� ���� ������

	// [���� ������] + [���� ���� ������]
	// �� �� �� ������ָ� �����Ϸ� '�Ͻ�������' ������ش�

	// �߰� ��� ) �����Ϸ��� �˾Ƽ� �� ������ش�?
	// �����ϼ���~ ���� ���� �Ѿ���? << NO --> ������ ��� �����ͳ� ������ ��������� ������ �߻�
	
	// [���� ���� Shallow Copy]
	// ��� �����͸� ��Ʈ�� ������ '�Ȱ���' ���� (�޸� ���� ���� �״�� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> �ּҰ��� �Ȱ��� ���� -> ������ ��ü�� ����Ű�� ���°� ��.
	// Stack : Knight1 [hp 0x1000]	-> Heap 0x1000 Pet[   ]
	// Stack : Knight2 [hp 0x1000] 
	// Stack : Knight3 [hp 0x1000] 


	// [ ���� ���� Deep Copy]
	// ��� �����Ͱ� ����(�ּ�) ���̶��, �����͸� ���� ������ش� (���� ��ü�� �����ϴ� ������ ���� ���� ����)
	// �����ʹ� �ּҰ� �ٱ��� -> ���ο� ��ü�� ���� -> ������ ��ü�� ����Ű�� ���°� ��.
	// Stack : Knight1 [hp 0x1000]	-> Heap 0x1000 Pet[   ]
	// Stack : Knight2 [hp 0x2000]	-> Heap 0x2000 Pet[	  ]
	// Stack : Knight3 [hp 0x3000]  -> Heap 0x3000 Pet[	  ]
	// �����Ϸ��� �Ͻ������� ����� �ִ� [���� ������] + [���� ���� ������] �� �״�� ����ؼ��� deep copy �Ұ�
	// �����ڰ� ����� �����.!!
	/*
	{_hp=0x000000c8 _pet=0x00be2b20 {...} }
	{_hp=0x000000c8 _pet=0x00be2910 {...} }
	{_hp=0x000000c8 _pet=0x00be27c0 {...} }
	*/

	// ��������� �����Ͱ� �ִٰ� �ؼ�, ������ �������縦 �ؾ��ϴ°� �ƴ�!!! ���� �Ϲ������δ� �������縦 ��.

	// ���� )
	// - �Ͻ��� ���� ������ Steps
	// 1) �θ� Ŭ������ ���� ������ ȣ��
	// 2) ��� Ŭ������ ���� ������ ȣ��
	// 3) ����� �⺻ Ÿ���� ��� �޸� ���� (���� ���� Shallow Copy)
	// 
	// console OUTPUT
	// ------------- ���� ������ --------------
	//	Player(const Player & player)
	//	Pet(const Pet&)
	// 
	// 
	// 
	// - ����� ���� ������ Steps
	// 1) �θ� Ŭ������ �⺻ ������ ȣ��
	// 2) ��� Ŭ������ �⺻ ������ ȣ��
	/*		CONSOLE OUTPUT
			------------- ���� ������ --------------
			Player()
			Pet()
			Knight(const Knight&)

	�츮�� �ٸ��� ȣ���϶�� ���� �ʴ� �̻�, �θ�&��� �Ѵ� [�⺻������]�� ȣ���Ѵ�. --> �߸��ϸ� �κ������θ� ���簡 �Ͼ�� �ȴ�.
	*/


	// - �Ͻ��� ���� ���� ������ Steps
	// 1) �θ� Ŭ������ ���� ���� ������ ȣ��
	// 2) ��� Ŭ������ ���� ���� ������ ȣ��
	// 3) ����� �⺻ Ÿ���� ��� �޸� ���� (���� ���� Shallow Copy)
	// 
	//  
	// - ����� ���� ���� ������ Steps
	// 1) �˾Ƽ� ���ִ°� ���� -> �츮�� ���� �˾Ƽ� ó���ؾ���.

	// �� �̷��� ȥ���������?
	// ��ü�� '����' �Ѵٴ� ���� �� ��ü�� ������ ��ġ��Ű���� ��
	// ���� �⺻������ ���� ���� (Shallow Copy) ������� ����

	// ����� ���� -> [��� å��]�� ���α׷������� �����ϰڴٴ� �ǹ�



	return 0;
}