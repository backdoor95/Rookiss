#include<iostream>
using namespace std;

// 오늘의 주제 : 유의 사항

// 1) 변수의 유효범위

// 전역변수
// int G_hp = 10;// 이런 컨벤션을 만들어서 사용한다.
// int hp = 10;

// 스택
// { } 중괄호의 범위가 생존 범위
// 같은 이름 두번 사용할 때 문제


// 2) 연산 우선순위

// 3) 타입 변환

// 4) 사칙 연산 관련


int main() {

	
	int hp = 123;
	cout << hp << endl;// 전역변수와 지역변수 이름이 같은경우 이 부분은 가장 가까운hp가 출력이 된다. 

	// 짝수 여부
	bool isEven = ((hp % 2) == 0);

	// 짝수거나 3으로 나뉘는 값인지
	bool isEvenOrDivBy3 = ((hp % 2) == 0 || (hp % 3) == 0);// ( )를 감싸는것이 가독성에 좋다. 연산에 우선순위에서 실수를 방지함.

	// 바구니 교체 
	short hp2 = hp; //  1) 바구니 사이즈가 줄어들면 => 윗쪽 비트 데이터가 짤린 상태로 저장
	float hp3 = hp; //  2) 실수로 변환할 때 정밀도 차이가 있기 때문에 데이터 손실
	unsigned int hp4 = hp; // 3) 비트 단위로 보면 똑같은데, 분석하는 방법이 달라진다.


	// 곱셈
	// -오버플로우
	// int * int = int 오버플로우 가능성있음

	// 나눗셈
	// - 0 나누기 조심
	// - 실수 관련

	int maxHp = 1000;

	
	float ratio = hp / maxHp;//  int / int = int  0.123 => 소수점 아래 부분 날라감.

	// int/ float  float/int  =		float
	float ratio2 = hp / (float)maxHp;//  실수가 우선순위가 더 높기 때문
	





	return 0;
}