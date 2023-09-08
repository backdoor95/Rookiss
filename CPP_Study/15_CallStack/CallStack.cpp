#include<iostream>
using namespace std;

//오늘의 주제 : 호출 스택

//함수 선언 - 선언은 순서가 상관없다.
void Func1();
void Func2(int a, int b);//선언부에서 매개변수 이름을 생략해도됨. (int, int)
void Func3(float a);

//선언부는 별도의 파일로 빼게 될것이다.

//구현부 부분도 별도의 파일로 관리하게 될것이다.


//디버그 모드일때, 호출 스택의 어셈블리코드를 까보면 call 다음 주소를 가리키고 있다.
// 오른쪽 아래에 있는 호출스택에 들어간 내용은 스택프레임에서 배운 반환주소값이랑 연관되어있다.
// 나중에 호출스택을 많이보게 될 것이다.

int main()
{
	cout << "main" << endl;
	Func1();
	return 0;
}



void Func1()
{
	cout << "Func1" << endl;
	// push 2 // 오른쪽 매개변수부터 stack에 push 한다.
	// push 1
	// call Func2 // 함수의 위치를 알지 못하면, 빌드 오류가 발생한다. 따라서 함수 선언을 먼저해야함.-> ctrl+shift + b를 하면 빌드 성공!
	Func2(1, 2);
	Func3(10.0f);
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

