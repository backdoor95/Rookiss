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
};

class RabbitPet : public Pet
{

};

class TuttlePet : public Pet
{

};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet)); // ���� ���� - 1. ���ο� ��ü�� ���� 2. ���ο� ��ü�� ���빰 ���� --> ���� �ٸ� �ּҰ��� ����.
	}

	Knight& operator=(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet));// ���� ����
		return *this;
	}

	~Knight()
	{
		delete _pet; // �̷��� �ϸ� �̹� delete�� ���� �� �ٽ� delete ���ִ� ���� �߻�
	}

public:
	int _hp = 100;
	//Pet _pet; // � Ŭ�������� �ٸ� Ŭ������ ��� �������� ��ü�� ������� �ʰ� �����͸� ��� �ִ�.!!!
	Pet* _pet;
};

int main()
{
	Pet* pet = new Pet();

	Knight knight; // �⺻ ������
	knight._hp = 200;
	knight._pet = pet;

	Knight knight2 = knight; // ���� ������
	// Knight knight3(knight);

	Knight knight3;// �⺻ ������
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



	return 0;
}