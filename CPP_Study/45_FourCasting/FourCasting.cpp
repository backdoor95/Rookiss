#include<iostream>
using namespace std;

// 오늘의 주제 : 캐스팅 (타입 변환) -- 면접 단골

class Player
{
public:
	virtual ~Player(){ }
};

class Knight :public Player
{
public:
};

class Archer : public Player
{
public:
};

class Dog
{

};

// 1) static_cast - 80%~90%
// 2) dynamic_cast - static_cast 다음으로 많이 쓰임. - 10%
// 3) const_cast - 1%
// 4) reinterpret_cast- 1%

void PrintName(char* str)
{
	cout << str << endl;
}

int main()
{
	// static_cast : 타입 원칙에 비춰볼 때 상식적인 캐스팅만 허용해준다.
	// 1) int <-> float
	// 2) Player* -> Knight* (다운캐스팅)[상속관계] << 단, 안정성 보장 못함!!

	int hp = 100;
	int maxHp = 200;
	//float ratio = (float)hp / maxHp;// 정수/정수 -> 정수, 둘중하나를 float으로 변환해야함. --> c style 임.
	float ratio = static_cast<float>(hp) / maxHp;// 정수/정수 -> 정수, 둘중하나를 float으로 변환해야함. --> c++ style 임.

	// 부모->자식 자식->부모
	Player* p = new Knight();
	//Knight* k1 = (Knight*)p;
	Knight* k1 = static_cast<Knight*>(p);


	// dynamic_cast : 상속 관계에서의 안전 형변환 
	// RTTI (RunTime Type Information)
	// 다형성을 활용하는 방식 -> 여러가지 형태로 동작하는 방식
	// dynamic_cast를 사용하려면 virtual 함수가 1개 이상 존재해야함.
	// - virtual 함수를 하나라도 만들면, 객체의 메모리에 가상 함수 테이블 (vftable) 주소가 기입된다.
	// - 만약 잘못된 타입으로 캐스팅을 했으면, nullptr 반환 ************************
	// 이를 이용해서 맞는 타입으로 캐스팅을 했는지 확인을 유용하다.
	Knight* k2 = dynamic_cast<Knight*>(p);// dynamic_cast가 Knight인지 아닌지 확인을 한번 더 해준다.!! 근데 static_cast 보다는 좀 느림.

	
	// const_cast : const를 붙이거나 떼거나~ --> 실전에서는 거의 사용할 일이 없을것임.

	PrintName(const_cast<char*>("Rookiss"));

	// reinterpret_cast
	// 가장 위험하고 강력한 형태의 캐스팅
	// 're-interpret': 다시 - 간주하다/생각하다
	// - 포인터랑 전혀 관계없는 다른 타입 변환 등
	__int64 address = reinterpret_cast<__int64>(k2);

	Dog* dog1 = reinterpret_cast<Dog*>(k2);

	void* p2 = malloc(1000);
	// void* : 너가 어떤걸 쓸지 모르겠으니까 알아서 변환해서 사용하라는 의미. 실제로 주소를 타고 갔는데 아무것도 없다는 뜻이 아님.!!
	Dog* dog2 = reinterpret_cast<Dog*>(p);
	//Dog* dog2 = (Dog*)(p);
	// [ " (Dog*) "]를 이용해서 캐스팅을 할 수 있지만 이건 c style 문법이고 위에 4가지 캐스팅을 전부 커버할 정도로 강력함.
	// 활용 범위도 넓지만 실수의 여지도 많다!!!



	return 0;
}