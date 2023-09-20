#pragma once


//플레이어와 몬스터의 구체적인 설계도는 관심이 없다.
//나중에 존재할것이다 라는 안심을 시켜주면 된다.

class Player;
class Monster;

class Field
{
public:
	Field();
	~Field();

	void Update(Player* player);
	void CreateMonster();

	void StartBattle(Player* player);
private:
	Monster* _monster;

};

