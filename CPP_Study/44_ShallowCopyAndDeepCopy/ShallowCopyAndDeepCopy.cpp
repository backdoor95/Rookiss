#include<iostream>
using namespace std;

// 오늘의 주제 : 얕은 복사 vs 깊은 복사

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}
	~Pet()
	{
		cout << "~Pet()" << endl;
	}
	Pet(const Pet& pet)// 복사생성자
	{
		cout << "Pet(const Pet&)" << endl;
	}

	Pet& operator=(const Pet& pet)
	{
		cout << "operator=(const Pet&)" << endl;
		return *this;
	}
};

class RabbitPet : public Pet
{

};

class TuttlePet : public Pet
{

};

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}

	// 복사 생성자
	Player(const Player& player)
	{
		cout << "Player(const Player& player)" << endl;
		_level = player._level;
	}

	// 복사 대입 연산자
	Player& operator=(const Player& player)
	{
		cout << "operator=(const Player&)" << endl;
		_level = player._level;
		return *this;
	}

public:
	int _level = 0;
};

class Knight : public Player
{
public:
	Knight()
	{
		//_pet = new Pet();
		cout << "Knight()" << endl;
	}

	Knight(const Knight& knight) : Player(knight), _pet2(knight._pet2)
	{
		cout << "Knight(const Knight&)" << endl;
		_hp = knight._hp;
		//_pet = new Pet(*(knight._pet)); // 깊은 복사 - 1. 새로운 객체를 생성 2. 새로운 객체에 내용물 복사 --> 서로 다른 주소값을 가짐.
	}

	Knight& operator=(const Knight& knight)
	{
	  cout << "operator=(const Knight& knight)" << endl;
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet));// 깊은 복사

		_pet2 = knight._pet2;
		Player::operator=(knight);
		return *this;
	}

	~Knight()
	{
		cout << "~Knight()" << endl;
		//delete _pet; // 이렇게 하면 이미 delete된 놈을 또 다시 delete 해주는 일이 발생
	}

public:
	int _hp = 100;
	//Pet _pet; // 어떤 클래스에서 다른 클래스를 들고 있을때는 자체를 들고있지 않고 포인터를 들고 있다.!!!
	Pet* _pet;
	Pet _pet2;
};

int main()
{
	Pet* pet = new Pet();

	Knight knight; // 기본 생성자
	knight._hp = 200;
	knight._pet = pet;
	
	
	cout << "------------- 복사 생성자 --------------" << endl;
	Knight knight2 = knight; // 복사 생성자
	// Knight knight3(knight);

	Knight knight3;// 기본 생성자
	cout << "------------- 복사 대입 연산자 ---------------" << endl;
	knight3 = knight;// 복사 대입 연산자

	// [복사 생성자] + [복사 대입 연산자]
	// 둘 다 안 만들어주면 컴파일러 '암시적으로' 만들어준다

	// 중간 결론 ) 컴파일러가 알아서 잘 만들어준다?
	// 수고하세요~ 다음 주제 넘어갈까요? << NO --> 복사할 대상에 포인터나 참조가 들어있으면 문제가 발생
	
	// [얕은 복사 Shallow Copy]
	// 멤버 데이터를 비트열 단위로 '똑같이' 복사 (메모리 영역 값을 그대로 복사)
	// 포인터는 주소값 바구니 -> 주소값을 똑같이 복사 -> 동일한 객체를 가리키는 상태가 됨.
	// Stack : Knight1 [hp 0x1000]	-> Heap 0x1000 Pet[   ]
	// Stack : Knight2 [hp 0x1000] 
	// Stack : Knight3 [hp 0x1000] 


	// [ 깊은 복사 Deep Copy]
	// 멤버 데이터가 참조(주소) 값이라면, 데이터를 새로 만들어준다 (원본 객체가 참조하는 대상까지 새로 만들어서 복사)
	// 포인터는 주소값 바구니 -> 새로운 객체를 생성 -> 상이한 객체를 가리키는 상태가 됨.
	// Stack : Knight1 [hp 0x1000]	-> Heap 0x1000 Pet[   ]
	// Stack : Knight2 [hp 0x2000]	-> Heap 0x2000 Pet[	  ]
	// Stack : Knight3 [hp 0x3000]  -> Heap 0x3000 Pet[	  ]
	// 컴파일러가 암시적으로 만들어 주던 [복사 생성자] + [복사 대입 연산자] 를 그대로 사용해서는 deep copy 불가
	// 개발자가 만들어 줘야함.!!
	/*
	{_hp=0x000000c8 _pet=0x00be2b20 {...} }
	{_hp=0x000000c8 _pet=0x00be2910 {...} }
	{_hp=0x000000c8 _pet=0x00be27c0 {...} }
	*/

	// 멤버변수에 포인터가 있다고 해서, 무조건 깊은복사를 해야하는건 아님!!! 물론 일반적으로는 깊은복사를 함.

	// 실험 )
	// - 암시적 복사 생성자 Steps
	// 1) 부모 클래스의 복사 생성자 호출
	// 2) 멤버 클래스의 복사 생성자 호출
	// 3) 멤버가 기본 타입일 경우 메모리 복사 (얕은 복사 Shallow Copy)
	// 
	// console OUTPUT
	// ------------- 복사 생성자 --------------
	//	Player(const Player & player)
	//	Pet(const Pet&)
	// 
	// 
	// 
	// - 명시적 복사 생성자 Steps
	// 1) 부모 클래스의 기본 생성자 호출
	// 2) 멤버 클래스의 기본 생성자 호출
	/*		CONSOLE OUTPUT
			------------- 복사 생성자 --------------
			Player()
			Pet()
			Knight(const Knight&)

	우리가 다른걸 호출하라고 하지 않는 이상, 부모&멤버 둘다 [기본생성자]를 호출한다. --> 잘못하면 부분적으로만 복사가 일어나게 된다.
	*/


	// - 암시적 복사 대입 연산자 Steps
	// 1) 부모 클래스의 복사 대입 연산자 호출
	// 2) 멤버 클래스의 복사 대입 연산자 호출
	// 3) 멤버가 기본 타입일 경우 메모리 복사 (얕은 복사 Shallow Copy)
	// 
	//  
	// - 명시적 복사 대입 연산자 Steps
	// 1) 알아서 해주는거 없음 -> 우리가 모든걸 알아서 처리해야함.

	// 왜 이렇게 혼란스러울까?
	// 객체를 '복사' 한다는 것은 두 객체의 값들을 일치시키려는 것
	// 따라서 기본적으로 얕은 복사 (Shallow Copy) 방식으로 동작

	// 명시적 복사 -> [모든 책임]을 프로그래머한테 위임하겠다는 의미



	return 0;
}