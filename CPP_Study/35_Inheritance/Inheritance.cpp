#include<iostream>
using namespace std;

// 오늘의 주제 : 상속성

// 객체지향 (OPP = Object Oriented Programming)
// - 상속성
// - 은닉성
// - 다형성

// 함수는 구조체로 묶어줄수없다.
// 
// 상속(Inheritance) ? 부모 -> 자식에게 유산을 물려주는 것.

// class는 일종의 설계도

// 생성자(N)/소멸자(1)

// 생성자는 탄생을 기념해서 호출되는 함수?
// - Knight 를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 솔로몬의 선택! 그냥 둘다 호출하자!!!!!

/*
void Knight::Move(int y, int x)// 정의를 이렇게 밖에서 해도됨. 대신 어느 클래스 소속인지를 알려주기 위해서 ' :: '을 사용한다.
단 , 상속을 할 때는 ' : '을 사용한다.
*/

// 메모리

// [ [ Player ] ]
// [    Knight   ]

// GameObject
// - Creature : 살아 움직임
// -- Player, Monster, Npc, Pet
// - Projectile : 투사체
// -- Arrow, Fireball
// - Env : environment

// Item
// - Weapon
// -- Sword, Bow
// - Armor
// -- Helmet, Boots, Armor
// - Consumable
// -- Potion, Scroll
class GameObject
{
public:
	int _objectId;
};

class Player : public GameObject
{
public:
	Player()
	{
		_hp=0;
		_attack=0;
		_defence=0;
		cout << "Player() 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player(int hp) 생성자 호출" << endl;
	}

	~Player()
	{
		cout << "~Player() 소멸자 호출" << endl;
	}

	void Move() { cout << "Player Move 호출 " << endl; }
	void Attack() { cout << "Player Attack 호출 " << endl; }
	void Die() { cout << "Player Die 호출 " << endl; }
public:
	int _hp;
	int _attack;
	int _defence;
};

class Knight : public Player // 상속을 시킬때는 ' : ' 이렇게 사용함.
{
public:
	Knight()
		/*
		선(먼저) 처리 영역 
		- 여기서 Player() 기본생성자를 호출
		*/
	{
		_stamina = 100;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100)//********부모의 기본생성자가 아니라 다른 생성자를 고르고 싶을때!!!!!!*********
		/*
		선(먼저) 처리 영역
		- 여기서 Player() 기본생성자를 호출
		*/
	{
		_stamina = stamina;
		cout << "Knight(int stamina) 생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;
	}
	/*
		후(나중에)처리 영역
		- 여기서 ~Player() 소멸자를 호출
	*/

	// 재정의 : 부모님의 유산을 거부하고 새로운 이름으로 만든?
	void Move() { cout << "Knight Move 호출" << endl; }

public:
	int _stamina;
};

class Mage : public Player
{
public:

public:
	int _mp;
};

int main()
{
	Knight k;
	k._hp = 100;
	k._attack = 10;
	k._defence = 5;
	k._stamina = 50;

	k.Move();// 자식이 재정의한 함수 호출
	k.Player::Move();// 재정의를 했음에도 부모의 함수를 호출하고 싶을때.  --> 실질적으로 거의 안쓰임...

	k.Attack();
	k.Die();

	return 0;
}