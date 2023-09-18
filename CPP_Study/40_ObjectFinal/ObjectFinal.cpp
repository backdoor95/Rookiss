#include<iostream>
using namespace std;

// 오늘의 주제 : 객체지향 마무리
// C++에서는 struct나 class나 종이 한 장 차이다.

// 1) struct vs class 
// struct는 기본 접근 지정자가 public이고, class는 private이다.
// 왜 이렇게 했을까? c++은 c언어에서 파생되어 발전했기 때문에, 호환성을 지키기 위함.
// -> struct는 그냥 구조체 (데이터 묶음)을 표현하는 용도
// -> class는 객체 지향 프로그래밍의 특징을 나타내는 용도

struct TestStruct
{
	int _a;
	int _b;
};

class TestClass
{
	int _a;
	int _b;
};

// 2) static 변수, static 함수 (static = 정적 = 고정된)

class Marine
{
public:
	// 특정 마린 객체에 종속적
	int _hp;

	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	static void SetAttack() // 여기서 static 멤버 변수만 고칠수 있다. 다른건 못 고침.
	{
		s_attack = 100;
	}

	// 특정 마린 객체와 무관
	// 마린이라는 '클래스' 자체와 연관
	static int s_attack;// 설계도 상으로만 존재 , 특정 객체에 묶여있는게 아니라 클래스에 묶여있게 된다.
	// 메모리에 딱 하나만 만들어져서 공용으로 사용하게 됨.
};

// static 변수는 어떤 메모리?
// 초기화 하면 .data
// 초기화 안 하면 .bss
int Marine::s_attack =0;

class Player
{
public:
	int _id;
};

int GenerateId()
{

	// 생명주기 : 프로그램 시작/종료(메모리에 항상 올라가 있음)
	// 가시범위 : static을 붙인 지역 객체를 만들어 주면 해당 함수 내에서만 사용이 가능.! -> [함수 내부]

	// 정적 지역 개체 -> 스택이 아니라 데이터 영역에 생성됨.
	static int s_id = 1;
	// 만약에 int s_id = 1;로 코드를 작성시 매번 1를 반환
	// 근데  static을 붙이는 순간, 초기화는 함수가 호출될때 딱 1번만 실행이 됨.
	// 그 다음 호출에서는 초기화를 안함.

	return s_id++;
}

int main()
{
	Marine m1;
	m1._hp = 40;
	//m1.s_attack = 6;
	m1.TakeDamage(10);
	Marine::s_attack = 6;

	Marine m2;
	m2._hp = 40;
	//m2.s_attack = 6;

	// 마린 공격력 업그레이드 완료! (Academy에서 업그레이드 끝)
	//m1.s_attack = 7;
	//m2.s_attack = 7;
	Marine::s_attack = 7;
	Marine::SetAttack();

	// id 는 스택 메모리에 만들어 지지 않는다. -> .data 영역에 만들어짐.
	static int id = 10;
	int a = id;

	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;
	cout << GenerateId() << endl;


	return 0;
}