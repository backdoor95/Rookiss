#include "Archer.h"
#include "Pet.h"

Archer::Archer(Pet* pet) : _pet(pet)
{
	
}

Archer::Archer(int hp) : Player(hp)
{
}

Archer::~Archer()
{
	// ��ſ��� �� �� :(
	if (_pet != nullptr)// ���� ������ �Ѱǵ� �� ������ �Ϸ��ϱ� �����߻�
		delete _pet;// double free ������ �߻���.
}

void Archer::AddHp(int value)
{
	Player::AddHp(value);

	// �׾����� �굵 ������
	if (IsDead())
	{
		delete _pet;
		_pet = nullptr;// nullptr �߰�
		// _pet [0x100]  -> 0x100 [			](delete�� �� �κ��� �����°���)
		// _pet[nullptr] �� �������.
	}
}
