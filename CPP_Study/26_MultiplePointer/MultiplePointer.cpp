#include<iostream>
using namespace std;

// 오늘의 주제 : 다중 포인터

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}

void SetMessage(const char** a)
{
	*a = "Bye";
}

void SetMessage2(const char*& a)// *에다가 &(참조)도 붙일수 있다.
{
	a = "Wow";
}

int main()
{
	int a = 0;
	SetNumber(&a);
	cout << a << endl;


	// .rdata Hello주소[H][e][l][l][o][\0]
	// .rdate Bye주소[B][y][e][\0]
	// msg[ Hello주소 ] << 8바이트
	const char* msg = "Hello";

											// [매개변수(a(Hello주소))]에서 아래 주소로 바뀜 
	//[매개변수][RET][지역변수(msg(Hello주소))] [매개변수(a(Bye주소))][RET][지역변수]
	SetMessage(msg);
	cout << msg << endl; // 바뀌지 않는 이유: 위에 설명대로, 처음 a에는 Hello 주소가 저장되어있다.
	// 근데 Bye 주소가 저장되고, 함수스택이 사라지면서 a 또한 같이 사라짐.

	// 주소2[ ] << 1바이트
	// 주소1[ 주소 2]<< 8바이트
	// pp[ 주소1 ] << 8바이트
	const char** pp = &msg;
	// .rdata Hello주소[H][e][l][l][o][\0]
	// msg[ Hello주소 ]<< 8바이트
	// pp[ &msg ] << 8바이트

	//[매개변수][RET][지역변수(msg(Hello주소))] [매개변수(a(&msg msg의주소))][RET][지역변수]
	SetMessage(&msg);

	//*pp = "Bye";
	cout << msg << endl;


	// 다중 포인터 : 혼동스럽다?
	// 그냥 양파까기라고 생각하면 된다.
	const char** pp2;//오른쪽에서 왼쪽으로 분석하면 된다.
	// 강사님 tip = *을 하나씩 까면서 타고 간다고 생각하면 이해하기 편하다.


	// 참조를 이용한 방식
	// 참조는 내부적으로 포인터와 완전 같다.
	//[매개변수][RET][지역변수(msg(Hello주소))] [매개변수(a(&msg msg의주소))][RET][지역변수]
	SetMessage2(msg);// 
	cout << msg << endl;

	return 0;
}