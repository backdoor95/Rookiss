#include<iostream>


// 오늘의 주제 : 오른값(rvalue) 참조와 std::move ---> c++11의 가장 많은 변화 (모던 c++의 꽃)


using namespace std;

class Pet
{

};

class Knight
{
public:
	
	Knight()
	{
		cout << "Knight()" << endl;
	}

	// 복사 생성자
	Knight(const Knight& knight)
	{
		cout << "const Knight&" << endl;
	}

	// 이동 생성자

	~Knight()
	{
		if (_pet)
			delete _pet;
	}

	// 복사 대입 연산자
	void operator=(const Knight& knight)
	{
		cout << "operator=(const Knight&)" << endl;

		// 깊은 복사
		_hp = knight._hp;
		
		if(knight._pet)
		_pet = new Pet(*knight._pet);
	}

	// 이동 대입 연산자
	void operator=(Knight&& knight) noexcept
	{
		cout << "operator=(const Knight&&)" << endl;

		// 얕은 복사
		_hp = knight._hp;

		// knight는 더이상 사용안할거라는 힌트!
		_pet = knight._pet;

		knight._pet = nullptr;
	}

	void PrintInfo() const// 
	{
		//_hp = 20;// 이거 못함. 오직 read only!
	}

public:
	int _hp = 100;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight)
{
	knight._hp = 200;// 원본에 영향을 못 줌!
}

void TestKnight_LValueRef(Knight& knight)
{
	knight._hp = 300;// 원본에 적용!!!
}

void TestKnight_ConstLValueRef(const Knight& knight)
{
	knight.PrintInfo();// 함수에 const가 붙어야 호출이 가능
}

void TestKnight_RValueRef(Knight&& knight)// 이동 대상!! 오른값 참조 가능해진다. --> 오른값 참조
{
	knight._hp = 500;
}

int main()
{
	// 왼값(lvalue) vs 오른값(rvalue)
	// - lvalue : 단일식을 넘어서 계속 지속되는 개체
	// - rvalue : lvalue가 아닌 나머지 (임시 값, 열거형 , 람다, i++ 등)

	int a = 3;
	a = 4;


	Knight k1;

	TestKnight_Copy(k1);
	TestKnight_LValueRef(k1);
	//TestKnight_LValueRef(Knight());// Knight()[오른값]는 딱 한 번만 임시적으로 만들어졌다가, 함수호출이 끝나면 사라짐.!
	TestKnight_ConstLValueRef(Knight());// lValue 형식이여도 파라매터에 const를 붙이면 오른값을 넘길수 있다.

	TestKnight_RValueRef(Knight());

	TestKnight_RValueRef(static_cast<Knight&&>(k1));
	// 핵심 : 오른값 참조로 넘겼다는 것은 이제 원본 데이터가 유지되지 않아도 된다든 힌트임!

	Knight k2;
	k2._pet = new Pet();
	k2._hp = 1000;

	// 원본은 날려도 된다 <<는 hint를 주는 쪽에 가깝다.
	Knight k3;
	k3 = static_cast<Knight&&>(k2);// k2는 버리는 놈이라고 힌트를 주는것임. 이동 대입 연산자 호출됨. 방법 1
	// 복사하는건 무거울수 있다. 이동하는건 훨씬 더 빨리 동작을 할 확률이 일단은 높음.

	k3 = move(k2);// 오른값 참조로 캐스팅 static_cast<Knight&&>(k2); 이거와 같은 의미
	// std::move의 본래 이름 후보 중 하나가 rvalue_cast ---> 얕은 복사!

	Knight* k;
	unique_ptr<Knight> uptr = make_unique<Knight>();
	//unique_ptr<Knight> uptr2 = uptr;// 오류가 발생하는 이유는 복사자체를 허용하지않아서임.
	unique_ptr<Knight> uptr2 = move(uptr);// 오른값 참조로 캐스팅함.! uptr2가 모든 권한을 위임받음.





	return 0;
}