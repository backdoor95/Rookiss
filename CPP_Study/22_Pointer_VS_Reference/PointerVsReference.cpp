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

// Ư�� ������ �����ϴ� ���͸� ã�� �Լ�
StatInfo* FindMonster()
{
	// TODO : Heap �������� ������ ã�ƺ�.
	// ã�Ҵ�!
	// return monster ~;


	return nullptr;
}

StatInfo globalInfo;
/*
* �����Ϳ��� const�� ����� �� �ִ�.
* �����Ϳ��� const�� �ٿ��� ��ġ�ʴ� �۾��� ���Ƽ� �������� ���� �� �ִ�.
* �ٵ� �����Ϳ����� const�� �ʼ��� �ƴϴ�. but ���������� ������ �ؼ��� const�� ��Ʈ�� ����.
* 
1) * �տ� const�� ���̴� ���
---1. void PrintInfo(const StatInfo* info) - �� ����� ���� ����.
---2. void PrintInfo(StatInfo const* info)// �̷��� ���� ����� �ִ�.

2) * �ڿ� const�� ���̴� ���
---   void PrintInfo(StatInfo*const info)

3) * ��, �� ���const�� ���̴� ���
	  void PrintInfo(const StatInfo* const info)

*/
void PrintInfo(const StatInfo* const info)
{
	//�׻� �����͸� nullptr üũ
	if (info == nullptr)
		return;// 

	if (!info)// �̷��Ե� null üũ ����, �ٵ� �������� �� �������� ����.
		return;


	cout << "-------------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "-------------------------" << endl;

	
	// �� �ڿ� ���δٸ�?
	// StatInfo* const info
	// info��� �ٱ����� ���빰(�ּ�)�� �ٲ� �� ����.
	// info�� �ּҰ��� ���� �ٱ��� -> �� �ּҰ��� �����̴�!

	
	// �� ������ ���δٸ�?
	// const StatInfo* info
	// info�� '����Ű�� �ִ�' �ٱ����� ���빰�� �ٲ� �� ����
	// '����' �ٱ����� ���빰�� �ٲ� �� ����.

	// �׳� ���� �ٲܼ� ���� �Ϸ��� 
	// *  ��, �ڷ� const�� �ٿ��ָ��.
	// const StatInfo* const info

	// 1.info[ �ּҰ� ]      2.�ּҰ�[ ������ ]
	// 1. void PrintInfo(StatInfo* const info) �϶�, �����߻�.
	// �ּҰ��� �� �ٲ�
	//info = &globalInfo;

	// 2. void PrintInfo(const StatInfo* info) �϶�, �����߻�
	// �ش� �ּҰ��� ���빰�� �� �ٲ�.
	//info->hp = 10000;


}

// �̸� �ٲٱ� ����Ű : ctrl + R R
void PrintInfo(const StatInfo& info)// ���࿡ 100% Ȯ���� info�� �������� �����Ŷ�� Ȯ���� �ִٸ�
// const�� �ٿ�����. �������ؼ��� reference�� const�� ��Ʈ�� �ٴϴ� ��찡 ����.
{
	cout << "-------------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "-------------------------" << endl;

	// ������ �Դ�.
	//info.hp = 2;// ���� �߻�, const�̱� ������ �� �ٲ�
}


// ���� �������� ����ϴ� ����� ���� ����.
// �ڿ� �ƹ��͵� ����. ������ �ɶ� �ƹ��� �ǹ̰� ����
#define OUT
// c#������ out�̶�� ������ �ִ�.
// c++������ �ٲ���� �ִٶ�� ��Ʈ�� �ִ� �뵵�� ����.
// �𸮾� ���� ���ÿ����� �̷� ����� ���̾�.
void ChangeInfo(OUT StatInfo& info)
{
	info.hp = 1000;
}

int main()
{
	StatInfo info;
	CreateMonster(&info);

	// ������ vs ���� ������ ���
	// ���� : �Ȱ���
	// ���Ǽ� : ���� ��!

	// 1) ���Ǽ� ����
	// ���Ǽ��� ���ٴ°� �� �������� �ƴϴ�.
	// �����ʹ� �ּҸ� �ѱ�� Ȯ���ϰ� ������ �ѱ�ٴ� ��Ʈ�� �� �� �ִ�.
	// ������ �ڿ������� �𸣰� ����ĥ ���� �ִ�.
	// ������ ���� �𸣰� ������ �Ѽ��� �� �ִ�.
	// ex) ������� ��ģ�ٸ�?
	// const�� ����ؼ� �̷� ������� ��ġ�� �κ� ��������

	// ����� �����͵� const�� ��� ����.
	// * �������� �տ� ���̴���, �ڿ� ���̴��Ŀ� ���� �ǹ̰� �޶�����.


	// 2) �ʱ�ȭ ����
	// ���� Ÿ���� �ٱ����� 2��° �̸� (��Ī?)
	// -> �����ϴ� ����� ������ �ȵ�.
	// �ݸ� �����ʹ� �׳� � ~�ּҶ�� �ǹ�
	// -> ����� �������� ���� ���� ����.
	// reference�� ��Ģ���� �ȵ�. �����ʹ� ��.
	// �����Ϳ��� '����'�� �ǹ̷�?  --> nullptr or NULL
	// ���α׷��� ���� ������ 80%�� ��ȿ���� ���� �ּҶ���.
	// 
	// ���� Ÿ���� �̷� nullptr�� ����.
	// ������ � ���� ����Ű�� ����


	// StatInfo* pointer = &info;// �̷��� �ص���.
	StatInfo* pointer = nullptr;// NULL�� �־�ǳ�, null �����Ͷ�� �ǹ̿��� nullptr�� ����.
	int a = NULL;// nullptr�� ������. ������.

	pointer = &info;
	PrintInfo(pointer);
	PrintInfo(&info);

	//StatInfo& reference; // ����������. reference�� ������ ������ �ϰ� �־����.
	StatInfo& reference = info;
	PrintInfo(reference);

	PrintInfo(info);

	// �׷��� ���?
	// ��� Team By Team ... ������ ���� ����.
	// ex) ���ۿ��� ���� ���¼ҽ��� ���� ���� ������ ������ ���
	// ex) �𸮾� �������� reference�� �ֿ�

	
	// Rookiss ��ȣ ��Ÿ��
	// - ���� ��쵵 ����ؾ� �Ѵٸ� pointer (null üũ �ʼ�)
	// - �ٲ��� �ʰ� �д� �뵵(readonly)�� ����ϸ� const ref&
	// - �� �� �Ϲ������� ref(��������� ȣ���� �� OUT�� ���δ�.)
	// -- ��, �ٸ� ����� pointer�� ���������� �̾ ����ٸ�, ��� pointer (���� ������� �ʴ´�. ref�� �ٲ��� �ʴ´ٴ� �ǹ�.)
	ChangeInfo(OUT info);// �̷��� �ϸ� ������ ���鿡�� �̰� �� ���Ǳ�� Ȯ���� �� �ִ�.

	// ���ʽ�) �����ͷ� ����ϴ��� ������ �Ѱ��ַ���?
	PrintInfo(pointer);

	// ���ʽ�) ������ ����ϴ��� �����ͷ� �Ѱ��ַ���?


	return 0;

}