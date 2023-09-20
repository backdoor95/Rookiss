#include<iostream>
using namespace std;

// ������ ���� : ĳ���� (Ÿ�� ��ȯ) -- ���� �ܰ�

class Player
{
public:
	virtual ~Player(){ }
};

class Knight :public Player
{
public:
};

class Archer : public Player
{
public:
};

class Dog
{

};

// 1) static_cast - 80%~90%
// 2) dynamic_cast - static_cast �������� ���� ����. - 10%
// 3) const_cast - 1%
// 4) reinterpret_cast- 1%

void PrintName(char* str)
{
	cout << str << endl;
}

int main()
{
	// static_cast : Ÿ�� ��Ģ�� ���纼 �� ������� ĳ���ø� ������ش�.
	// 1) int <-> float
	// 2) Player* -> Knight* (�ٿ�ĳ����)[��Ӱ���] << ��, ������ ���� ����!!

	int hp = 100;
	int maxHp = 200;
	//float ratio = (float)hp / maxHp;// ����/���� -> ����, �����ϳ��� float���� ��ȯ�ؾ���. --> c style ��.
	float ratio = static_cast<float>(hp) / maxHp;// ����/���� -> ����, �����ϳ��� float���� ��ȯ�ؾ���. --> c++ style ��.

	// �θ�->�ڽ� �ڽ�->�θ�
	Player* p = new Knight();
	//Knight* k1 = (Knight*)p;
	Knight* k1 = static_cast<Knight*>(p);


	// dynamic_cast : ��� ���迡���� ���� ����ȯ 
	// RTTI (RunTime Type Information)
	// �������� Ȱ���ϴ� ��� -> �������� ���·� �����ϴ� ���
	// dynamic_cast�� ����Ϸ��� virtual �Լ��� 1�� �̻� �����ؾ���.
	// - virtual �Լ��� �ϳ��� �����, ��ü�� �޸𸮿� ���� �Լ� ���̺� (vftable) �ּҰ� ���Եȴ�.
	// - ���� �߸��� Ÿ������ ĳ������ ������, nullptr ��ȯ ************************
	// �̸� �̿��ؼ� �´� Ÿ������ ĳ������ �ߴ��� Ȯ���� �����ϴ�.
	Knight* k2 = dynamic_cast<Knight*>(p);// dynamic_cast�� Knight���� �ƴ��� Ȯ���� �ѹ� �� ���ش�.!! �ٵ� static_cast ���ٴ� �� ����.

	
	// const_cast : const�� ���̰ų� ���ų�~ --> ���������� ���� ����� ���� ��������.

	PrintName(const_cast<char*>("Rookiss"));

	// reinterpret_cast
	// ���� �����ϰ� ������ ������ ĳ����
	// 're-interpret': �ٽ� - �����ϴ�/�����ϴ�
	// - �����Ͷ� ���� ������� �ٸ� Ÿ�� ��ȯ ��
	__int64 address = reinterpret_cast<__int64>(k2);

	Dog* dog1 = reinterpret_cast<Dog*>(k2);

	void* p2 = malloc(1000);
	// void* : �ʰ� ��� ���� �𸣰����ϱ� �˾Ƽ� ��ȯ�ؼ� ����϶�� �ǹ�. ������ �ּҸ� Ÿ�� ���µ� �ƹ��͵� ���ٴ� ���� �ƴ�.!!
	Dog* dog2 = reinterpret_cast<Dog*>(p);
	//Dog* dog2 = (Dog*)(p);
	// [ " (Dog*) "]�� �̿��ؼ� ĳ������ �� �� ������ �̰� c style �����̰� ���� 4���� ĳ������ ���� Ŀ���� ������ ������.
	// Ȱ�� ������ ������ �Ǽ��� ������ ����!!!



	return 0;
}