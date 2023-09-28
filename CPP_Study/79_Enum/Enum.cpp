#include<iostream>
#include<algorithm>
using namespace std;

// ������ ���� : enum class


// �⺻ enum�� unscoped enum (��������)
enum PlayerType : char // �̷��� �ϸ� PlayerType ����� 1����Ʈ�� ��µȴ�. enum�� �⺻���´� int�̴�.
{
	None,
	PT_Knight,
	PT_Archer,
	PT_Mage
};

enum MonsterType : char
{
	//None// �̷��� �̸��� ��ġ�� ������ �߻��Ѵ�. �׷��� �̸� �տ� enum�� ���ڸ� �ٿ���
};

enum class ObjectType
{
	Player,
	Monster,
	Projectile
};

enum class ObjectType2
{
	Player, // �̸��� ��ü�� ��Ȱ�� ����!--
	Monster,
	Projectile
};

int main()
{
	// enum class (scoped enum)
	// 1) �̸����� ���� (scoped) --.> Ȯ���� ����
	// 2) �Ϲ����� ��ȯ ���� --> ������ �ɼ��� �ְ�, �ƴҼ��� �ִ�.


	double value = PT_Knight;// �׳� enum

	double value = static_cast<double>(ObjectType::Player);// �Ϲ����� ��ȯ�� �����Ǿ cast�� ���� �������.

	int choice;
	cin >> choice;

	if (choice == static_cast<int>(ObjectType::Monster))
	{

	}

	unsigned int bitFlag;
	bitFlag = (1 << static_cast<int>(ObjectType::Player));


	cout << sizeof(PlayerType) << endl; // 4����Ʈ

	return 0;

}