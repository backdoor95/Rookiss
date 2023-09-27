#include<iostream>
#include<vector>
using namespace std;

// ������ ���� : nullptr

class Knight
{
public:
	void Test()
	{

	}
};

Knight* FindKnight()
{
	//TODO

	return nullptr;
}

void Test(int a)
{
	cout << "Test(int)" << endl;
}

void Test(void* ptr)
{
	cout << "Test(*)" << endl;
}

// nullptr ����

class NullPtr
{
public:
	// �� � Ÿ���� �����Ϳ͵� ġȯ ����
	template<typename T>
	operator T* ()const // �̰� Ÿ�� ��ȯ ������ --
	{
		return 0;
	}
	
	// �� � Ÿ���� ��� �����Ϳ͵� ġȯ ����
	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}

private:
	void operator&() const;// �ּҰ� &�� ���´�. ---> ���� ��Ÿ��
};

const NullPtr _NullPtr;


/*
const
class
{
public:
	// �� � Ÿ���� �����Ϳ͵� ġȯ ����
	template<typename T>
	operator T* ()const // �̰� Ÿ�� ��ȯ ������
	{
		return 0;
	}

	// ��� �Լ� ������ �� ����
	// �� � Ÿ���� ��� �����Ϳ͵� ġȯ ����
	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}

private:
	void operator&() const;// �ּҰ� &�� ���´�. ---> ���� ��Ÿ��
} _nullptr;
// �̷��� �ص� �����ϴ�.

*/


int main()
{
	// define NULL 0
	// 0 NULL
	int* ptr = nullptr;
	int* ptr2 = NULL;// 0 NULL

	int* test1 = _NullPtr;

	// 1) ������
	Test(0);// cout << "Test(int)" << endl;
	Test(NULL);// cout << "Test(int)" << endl;
	// NULL�� 0 �̶� int ȣ���

	Test(nullptr);//cout << "Test(*)" << endl;

	Test(_NullPtr);// ���� ������ �κ�.
	
	// �������� �����ϱ� ���ؼ�
	// nullptr�� ����Ѵ�.

	// 2) ������
	auto knight = FindKnight();
	if (knight == nullptr)
	{

	}
	
	void (Knight:: * memFunc)();
	memFunc = &Knight::Test;

	if (memFunc == _NullPtr)
	{

	}

	auto whoami = nullptr;
	// nullptr_t whoami = nullptr;
	// 



	return 0;
}