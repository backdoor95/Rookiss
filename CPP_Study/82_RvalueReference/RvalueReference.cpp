#include<iostream>


// ������ ���� : ������(rvalue) ������ std::move ---> c++11�� ���� ���� ��ȭ (��� c++�� ��)


using namespace std;

class Pet
{

};

class Knight
{
public:
	
	Knight()
	{
		cout << "Knight()" << endl;
	}

	// ���� ������
	Knight(const Knight& knight)
	{
		cout << "const Knight&" << endl;
	}

	// �̵� ������

	~Knight()
	{
		if (_pet)
			delete _pet;
	}

	// ���� ���� ������
	void operator=(const Knight& knight)
	{
		cout << "operator=(const Knight&)" << endl;

		// ���� ����
		_hp = knight._hp;
		
		if(knight._pet)
		_pet = new Pet(*knight._pet);
	}

	// �̵� ���� ������
	void operator=(Knight&& knight) noexcept
	{
		cout << "operator=(const Knight&&)" << endl;

		// ���� ����
		_hp = knight._hp;

		// knight�� ���̻� �����ҰŶ�� ��Ʈ!
		_pet = knight._pet;

		knight._pet = nullptr;
	}

	void PrintInfo() const// 
	{
		//_hp = 20;// �̰� ����. ���� read only!
	}

public:
	int _hp = 100;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight)
{
	knight._hp = 200;// ������ ������ �� ��!
}

void TestKnight_LValueRef(Knight& knight)
{
	knight._hp = 300;// ������ ����!!!
}

void TestKnight_ConstLValueRef(const Knight& knight)
{
	knight.PrintInfo();// �Լ��� const�� �پ�� ȣ���� ����
}

void TestKnight_RValueRef(Knight&& knight)// �̵� ���!! ������ ���� ����������. --> ������ ����
{
	knight._hp = 500;
}

int main()
{
	// �ް�(lvalue) vs ������(rvalue)
	// - lvalue : ���Ͻ��� �Ѿ ��� ���ӵǴ� ��ü
	// - rvalue : lvalue�� �ƴ� ������ (�ӽ� ��, ������ , ����, i++ ��)

	int a = 3;
	a = 4;


	Knight k1;

	TestKnight_Copy(k1);
	TestKnight_LValueRef(k1);
	//TestKnight_LValueRef(Knight());// Knight()[������]�� �� �� ���� �ӽ������� ��������ٰ�, �Լ�ȣ���� ������ �����.!
	TestKnight_ConstLValueRef(Knight());// lValue �����̿��� �Ķ���Ϳ� const�� ���̸� �������� �ѱ�� �ִ�.

	TestKnight_RValueRef(Knight());

	TestKnight_RValueRef(static_cast<Knight&&>(k1));
	// �ٽ� : ������ ������ �Ѱ�ٴ� ���� ���� ���� �����Ͱ� �������� �ʾƵ� �ȴٵ� ��Ʈ��!

	Knight k2;
	k2._pet = new Pet();
	k2._hp = 1000;

	// ������ ������ �ȴ� <<�� hint�� �ִ� �ʿ� ������.
	Knight k3;
	k3 = static_cast<Knight&&>(k2);// k2�� ������ ���̶�� ��Ʈ�� �ִ°���. �̵� ���� ������ ȣ���. ��� 1
	// �����ϴ°� ���ſ�� �ִ�. �̵��ϴ°� �ξ� �� ���� ������ �� Ȯ���� �ϴ��� ����.

	k3 = move(k2);// ������ ������ ĳ���� static_cast<Knight&&>(k2); �̰ſ� ���� �ǹ�
	// std::move�� ���� �̸� �ĺ� �� �ϳ��� rvalue_cast ---> ���� ����!

	Knight* k;
	unique_ptr<Knight> uptr = make_unique<Knight>();
	//unique_ptr<Knight> uptr2 = uptr;// ������ �߻��ϴ� ������ ������ü�� ��������ʾƼ���.
	unique_ptr<Knight> uptr2 = move(uptr);// ������ ������ ĳ������.! uptr2�� ��� ������ ���ӹ���.





	return 0;
}