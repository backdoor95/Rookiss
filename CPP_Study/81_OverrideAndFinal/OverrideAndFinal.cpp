#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Creature
{
public:
	virtual void Attack()
	{
		cout << "Creature!" << endl;
	}
};

class Player : public Creature 
{
public:
	// final : Player까지만 사용하고 더 이상 오버라이드를 막아주겠다라는 의미
	virtual void Attack() final 
	{
		cout << "Player!" << endl;
	}
};
class Knight : public Player
{
public:
	// 재정의 (override)
	// 같은 이름의 같은 시그니처 함수는 가상함수로 작동한다. 상속받은 클래스에서 virtual를 안붙여줘도 되나, 붙여주는게 좋다.
	virtual void Attack() override // override는 부모님에게 물려받은 함수를 재정의하고 있다는 표시!!--> 장점 : 실수 줄이고 가독성을 높임. / 안전 장치이다!!
	{
		cout << "Knight!!" << endl;
	}

	// 부모님이 물려주신 함수를 재정의 할 때는 반드시 override를 붙여주자!! 

	
	
	// 오버로딩 (overloading) : 함수 이름의 재사용
	//void Attack(int a)
	//{

	//}
private:
	int _stamina = 100;
};
int main()
{
	Knight* knight = new Knight();

	knight->Attack();

	Player* player = new Knight();
	
	player->Attack();


	return 0;
}