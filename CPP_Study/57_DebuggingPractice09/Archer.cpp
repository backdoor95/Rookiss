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
	// 즐거웠다 내 펫 :(
	if (_pet != nullptr)// 펫을 삭제를 한건데 또 삭제를 하려니까 에러발생
		delete _pet;// double free 문제가 발생함.
}

void Archer::AddHp(int value)
{
	Player::AddHp(value);

	// 죽었으면 펫도 날린다
	if (IsDead())
	{
		delete _pet;
		_pet = nullptr;// nullptr 추가
		// _pet [0x100]  -> 0x100 [			](delete는 이 부분을 날리는거임)
		// _pet[nullptr] 로 해줘야함.
	}
}
