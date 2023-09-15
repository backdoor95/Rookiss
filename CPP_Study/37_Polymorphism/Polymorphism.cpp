#include<iostream>
using namespace std;

// 오늘의 주제 : 다형성

// 객체지향 (OOP)
// - 상속성
// - 은닉성 = 캡슐화
// - 다형성

// 다형성 (Polymorphism = Poly + morph) : 형태가 다양하게 있는것. 겉은 똑같은데, 기능이 다르게 동작한다.

// - 오버로딩(Overloading) = 함수 중복 정의 = 함수 이름의 재사용

// - 오버라이딩(Overriding) = 재정의 = 부모 클래스의 함수를 자식 클래스에서 재정의

// 바인딩(Binding) = 묶는다.
// - 정적 바인딩(Static Binding) : 컴파일 시점에 결정
// - 동적 바인딩(Dynamic Binding) : 실행 시점에 결정  ---> 면접 단골 질문

// 일반 함수는 정적 바인딩을 사용
// 동적 바인딩을 원한다면? -> 가상 함수(virtual function)

class Player
{
public:
	void Move() { cout << "Move Player !" << endl; }
	//void Move(int a){ cout << "Move Player (int) !" << endl; }
	virtual void VMove(){ cout << "VMove Player !" << endl; }// 가상 함수를 만들기 위해서는 virtual를 붙여줘야함. 경우에 따라서 대문자 V를 함수이름 앞에 붙여준다.

public:
	int _hp;
};

class Knight : public Player
{
public:
	void Move() { cout << "Move Knight !" << endl; }

	// 가상 함수는 재정의를 하더라도 가상 함수다!  여기서 virtual를 없애도 가상함수이다.
	virtual void VMove() { cout << "VMove Knight !" << endl; }// 가상 함수를 만들기 위해서는 virtual를 붙여줘야함. 경우에 따라서 대문자 V를 함수이름 앞에 붙여준다.

public:
	int _stamina;
};
class Mage : public Player
{
public:
	int _mp;
};

void MovePlayer(Player* player)
{
	//player->Move(); // 원본이 player, knight 인지 구분 못함. 그래서 player의 함수를 호출함.


	player->VMove(); // 동적 바인딩
}

void MoveKnight(Knight* knight)
{
	knight->Move();
}

class Animal
{
	 
};

class Cat : public Animal
{

};

class Dog : public Animal
{

};

int main()
{
	Player p;
	//p.Move();
	//MovePlayer(&p);// 플레이어는 플레이어다 ? YES
	//MoveKnight(&p); // 플레이어는 기사다? NO

	Knight k;
	//k.Move();
	//MoveKnight(&k);// 기사는 기사다 ? YES
	MovePlayer(&k);// 기사는 플레이어다? YES   --> player의 move 함수 호출


	return 0;
}