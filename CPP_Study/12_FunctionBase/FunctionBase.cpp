#include<iostream>
using namespace std;

// 오늘의 주제 : 함수 (어셈블리에서는 프로시저, c#: 메소드, 루틴)

/*

input으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다.

반환타입 함수이름([인자타입 매개변수])
{
	함수 내용

	return ~~~~;


}


*/

// Hello World를 콘솔에 출력하는 함수를 만들어보자!
// input 없음, output :없음
// 타입 : int, float, double, char ,~~~ , void

void PrintHelloWorld()// 일반적으로 대문자로 시작, 매개변수에 void 하나만 쓴다면 생략해도됨.
{
	cout << "Hello World" << endl;
	return;// void 반환 타입일때 생략해도되고, 이렇게 리턴을 해도됨. // 함수를 빠져나감.!
	cout << "Test" << endl;// 이 코드는 실행이 안됨.
}

//정수를 입력(함수) 받아서, 콘솔에 출력하는 함수를 만들어보자.
// input : int // output : 없음
void PrintNumber(int number)
{
	cout << "넘겨주신 숫자는 " << number << " 입니다." << endl;
}

// 2를 곱하고 결과를 뱉는 함수를 만들어보자
int MultiplyBy2(int a)
{
	int b = a * 2;
	return b;
}

// 두 숫자를 곱해서 결과물을 뱉는 함수를 만들어보자
//input : int, int /output : int

int MultiplyBy(int a, int b)
{
	int c = a * b;
	return c;
}

int main()
{

	PrintHelloWorld();

	PrintNumber(2);

	//int result = MultiplyBy2(3);

	int a = 3;
	int b = 5;
	int result = MultiplyBy(b, a);

	return 0;
}