#include<iostream>
using namespace std;

// 오늘의 주제 : 초기화 리스트

// 멤버 변수 초기화 ? 다양한 문법이 존재

// 초기화 왜 해야할까? 귀찮다~
// - 버그 예방에 중요
// - 포인터 등 주소값이 연루되어 있을 경우

// 초기화 방법
// - 생성자 내에서
// - 초기화 리스트
// - C++11 문법
// 초기화를 하지 않으면 쓰레기 값이 들어간다.

/**************************************************************************************/

// 초기화 리스트 --> 선처리 영역에서 초기화가 이루어짐
// - 일단 상속 관계에서 원하는 부모 생성자 호출할 때 필요하다.
// - [생성자 내에서 초기화 vs 초기화 리스트]
// -- 일반 변수는 별 차이 없음[ 기본 타입일 경우]
// -- 멤버 타입이 클래스인 경우 차이가 난다.
// -- 정의함과 동시에 초기화가 필요한 경우 (참조 타입, const 타입)
// 정리 : 내부에서 만들어지게 되면 생성자가 2번이 호출될 경우가 있기 때문에
//		  클래스 멤버변수를 초기화 할때는 초기화 리스트 방식을 사용하는게 좋다!!!!!!!!

/**************************************************************************************/


// 초기화 리스트  예시
//	Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100) // 초기화 방식 2가지.!


class Inventory
{
public:

public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size){ cout << "Inventory(int size)" << endl; }
	~Inventory() { cout << "~Inventory()" << endl; }

public:
	int _size = 10;
};
class Player
{
public:
	Player()
	{

	}
	Player(int id)
	{

	}
};
// *************************************************************************
// Is-A (Knight Is-A Player? 기사는 플레이어다) OK -> 상속관계
// Is-A (Knight Is-A Inventory? 기사는 인벤토리냐?) NO -> 포함관계
// 
// Has-A (Knight Has_A Inventor? 기사는 인벤토리를 포함하고 있다 갖고 있다) OK -> 포함관계

// 여기서 Has-A 관계이기 때문에 인벤토리를 Knight의 멤버변수로 만들어준다.[포함관계]


// *************************************************************************

class Monster
{

};

class Knight : public Player
{
public:
	Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100) // 초기화 방식 2가지.!
		/*
			선처리 영역
			여기서 Inventory의 기본생성자가 같이 호출이된다.
			_inventory = Inventory() // 인벤토리의 기본 생성자를 이용해서 인벤토리 멤버변수가 만들어짐.
			단, 위에 _inventory(20)이렇게 초기화를 할 경우 . 기본생성자는 호출되지 않고, 기타생성자가 호출 -> 인벤토리 멤버변수가 만들어짐.
		
			초기화를 할때는 함수 내부에서 하기보다는, 위에 방식(초기화 리스트)를 이용하는게 좋다.

		
		*/
	{
		_hp = 100;
		//_inventory = Inventory(20); // 이걸 추가하면 인벤토리 생성자가 또 호출이 된다.
	}

	/*
	* 
	* [콘솔창 output]
	Inventory()// - 1
	Inventory(int size)// - 2
	~Inventory()// 2가 1를 덮어씌우면서 1번에 대한 소멸자가 호출됨.
	100
	~Inventory()

	
	*/





public:
	int _hp = 200;// 이렇게 초기화 할 수 있다. 모던 C++ 방식임.
	Inventory _inventory;

// -- 정의함과 동시에 초기화가 필요한 경우 (참조 타입, const 타입)
	int& _hpRef;
	const int _hpConst;

};

int main()
{
	/*
	컴파일 레벨을 조절을 할 수 있다. 
	경고, 에러를 설정이 가능하다.!!!
	*/
	Knight k;

	cout << k._hp << endl;

	if (k._hp < 0)
	{
		cout << "Knight is Dead" << endl;
	}

	return 0;
}