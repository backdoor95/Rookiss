#include<iostream>
using namespace std;

// 오늘의 주제 ; 객체지향의 시작
// 절차(procedural) 지향 프로그래밍
// -procedure = 함수

// 데이터 + 가공(로직, 동작)

// 객체지향 = 객체
// 객체란? -> 플레이어, 몬스터, GameRoom

// Knight를 설계해보자
// - 속성(데이터): hp, attack, position(y,x)
// - 기능(동작): Move, Attack, Die


// C++에서는 구조체와 클래스 차이는 public 의 유무
// class는 일종의 설계도

class Knight// 붕어빵 틀
{
public:
	// 멤버 함수 선언
	// 같은 클래스에 있는 멤버 함수는 멤버변수에 접근이 가능하다.
	void Move(int y, int x);
	void Attack();
	void Die() //정의를 class 안에서도 해도됨
	{
		hp = 0;
		cout << "Die" << endl;
	}

public:
	// 멤버 변수
	int hp;
	int attack;
	int posY;
	int posX;



};

void Move(Knight *knight, int y, int x)
{
	knight->posY = y;
	knight->posX = x;
}

void Knight::Move(int y, int x)// 정의를 이렇게 밖에서 해도됨. 대신 어느 클래스 소속인지를 알려주기 위해서 ' :: '을 사용한다.
{
	posY = y;
	posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << attack << endl;
}


// Instantiate = 객체를 만든다!
int main()
{
	Knight k1;
	k1.hp = 100;
	k1.attack = 10;
	k1.posY = 0;
	k1.posX = 0;

	// k1의 sizeof(k1) = 16 --> 멤버변수만 데이터에 잡혀있다. , 멤버함수에 대한 메모리는 잡히지 않는다.

	Knight k2;
	k2.hp = 80;
	k2.attack = 5;
	k2.posY = 1;
	k2.posX = 1;

	Move(&k1, 2, 2);

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;

}