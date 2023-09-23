#include<iostream>
using namespace std;

// 오늘의 주제 : 템플릿 기초

//void Print(int a)
//{
//	cout << a << endl;
//}
//void Print(float a)
//{
//	cout << a << endl;
//}
//void Print(double a)
//{
//	cout << a << endl;
//}
//void Print(const char* a)
//{
//	cout << a << endl;
//}

class Knight
{
public:
	// ...

public:
	int _hp = 123;
};

template<typename T> 
void Print(T a)
{
	cout << a << endl;
}

// 템플릿 특수화
// 다른 규칙을 따르고 싶을때
template<>// 조거카드가 없고, 우리가 지정해줘야 하니까 <> 사이를 비워놔야함.
void Print(Knight a)
{
	cout << "Knight!!!!!!!!!!!!!!!!!" << endl;
	cout << a._hp << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}


//template<class T> // typename 대신에 class 도 가능하다. 그러나 강사는 class라고 하면 왠지 그 클래스를 넣어줘야 할 것 같아서 typename을 선호함.
//void Print(T a)
//{
//	cout << a << endl;
//}


int Add(int a, int b)
{
	return a + b;
}

float Add(float a, float b)
{
	return a + b;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// 연산자 오버로딩( 전역함수 버전)
ostream& operator <<(ostream& os, const Knight& k) // out-stream
{
	os << k._hp;
	return os;
}


int main()
{
	// 템플릿 : 함수나 클래를 찍어내는 틀
	// 1) 함수 템플릿
	// 2) 클래스 템플릿

	Print(50);
	Print<int>(50);// 이렇게 명시적으로 타입을 정해줄수 있다.
	Print(50.0f);
	Print<int>(50.0f);
	Print(50.0);
	Print("Template Joker!!");
	// 같은 함수를 재사용하는게 아니라 
	// 진짜로 각각 함수를 만든다.

	/*
		Print(50);
00122B3F  push        32h  
00122B41  call        Print<int> (0121267h)  
00122B46  add         esp,4  
	Print<int>(50);// 이렇게 명시적으로 타입을 정해줄수 있다.
00122B49  push        32h  
00122B4B  call        Print<int> (0121267h)  
00122B50  add         esp,4  
	Print(50.0f);
00122B53  push        ecx  
00122B54  movss       xmm0,dword ptr [__real@42480000 (0129B84h)]  
00122B5C  movss       dword ptr [esp],xmm0  
00122B61  call        Print<float> (0121442h)  
00122B66  add         esp,4  
	Print<int>(50.0f);
00122B69  push        32h  
00122B6B  call        Print<int> (0121267h)  
00122B70  add         esp,4  
	Print(50.0);
00122B73  sub         esp,8  
00122B76  movsd       xmm0,mmword ptr [__real@4049000000000000 (0129B78h)]  
00122B7E  movsd       mmword ptr [esp],xmm0  
00122B83  call        Print<double> (012132Ah)  
00122B88  add         esp,8  
	Print("Template Joker!!");
00122B8B  push        offset string "Template Joker!!" (0129B4Ch)  
00122B90  call        Print<char const *> (012117Ch)  
00122B95  add         esp,4  
	
	
	*/

	// 템플릿 --> 조커 카드

	int result1 = Add(1, 2);
	float result2 = Add<float>(1.11f, 2.22f);

	//Print(int, cont char*); // --> typename을 2개를 만든다.
	Print("Hello", 100);

	// 템플릿 특수화

	Knight k1;
	Print(k1);


	return 0;
}