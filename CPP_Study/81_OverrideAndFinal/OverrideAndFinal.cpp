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
	// final : Player������ ����ϰ� �� �̻� �������̵带 �����ְڴٶ�� �ǹ�
	virtual void Attack() final 
	{
		cout << "Player!" << endl;
	}
};
class Knight : public Player
{
public:
	// ������ (override)
	// ���� �̸��� ���� �ñ״�ó �Լ��� �����Լ��� �۵��Ѵ�. ��ӹ��� Ŭ�������� virtual�� �Ⱥٿ��൵ �ǳ�, �ٿ��ִ°� ����.
	virtual void Attack() override // override�� �θ�Կ��� �������� �Լ��� �������ϰ� �ִٴ� ǥ��!!--> ���� : �Ǽ� ���̰� �������� ����. / ���� ��ġ�̴�!!
	{
		cout << "Knight!!" << endl;
	}

	// �θ���� �����ֽ� �Լ��� ������ �� ���� �ݵ�� override�� �ٿ�����!! 

	
	
	// �����ε� (overloading) : �Լ� �̸��� ����
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