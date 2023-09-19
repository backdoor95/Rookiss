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
};

class RabbitPet : public Pet
{

};

class TuttlePet : public Pet
{

};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet)); // 깊은 복사 - 1. 새로운 객체를 생성 2. 새로운 객체에 내용물 복사 --> 서로 다른 주소값을 가짐.
	}

	Knight& operator=(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet));// 깊은 복사
		return *this;
	}

	~Knight()
	{
		delete _pet; // 이렇게 하면 이미 delete된 놈을 또 다시 delete 해주는 일이 발생
	}

public:
	int _hp = 100;
	//Pet _pet; // 어떤 클래스에서 다른 클래스를 들고 있을때는 자체를 들고있지 않고 포인터를 들고 있다.!!!
	Pet* _pet;
};

int main()
{
	Pet* pet = new Pet();

	Knight knight; // 기본 생성자
	knight._hp = 200;
	knight._pet = pet;

	Knight knight2 = knight; // 복사 생성자
	// Knight knight3(knight);

	Knight knight3;// 기본 생성자
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



	return 0;
}