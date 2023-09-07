#include<iostream>
using namespace std;

//오늘의 주제 : 호출 스택

//함수 선언 - 선언은 순서가 상관없다.
void Func1();
void Func2(int a, int b);//선언부에서 매개변수 이름을 생략해도됨. (int, int)
void Func3(float a);

int main()
{
	cout << "main" << endl;
	Func1();
	return 0;
}



void Func1()
{
	cout << "Func1" << endl;
	// push 2
	// push 1
	// call Func2 // 함수의 위치를 알지 못하면, 빌드 오류가 발생한다. 따라서 함수 선언을 먼저해야함.-> ctrl+shift + b를 하면 빌드 성공!
	Func2(1, 2);
}

void Func2(int a, int b)
{
	cout << "Func2" << endl;
	Func3(10);
}

void Func3(float a)
{
	cout << "Func3" << endl;
}

