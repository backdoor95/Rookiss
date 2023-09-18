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


//  복사 대입 연산자 *********** 이해하기 까다로움
//	- 대입 연산자가 나온 김에[복사 대입 연산자]에 대해 알아보자
//	용어가 좀 헷갈린다 [복사 생성자] [대입 연산자] [복사 대입 연산자]
//	- 복사 대입 연산자 = 대입 연산자 중, 자기 자신의 참조 타입을 인자로 받는 것


// 기타
// - 모든 연산자를 다 오버로딩 할 수 있는 것은 아니다((::) , (.) , (.*)  이런건 안됨.)
// - 모든 연산자가 다 2개 항이 있는 건 아님. ++,  -- 가 대표적(단항 연산자)
// - 증감 연산자 ++ --
// -- 전위형(++a) operator++()
// -- 후위형(a++) operator++(int)
// (a++)++ : 이건 안됨. -> 통과 안됨.
// ++(++a) : 이건 됨. -> 통과 됨.


class Position
{
public:

	/*
	RET FUNC_NAME(ARG_LIST)
	{

	}
	
	*/
	//  	Position pos3 = pos + pos2; 여기서 pos이걸 기준으로 


	//Position(const Position& arg) // 복사 생성자
	//{

	//}


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


	Position& operator=(int arg)// void보다 자기 자신의 참조값으로 리턴을 해주는 경우가 많음
	{
		_x = arg;
		_y = arg;

		//Position* this = 내 자신의 주소;

		return *this;//*************************
	}

	// [복사 생성자] [복사 대입 연산자] 등 특별 대우를 받는 이유는,
	// 말 그대로 객체가 '복사'되길 원하는 특징 때문.
	// TODO) 동적할당 시간에 더 자세히 알아볼것
	Position& operator=(const Position& arg)// 복사 대입 연산자
	{
		_x = arg._x;
		_y = arg._y;

		//Position* this = 내 자신의 주소;

		return *this;//*************************
	}


	//void operator++()// ++pos; - 전위형 
	//{
	//	_x++;
	//	_y++;
	//}

	Position& operator++()// ++pos; - 전위형 // ++(++a) : 이건 됨. -> 통과 됨. 그래서 void 보다는 참조값을 반환하는 형식으로 만들어줌.
	{
		_x++;
		_y++;
		return *this;
	}

	//void operator++(int) // pos++; - 후위형
	//{
	//	_x++;
	//	_y++;
	//}

	Position operator++(int) // pos++; - 후위형
	{
		// 만약 Position& operator++(int) 으로 바꾸게 되면
		// 여기 스택 메모리에 있는 ret를 반환하게 되는데.
		// ret의 유효 범위는 {...}  안쪽이므로 이걸 리턴하게 되면 큰일남.
		Position ret = *this;
		_x++;
		_y++;
		return ret;
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
	int a = 1;
	int c = (a = 3);

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos + pos2;// 방법 1
	Position pos3_1 = (pos.operator+(pos2));// 방법 2 --> 아마도 복사연산자의 '='을 사용하는듯
	Position pos3_2;
	pos3_2 = pos.operator+(pos2); // 이게 복사 대입 연산자로 인식이 되기 때문에 안되는 거였음.!!!
	pos3_2 = pos + pos2;

	Position pos4 = pos3 + 1;
//	Position pos4 = 1 + pos3;//  이건 안됨. 왼쪽 대상으로 해야하기 때문
	// 이게 되려면 전역연산자 함수 버전으로 만들어야함.


	bool isSame = (pos3 == pos4);

	Position pos5;
	pos5 = 5;
	pos3 = (pos5 = 5);
//	Position pos5 = 5;
	// 이거는 생성되자 마자 5로 초기화 되는 느낌.
	// 5라는 인자를 받는 생성자를 찾게됨.

	//(Pos&)줘~ : 왼쪽       (Pos) 복사값 줄께~ : 오른쪽   그래서 에러가 발생한것임.
	//(cost Pos&)줘~ : 왼쪽       (Pos) 복사값 줄께~ : 오른쪽  이건 에러가 발생 안함.
	// 이 경우에는 타입이 일치하지 않아도 const를 붙이면 에러가 발생하지 않음. 
	
	pos5 = pos3++;// 


	++(++pos3);


	return 0;
}