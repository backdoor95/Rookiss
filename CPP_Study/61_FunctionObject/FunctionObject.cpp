#include<iostream>
using namespace std;

// 오늘의 주제 : 함수 객체

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
		// () 를 오버로딩
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
		cout << "해당 좌표로 플레이어 이동" << endl;
	}

public:
	int _playerId;
	int _posX;
	int _posY;
};

int main()
{
	// 함수 객체 (Functor) : 함수처럼 동작하는 객체
	// 함수 포인터의 단점

	// 함수 포인터 선언

	void (*pfunc)(void);

	// 동작을 넘겨줄 때 유용하다
	pfunc = &HelloWorld;
	(*pfunc)();

	// 함수 포인터 단점
	// 1) 시그니처가 안 맞으면 사용할 수 없다.
	//pfunc = &HelloNumber;

	// 2) 상태를 가질 수 없다.
	// 함수는 어떤 상태를 지닐수 없다.

	

	// 함수 객체란?
	// [함수처럼 동작]하는 객체
	HelloWorld();// 함수처럼 동작하려면 ()를 통해서 호출한다.

	// () 연산자 오버로딩을 해야함.

	Functor functor;

	functor();// 연산자 오버로딩을 한다면 이렇게 함수처럼 사용이 가능함.
	// 장점 : 함수 포인터와는 다르게 우리가 이제 어떤 상태값도 들고있으면서
	// 일반 함수처럼 호출할 수 있다.

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

	// MMO에서 함수 객체를 사용하는 예시
	// 클라 <-> 서버
	// 서버 : 클라가 보내준 네트워크 패킷을 받아서 처리
	// ex) 클라: 나(5,0) 좌표로 이동시켜줘!

	// 1. 논리적으로 일감을 만들어주는 부분
	MoveTask task;
	task._playerId = 100;
	task._posX = 5;
	task._posY = 0;


	// 나중에 여유 될때 일감을 실행
	task();// 2. 실제로 실행하는 부분 으로 분리

	// 나중에 이걸 [커멘드 패턴] 이라고 불린다.

	return 0;
}