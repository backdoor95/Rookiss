#include<iostream>
#include<vector>
using namespace std;

// 오늘의 주제 : nullptr

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

// nullptr 구현

class NullPtr
{
public:
	// 그 어떤 타입의 포인터와도 치환 가능
	template<typename T>
	operator T* ()const // 이건 타입 변환 연산자 --
	{
		return 0;
	}
	
	// 그 어떤 타입의 멤버 포인터와도 치환 가능
	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}

private:
	void operator&() const;// 주소값 &를 막는다. ---> 옛날 스타일
};

const NullPtr _NullPtr;


/*
const
class
{
public:
	// 그 어떤 타입의 포인터와도 치환 가능
	template<typename T>
	operator T* ()const // 이건 타입 변환 연산자
	{
		return 0;
	}

	// 멤버 함수 포인터 와 연관
	// 그 어떤 타입의 멤버 포인터와도 치환 가능
	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}

private:
	void operator&() const;// 주소값 &를 막는다. ---> 옛날 스타일
} _nullptr;
// 이렇게 해도 가능하다.

*/


int main()
{
	// define NULL 0
	// 0 NULL
	int* ptr = nullptr;
	int* ptr2 = NULL;// 0 NULL

	int* test1 = _NullPtr;

	// 1) 오동작
	Test(0);// cout << "Test(int)" << endl;
	Test(NULL);// cout << "Test(int)" << endl;
	// NULL이 0 이라서 int 호출됨

	Test(nullptr);//cout << "Test(*)" << endl;

	Test(_NullPtr);// 직접 구현한 부분.
	
	// 오동작을 방지하기 위해서
	// nullptr를 사용한다.

	// 2) 가독성
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