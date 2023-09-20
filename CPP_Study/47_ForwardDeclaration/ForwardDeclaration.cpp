#include<iostream>
using namespace std;
#include"Player.h"

// 오늘의 주제 : 전방선언

int main()
{
	//플레이어의 설계가 완성이 되어야 빌드가 통과됨.
	//메모리에 플레이어를 만들어주기 위해서는 플레이어 크기가 몇 바이트인지가 알아야함.
	//
	// 핵심 : Player는 몇 바이트?
	// int 2개 = 2* 4바이트= 8바이트
	// Monster -- ?
	// sizeof(Monster*) = 4or8

	Player p1; // 지역변수 (Stack)

	Player* p2 = new Player();// 동적할당(Heap)

	return 0;
}