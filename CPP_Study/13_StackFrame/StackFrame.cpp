#include<iostream>
using namespace std;

// 디버깅
// 
// F5 - 한방에 실행, 다음 break point 까지 이동.

// F10 - 프로시저(함수)단위 실행

// F11 - 한 줄씩 코드 실행

// 스택은 높은 주소에서 시작해서 낮은 주소로 이동한다.
// 함수 = 1.매개변수, 2.반환 주소값 , 3.지역변수 로 구성

// 어셈블리를 까보기
// 디버그 실행시 x86를 실행할 때와 x64를 실행할 때, 어셈블리가 조금씩 다르다는걸 알게됨. 
//
// call 하면 return 주소가 스택에 넣어진다.





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

	int a = 3;
	int b = 5;
	int result = MultiplyBy(b, a);

	PrintNumber(result);
	return 0;
}