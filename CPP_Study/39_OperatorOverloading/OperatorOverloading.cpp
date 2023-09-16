#include<iostream>
using namespace std;

// 오늘의 주제 : 연산자 오버로딩(Operator Overloading)

// 연산자 vs 함수
// - 연산자는 피연산자의 개수 / 타입이 고정되어 있음.

// 연산자 오버로딩?
// 일단 [연산자 함수] 를 정의해야 함.
// 함수도 멤버함수 vs 전역함수가 존재하는것처럼, 연산자 함수도 두가지 방식으로 만들 수 있음.

// - 멤버 연산자 함수 version
// -- a op b 형태에서 왼쪽으로 기준으로 실행됨.(a가 클래스여야 가능. a를 '기준 피연산자'라고 함)
// -- 한계) a가 클래스가 아니면 사용 못함.

// - 전역 연산자 함수 version
// -- a op b 형태라면 a, b 모두를 연산자 함수의 피연산자로 만들어준다.


// 그럼 어떤 version이 좋은가? 그런거 없음. 심지어 둘 중 하나만 지원하는 경우도 있기 때문.
// - 대표적으로 대입 연산자 ( a = b )는 전역 연산자 version으로는 못 만듬.


class Position
{
public:

	/*
	RET FUNC_NAME(ARG_LIST)
	{

	}
	
	*/
	//  	Position pos3 = pos + pos2; 여기서 pos이걸 기준으로 

	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;

		return pos;
	}

	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;

		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}

	void operator=(int arg)
	{
		_x = arg;
		_y = arg;
	}

public:
	int _x;
	int _y;


};

// 이렇게는 안됨.!!!
//void operator=(const Position&a,int b)
//{
//	a._x = b;
//	a._y = b;
//}

Position operator+(int a, const Position& b)
{
	Position ret;

	ret._x = b._x + a;
	ret._y = b._y + a;

	return ret;
}


int main()
{

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos + pos2;// 방법 1
	pos3 = pos.operator+(pos2);// 방법 2

	Position pos4 = pos3 + 1;
//	Position pos4 = 1 + pos3;//  이건 안됨. 왼쪽 대상으로 해야하기 때문
	// 이게 되려면 전연연산자 함수 버전으로 만들어야함.


	bool isSame = (pos3 == pos4);

	Position pos5;
	pos5 = 5;
//	Position pos5 = 5;
	// 이거는 생성되자 마자 5로 초기화 되는 느낌.
	// 5라는 인자를 받는 생성자를 찾게됨.



	return 0;
}