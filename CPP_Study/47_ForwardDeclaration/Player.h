#pragma once

// #include "Monster.h"

//이거는 땡깡에 불과함.
class Monster;

// class는 설계도
class Player
{
public:

	void KillMonster();

	void KillMonster2();

	//void KillMonster2()
	//{
	//	_target2->_hp = 0;//이걸 빌드 했을때, 에러발생
	//	// 아직 Monster의 설계도를 모르기 때문.
	//	// 그래서 전방선언 했음에도 빌드했을때 오류발생.
	//	// 결국 #include "Monster.h"를 해줘야 통과가 된다.
	//	// 그래서 cpp 에서 구현하는걸 추천
	//}

public:
	int _hp;
	int _attack;

	//Monster _target;
	Monster* _target2;
	// class Monster* _target2;// 이렇게 해도됨.!


	//Player _target3;// 이건 안됨. 전체적인 메모리 크기를 모르기 때문
	Player* _target3;// 이건 됨. 포인터는 고정 크기이기 때문에 전체 메모리 크기를 알수 있기 때문

};

