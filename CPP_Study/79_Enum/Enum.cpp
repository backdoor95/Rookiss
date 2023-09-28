#include<iostream>
#include<algorithm>
using namespace std;

// 오늘의 주제 : enum class


// 기본 enum은 unscoped enum (범위없는)
enum PlayerType : char // 이렇게 하면 PlayerType 사이즈가 1바이트로 출력된다. enum의 기본형태는 int이다.
{
	None,
	PT_Knight,
	PT_Archer,
	PT_Mage
};

enum MonsterType : char
{
	//None// 이렇게 이름이 겹치면 오류가 발생한다. 그래서 이름 앞에 enum의 약자를 붙여줌
};

enum class ObjectType
{
	Player,
	Monster,
	Projectile
};

enum class ObjectType2
{
	Player, // 이름을 자체를 재활용 가능!--
	Monster,
	Projectile
};

int main()
{
	// enum class (scoped enum)
	// 1) 이름공간 관리 (scoped) --.> 확실한 장점
	// 2) 암묵적인 변환 금지 --> 장점이 될수도 있고, 아닐수도 있다.


	double value = PT_Knight;// 그냥 enum

	double value = static_cast<double>(ObjectType::Player);// 암묵적인 변환이 금지되어서 cast를 따로 해줘야함.

	int choice;
	cin >> choice;

	if (choice == static_cast<int>(ObjectType::Monster))
	{

	}

	unsigned int bitFlag;
	bitFlag = (1 << static_cast<int>(ObjectType::Player));


	cout << sizeof(PlayerType) << endl; // 4바이트

	return 0;

}