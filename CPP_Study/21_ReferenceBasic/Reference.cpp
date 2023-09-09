#include<iostream>
using namespace std;

// 오늘의 주제 : 참조

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// [매개변수][RET][지역변수(info)] [매개변수(&info)][RET][지역변수]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// 이렇게 하면 복사가 일어나서 넘겨줌.
void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5; //단축키 :[한번에 고치기] alt를 누르고 드래그 **
}

//근데 복사가 완전히 나쁜건 아니다.

// 1)값 전달 방식
// // [매개변수][RET][지역변수(info)] [매개변수(info)][RET][지역변수]
void PrintInfoByCopy(StatInfo info)
{
	cout << "-------------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "-------------------------" << endl;
}

// 2) 주소 전달 방식
// [매개변수][RET][지역변수(info)] [매개변수(&info)][RET][지역변수]
void PrintInfoByPtr(StatInfo* info)
{
	cout << "-------------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "-------------------------" << endl;
}


// StatInfo 구조체가 1000바이트짜리 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사되는
// - (주소 전달) StatInfo*는 8바이트 // 주소는 무조건 4바이트 또는 8바이트다.
// - (참조 전달) StatInfo&는 8바이트 //c에는 존재 안함, c++에만 있음. 


// 3) 참조 전달 방식 
// 값 전달처럼 편리하게 사용하고!
// 주소 전달처럼 주소값을 이용해 진퉁을 건드린다! 다만 주소값을 전달하는 부분이 숨겨져있다.
// 일석이조의 방식!---- 근데 무조건 장점만 있는건 아니다. 다음시간에 알려줌
// (1)과(2) 방식의 사이에 위치한 방식이라고 이해하면됨.
// 성능적으로 2번과 똑같다.
// Low level 관점에서 포인터와 완전히 똑같이 동작을함. 그러나 사용하는 인터페이스 자체가 포인터랑 다르게 일반적인 복사랑 비슷하게 사용함.

void PrintInfoByRef(StatInfo& info)
{
	cout << "-------------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "-------------------------" << endl;
}

int main()
{

	// 4바이트 정수형 바구니를 사용할꺼야.
	// 앞으로 그 바구니 이름을 number라고 할께.
	// 그러니까 number에서 뭘 꺼내거나, number에 뭘 넣는다고 하면
	// 찰떡같이 알아듣고 해당 주소(data, stack, heap)에 1을 넣어주면 된다!
	int number = 1;

	// * : 주소를 담는 바구니
	// int 그 바구니를 따라가면 int 데이터(바구니)가 있음.
	int* pointer = &number;
	// pointer 바구니에 있는 주소를 타고 이동해서, 그 멀리 있는 바구니에 2를 넣는다.
	*pointer = 2;


	// 로우레벨(어셈블리) 관점에서 실제 작동 방식은 int*와 똑같음
	// 실제로 실행해보면 포인터랑 100% 똑같다.
	int& reference = number;// 이거는 무조건 초기값을 넣어줘야함.

	//C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
	// number 라는 바구니에 reference라는 다른 이름을 지어줄께
	// 앞으로 reference 바군니에다가 뭘 꺼내거나 넣으면,
	// 실제 number 바구니(찐퉁에다가) 그 값을 꺼내거나 넣으면됨.

	reference = 3;// 실제로 number에 3을 넣는것.

	// 그런데 귀찮게 또 다른 이름을 짓는 이유는?
	// 그냥 number = 3 이라고 해도 똑같은데...
	// ********** 참조 전달 때문!***********
	// (.)을 찍어서 사용가능.

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByRef(info);// 주소를 안넘겨줘도. 진퉁을 건드릴수있다. --> 내부적으로 알아서 주소값을 추출해서 사용하게될것이다.




}