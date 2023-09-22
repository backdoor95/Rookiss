#include<iostream>
using namespace std;


class Knight
{
public:
	// 멤버 함수
	int GetHp(int a, int b)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}
public:
	int _hp = 100;
};



// 오늘의 주제 : 함수 포인터

// typedef의 진실
// typedef 왼쪽 오른값 -> 오른쪽 (커스텀 타입 정의)

typedef int NUMBER; 

// 정확히는 왼쪽/오른쪽 기준이 아니라,
// [선언 문법]에서 typedef을 앞에다 붙이는 쪽

typedef int* POINTER;

typedef int FUNC(int, int); // 이 버전은 잊어도 된다고 함.


// 일반 함수 포인터
typedef int(*PFUNC)(int, int); // 이건 함수의 포인터 ---> ()로 묶어주어야 함수포인터로 인식함. 
// int* PFUNC(int, int) :// 함수인데 반환하는게 int* 이다.

// 멤버 함수 포인터
typedef int(Knight::*PMEMFUNC)(int, int);


int Test(int a, int b)
{
	cout << "Test" << endl;
	return a + b;
}

int t(int a, int b)
{
	cout << "t" << endl;
	return a + b;
}



int main()
{
	// 함수 포인터
	// 1) 포인터		*
	// 2) 변수의 이름	fn
	// 3) 타입			함수(인자로 int 2를 받고, int 1개를 반환)

	int (*fn)(int, int);
	//fn = Test; // & 생략 가능 (C언어 호환성 때문)  
	fn = &Test; // 위와 동일한 결과를 얻는다. 이렇게 '&'를 붙이는걸 추천 -> 주소 임을 나타내주기 때문
	fn(1, 2);// 방법 1.
	(*fn)(1, 2); // 방법 2.


	//int (fn2)(int, int);
	//fn2 = Test; // 에러 발생


	typedef int(FUNC_TYPE)(int, int);
	FUNC_TYPE* fn3;
	fn3 = Test;

	FUNC_TYPE fn4;
	//fn4 = Test; // 이건 안됨 [FUNC_TYPE* fn4;] 이렇게 변경해야 함.


	FUNC t; // 함수는 스택에 올라가는게 아니라... 아래 장문의 주석 설명 참고!

	t(1, 2);

	PFUNC pfn;

	pfn = Test;
	pfn(1, 2);


	/*
함수를 호출할 때 프로그램이 어떻게 동작하는지 이해하기 위해서는 프로그램의 메모리 관리와 실행 흐름을 이해해야 합니다.

코드 영역 (Code Segment 또는 Text Segment):

코드 영역은 프로그램의 실제 명령어가 저장되는 영역입니다.
실행 중인 프로그램의 명령어들이 이 영역에 저장되며, 이 영역은 읽기 전용으로 설정됩니다.
함수의 실제 명령어들도 코드 영역에 저장됩니다.
스택 영역 (Stack Segment 또는 Call Stack):

스택 영역은 함수 호출 및 지역 변수와 관련된 정보를 저장하는 데 사용됩니다.
함수가 호출될 때 스택 프레임이 생성되고, 이 프레임에는 함수의 인수, 지역 변수, 반환 주소 등이 저장됩니다.
함수가 반환될 때 스택 프레임이 제거됩니다.
함수 호출 시, 일반적으로 다음과 같은 과정이 일어납니다:

호출하는 함수에서 호출되는 함수로 제어가 전달됩니다.
호출되는 함수의 스택 프레임이 스택 영역에 생성됩니다. 이 스택 프레임에는 호출된 함수의 인수, 지역 변수 및 반환 주소가 저장됩니다.
호출된 함수의 코드 영역으로 제어가 이동하고, 함수의 명령어를 실행합니다.
함수 실행이 완료되면, 스택 프레임이 스택에서 제거되고, 호출한 함수로 다시 제어가 전달됩니다.
따라서 함수 호출 시, 제어 흐름은 코드 영역으로 들어가서 함수 명령어를 실행한 후, 스택 영역으로 스택 프레임을 만들고 제어를 전달합니다. 함수 실행이 완료되면 스택 프레임이 스택에서 제거되고, 호출한 함수로 돌아갑니다.
	*/


	// 위 문법으로 [전역 함수 / 정적 함수]만 담을 수 있다. (호출 규약이 동일한 애들)

	//pfn = &Knight::GetHp; // 에러가 뜸.
	// 멤버함수이기 때문에 객체를 만들어서 호출해야함.
	Knight k1;
	k1.GetHp(1, 2);

	PMEMFUNC mfn;

	mfn = &Knight::GetHp;// & 를 붙여야함.!!!!!!!

	(k1.*mfn)(1, 1);// 너무 괴랄하다... 멤버함수의 포인터를 사용하기 위해서는 *를 붙여줘야함.
	// 멤버 변수와 구별을 해야하기 때문

	Knight* k2 = new Knight();
	((*k2).*mfn)(1, 1);// 방법 1
	(k2->*mfn)(1, 1);// 방법 2

	


	delete k2;




	return 0;
}