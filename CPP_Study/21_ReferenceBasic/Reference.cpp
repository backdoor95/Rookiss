#include<iostream>
using namespace std;

// ������ ���� : ����

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// [�Ű�����][RET][��������(info)] [�Ű�����(&info)][RET][��������]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// �̷��� �ϸ� ���簡 �Ͼ�� �Ѱ���.
void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5; //����Ű :[�ѹ��� ��ġ��] alt�� ������ �巡�� **
}

//�ٵ� ���簡 ������ ���۰� �ƴϴ�.

// 1)�� ���� ���
// // [�Ű�����][RET][��������(info)] [�Ű�����(info)][RET][��������]
void PrintInfoByCopy(StatInfo info)
{
	cout << "-------------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "-------------------------" << endl;
}

// 2) �ּ� ���� ���
// [�Ű�����][RET][��������(info)] [�Ű�����(&info)][RET][��������]
void PrintInfoByPtr(StatInfo* info)
{
	cout << "-------------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "-------------------------" << endl;
}


// StatInfo ����ü�� 1000����Ʈ¥�� ���� ����ü���?
// - (�� ����) StatInfo�� �ѱ�� 1000����Ʈ�� ����Ǵ�
// - (�ּ� ����) StatInfo*�� 8����Ʈ // �ּҴ� ������ 4����Ʈ �Ǵ� 8����Ʈ��.
// - (���� ����) StatInfo&�� 8����Ʈ //c���� ���� ����, c++���� ����. 


// 3) ���� ���� ��� 
// �� ����ó�� ���ϰ� ����ϰ�!
// �ּ� ����ó�� �ּҰ��� �̿��� ������ �ǵ帰��! �ٸ� �ּҰ��� �����ϴ� �κ��� �������ִ�.
// �ϼ������� ���!---- �ٵ� ������ ������ �ִ°� �ƴϴ�. �����ð��� �˷���
// (1)��(2) ����� ���̿� ��ġ�� ����̶�� �����ϸ��.
// ���������� 2���� �Ȱ���.
// Low level �������� �����Ϳ� ������ �Ȱ��� ��������. �׷��� ����ϴ� �������̽� ��ü�� �����Ͷ� �ٸ��� �Ϲ����� ����� ����ϰ� �����.

void PrintInfoByRef(StatInfo& info)
{
	cout << "-------------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "-------------------------" << endl;
}

int main()
{

	// 4����Ʈ ������ �ٱ��ϸ� ����Ҳ���.
	// ������ �� �ٱ��� �̸��� number��� �Ҳ�.
	// �׷��ϱ� number���� �� �����ų�, number�� �� �ִ´ٰ� �ϸ�
	// �������� �˾Ƶ�� �ش� �ּ�(data, stack, heap)�� 1�� �־��ָ� �ȴ�!
	int number = 1;

	// * : �ּҸ� ��� �ٱ���
	// int �� �ٱ��ϸ� ���󰡸� int ������(�ٱ���)�� ����.
	int* pointer = &number;
	// pointer �ٱ��Ͽ� �ִ� �ּҸ� Ÿ�� �̵��ؼ�, �� �ָ� �ִ� �ٱ��Ͽ� 2�� �ִ´�.
	*pointer = 2;


	// �ο췹��(�����) �������� ���� �۵� ����� int*�� �Ȱ���
	// ������ �����غ��� �����Ͷ� 100% �Ȱ���.
	int& reference = number;// �̰Ŵ� ������ �ʱⰪ�� �־������.

	//C++ ���������� number��� �ٱ��Ͽ� �� �ٸ� �̸��� �ο��� ��.
	// number ��� �ٱ��Ͽ� reference��� �ٸ� �̸��� �����ٲ�
	// ������ reference �ٱ��Ͽ��ٰ� �� �����ų� ������,
	// ���� number �ٱ���(�������ٰ�) �� ���� �����ų� �������.

	reference = 3;// ������ number�� 3�� �ִ°�.

	// �׷��� ������ �� �ٸ� �̸��� ���� ������?
	// �׳� number = 3 �̶�� �ص� �Ȱ�����...
	// ********** ���� ���� ����!***********
	// (.)�� �� ��밡��.

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByCopy(info);
	PrintInfoByPtr(&info);
	PrintInfoByRef(info);// �ּҸ� �ȳѰ��൵. ������ �ǵ帱���ִ�. --> ���������� �˾Ƽ� �ּҰ��� �����ؼ� ����ϰԵɰ��̴�.




}