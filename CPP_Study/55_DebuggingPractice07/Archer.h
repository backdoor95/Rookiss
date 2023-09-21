#pragma once
#include "Player.h"

class Archer : public Player
{
public:
	Archer();
	Archer(int hp);
	~Archer();

public:
	class Pet* _pet;// 앞에 class를 붙여줬으므로 전방선언임.
};

