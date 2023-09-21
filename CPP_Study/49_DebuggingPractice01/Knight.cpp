#include "Knight.h"
#include <iostream>
using namespace std;

// [사양서] 기본값 Hp=100, Attack=10
Knight::Knight() : _hp(100), _attack(10)
{

}

Knight::Knight(int hp) : _hp(hp), _attack(10) // 내 풀이 : 여기에 _attack를 초기화 해주지 않았기 때문이다.
{// Rookiss : 초기화 이슈!

}

Knight::~Knight()
{

}

void Knight::PrintInfo()
{
	cout << "HP: " << _hp << endl;
	cout << "ATT: " << _attack << endl;
}