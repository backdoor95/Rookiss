#include<iostream>
using namespace std;

// ������ ���� : ��Ӽ�

// ��ü���� (OPP = Object Oriented Programming)
// - ��Ӽ�
// - ���м�
// - ������

// �Լ��� ����ü�� �����ټ�����.
// 
// ���(Inheritance) ? �θ� -> �ڽĿ��� ������ �����ִ� ��.

// class�� ������ ���赵

// ������(N)/�Ҹ���(1)

// �����ڴ� ź���� ����ؼ� ȣ��Ǵ� �Լ�?
// - Knight �� �����ϸ� -> Player�� ������? Knight�� ������?
// -> �ַθ��� ����! �׳� �Ѵ� ȣ������!!!!!

/*
void Knight::Move(int y, int x)// ���Ǹ� �̷��� �ۿ��� �ص���. ��� ��� Ŭ���� �Ҽ������� �˷��ֱ� ���ؼ� ' :: '�� ����Ѵ�.
�� , ����� �� ���� ' : '�� ����Ѵ�.
*/

// �޸�

// [ [ Player ] ]
// [    Knight   ]

// GameObject
// - Creature : ��� ������
// -- Player, Monster, Npc, Pet
// - Projectile : ����ü
// -- Arrow, Fireball
// - Env : environment

// Item
// - Weapon
// -- Sword, Bow
// - Armor
// -- Helmet, Boots, Armor
// - Consumable
// -- Potion, Scroll
class GameObject
{
public:
	int _objectId;
};

class Player : public GameObject
{
public:
	Player()
	{
		_hp=0;
		_attack=0;
		_defence=0;
		cout << "Player() �⺻ ������ ȣ��" << endl;
	}

	Player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;
		cout << "Player(int hp) ������ ȣ��" << endl;
	}

	~Player()
	{
		cout << "~Player() �Ҹ��� ȣ��" << endl;
	}

	void Move() { cout << "Player Move ȣ�� " << endl; }
	void Attack() { cout << "Player Attack ȣ�� " << endl; }
	void Die() { cout << "Player Die ȣ�� " << endl; }
public:
	int _hp;
	int _attack;
	int _defence;
};

class Knight : public Player // ����� ��ų���� ' : ' �̷��� �����.
{
public:
	Knight()
		/*
		��(����) ó�� ���� 
		- ���⼭ Player() �⺻�����ڸ� ȣ��
		*/
	{
		_stamina = 100;
		cout << "Knight() �⺻ ������ ȣ��" << endl;
	}

	Knight(int stamina) : Player(100)//********�θ��� �⺻�����ڰ� �ƴ϶� �ٸ� �����ڸ� ���� ������!!!!!!*********
		/*
		��(����) ó�� ����
		- ���⼭ Player() �⺻�����ڸ� ȣ��
		*/
	{
		_stamina = stamina;
		cout << "Knight(int stamina) ������ ȣ��" << endl;
	}

	~Knight()
	{
		cout << "~Knight() �Ҹ��� ȣ��" << endl;
	}
	/*
		��(���߿�)ó�� ����
		- ���⼭ ~Player() �Ҹ��ڸ� ȣ��
	*/

	// ������ : �θ���� ������ �ź��ϰ� ���ο� �̸����� ����?
	void Move() { cout << "Knight Move ȣ��" << endl; }

public:
	int _stamina;
};

class Mage : public Player
{
public:

public:
	int _mp;
};

int main()
{
	Knight k;
	k._hp = 100;
	k._attack = 10;
	k._defence = 5;
	k._stamina = 50;

	k.Move();// �ڽ��� �������� �Լ� ȣ��
	k.Player::Move();// �����Ǹ� �������� �θ��� �Լ��� ȣ���ϰ� ������.  --> ���������� ���� �Ⱦ���...

	k.Attack();
	k.Die();

	return 0;
}