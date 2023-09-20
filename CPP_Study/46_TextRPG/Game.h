#pragma once
#include"Player.h"

// is - a : game이 player 냐?
// 
// has - a : game이 player를 가지고 있냐?
class Game
{
public:

private:

	//Player _player;// 이렇게 포인터 형태가 아닌 멤버클래스로 들고 있는건 안좋은 설계임.
	// 예를 들어서 멤버가 Knight를 받게 된다면 Knight의 메모리 크기가 player보다 크기 때문에
	// 부분적으로 짤리게 된다.!!

	// [ 4~8 ] 바이트 바구니(주소) ---> [					]
	Player* _player;


};

