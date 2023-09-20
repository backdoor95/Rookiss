#pragma once
//#include"Player.h"// 우리가 include를 생각없이 추가하게 되면 [순환구조문제]가 발생할 수 있다.
// 순환 구조 문제가 발생하면 빌드가 실패한다.

// 전방선언 - Player 클래스는 나중에 등장 할것임을 알려줌. include 대신에 전방선언을 하면 빨간줄이 안뜬다.
class Player;

// is - a : game이 player 냐?  (x)
// 
// has - a : game이 player를 가지고 있냐?(o)-> 포함관계
class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:

	//Player _player;// 이렇게 포인터 형태가 아닌 멤버클래스로 들고 있는건 안좋은 설계임.
	// 예를 들어서 멤버가 Knight를 받게 된다면 Knight의 메모리 크기가 player보다 크기 때문에
	// 부분적으로 짤리게 된다.!!

	// [ 4~8 ] 바이트 바구니(주소) ---> [					]
	Player* _player;// 포인터로 클래스를 들고있는게 좋다.


};

