#include<iostream>
using namespace std;

// 오늘의 주제 : 동적 할당

// 이번 주제 매우매우 중요!!

// 메모리 구조 복습
// - 실행할 코드가 저장되는 영역 -> 코드 영역
// - 전역(global)/정적(static) 변수 -> 데이터 영역
// - 지역 변수 / 매개 변수 -> 스택 영역
// - 동적 할당 -> 힙 영역
// 

// 지금까지 데이터 영역/ 스택 영역 이용해서 
// 이런 저런 프로그램을 잘 만들어 왔다!
// 굳이 새로운 영역이 필요?

// 실제 상황)
// -MMORPG 동접 1명 ~ 5만명, 몬스터 1~500만
// - 몬스터 생성 이벤트 -> 5분동안 몬스터가 10배 많이 나옴

// -스택영역
// 함수가 끝나면 같이 정리되는 불안정한 메모리
// 잠시 함수에 매개변수 넘긴다거나, 하는 용도로는 ok
// 
// -메모리 영역
// 프로그램이 실행되는 도중에는 '무조건' 사용되는

// 희망사항)
// - 필요한때만 사용하고, 필요없으면 반납할 수 있는!
// - 그러면서도 (스택과는 다르게) 우리가 생성/소멸 시점을 관리할 수 있는!
// - 그런 아름다운 메모리 없나? -> HEAP
// 동적할당과 연관된 함수 / 연산자: malloc, free, new , delete, new[], delete[]

class Monster
{
public:
	int _hp;
	int _x;
	int _y;
};

// 전역으로 만들게 되면 안좋은점 
// -> 무조건 최대 갯수인 500만마리를 항상 생성함.
//Monster monster[500 * 10000];

int main()
{	// [컴퓨터 구조]
	// 유저 영역 [메모장][LOL][곰플레이어]
	//-----------------------------------
	// 커널 영역(Window 등의 핵심 코드)

	// 유저 영역) 운영체제에서 제공하는 API 호출
	// 커널 영역) 메모리 할당해서 건내줌
	// 유저 영역) ㄳㄳ 잘쓸게요~

	// [													] 
	// C++에서는 기본적으로 CRT(C런타임 라이브러리)의 [힙 관리자]를 통해 힙 영역 사용
	// 단, 정말 원한다면 우리가 직접 API를 통해 힙을 생성하고 관리할 수도 있음 (MMORPG 서버 메모리 풀링)-> 메모리를 최대한 재활용


	/*
	// Definitions of common types
#ifdef _WIN64
    typedef unsigned __int64 size_t; // unsigned__int64(64비트)를 size_t로 사용하겠다!! 라는 의미
    typedef __int64          ptrdiff_t;
    typedef __int64          intptr_t;
#else
    typedef unsigned int     size_t;// [unsigned int(32비트)를 size_t로 사용하겠다] 라는 의미
    typedef int              ptrdiff_t;
    typedef int              intptr_t;
#endif
	
	*/

	size_t
	malloc()


	return 0;
}