#include<iostream>
using namespace std;

// 한번 정해지만 절대 바뀌지 않을 값들
// constant의 약자인 const를 붙임(변수를 상수화 한다고 함)
// const를 붙였으면 초기값을 반드시 지정해야 함.


//그러면 const도 바뀌지 않는 읽기 전용 데이터이니까
// .rodata 일까?
// 이건 딱히 정해진게 없다.
// 사실 C++ 표준에서 꼭 그렇게 하라는 말이 없음
// 그냥 컴파일러 (VS : 비주얼 스튜디오) 마음이다.
unsigned char flag;// 부호를 없애야 '>>' 를 하더라도 부호비트가 딸려오지 않음.
const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVINCIBLE = 3;// 반드시 초기값을 넣어줘야함.!!!!!

//전역 변수

// [데이터 영역]
// .data(초기값 있는 경우)
int a = 2;

// .bss( 초기값 없는 경우)
int b;

// .rodata(읽기 전용 데이터)
const char* msg = "Hello World";




int main() {

	// [스택 영역]
	int c = 3;




#pragma region 비트연산
	// 언제 필요한가?
	// 비트 단위의 조작이 필요할 때
	// - 게임서버에서 아이디를 발급할때
	// - 대표적으로 BitFlag
	// 

	// ~ : bitwise not
	// 단일 숫자의 모든 비트를 대상으로, 0은 1 , 1은 0으로 뒤바꿈

	// & : bitwise and
	// 두 숫자의 모든 비트 쌍을 대상으로, and를 한다.

	// | : bitwise or
	// 두 숫자의 모든 비트 쌍을 대상으로, or를 한다

	// ^ : bitwise xor
	// 두 숫자의 모든 비트 쌍을 대상으로, xor를 한다.
	// 숫자를 2번 xor를 하면 원복이 된다.

	// << : 비트 좌측 이동
	// 비트열을 N만큼 왼쪽으로 이동
	// 왼쪽의 넘치는 N개의 비트는 버림. 새로 생성되는 N개의 비트는 0.
	// *2를 할 때 자주 보이는 패턴

	// >> : 비트 우측 이동
	// 비트열을 N만큼 오른쪽으로 이동
	// 오른쪽의 넘치는 N개의 비트는 버림.
	// 왼쪽 생성되는 N개의 비트는
	// - 부호 비트가 존재할 경우 부호 비트를 따라감(부호있는 정수라면 이 부분을 유의)
	// 음수비트였으면 0이 아니라 1이 최상위 비트로 계속 설정됨.
	// - 아니면 0 으로 채워짐.[unsigned type 이라면 이 부분 규칙을 따름]

	// 실습
	// 0b0000 [무적][변이][스턴][공중부양]

	// 무적 상태로 만든다.
	flag = (1 << INVINCIBLE);// 1이라는 숫자를 왼쪽으로 3칸 옮긴다.  1은 비트이다. 즉 8이라는 의미

	// 변이 상태를 추가한다 (무적 + 변이)
	flag |= (1 << POLYMORPH);
	/*
		1000
OR		0100
RESULT	1100
	*/

	// 무적인지 확인하고 싶다? (다른 상태는 관심없음)
	// bitmask
	bool invincible = ((flag & (1 << INVINCIBLE)) != 0);

	// 무적이거나 스턴 상태인지 확인하고 싶다면?
	bool mask = (1 << 3) | (1 << 1);
	bool stunOrInvincible = ((flag & 0b1010) != 0); // 0b1010 대신 mask를 넣어도됨.




#pragma endregion
	return 0;
}