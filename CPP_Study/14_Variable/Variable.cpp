#include<iostream>
using namespace std;

// ������ ���� : ���� ������ ��(value) ����

// ���� ����-- �����ؾ��Ѵ�. ������ ��Ʊ� ����. // �������� ���� ��ſ� �����Ͱ� ���ϼ� �ִ� Ȯ���� ���⶧���̴�.
int globalValue = 0;

void Test() 
{
	cout << "���� ������ ���� : " << globalValue << endl;
	globalValue++;
}

void IncreaseHp(int hp)
{
	int finalHp = hp + 1;
	hp = hp + 1;
}
// ������ �׸��� �� �׸��� �˾ƾ��Ѵ�.
// [�Ű�����][RET][��������(hp=1)] [�Ű�����(hp=1)][RET][��������(finalHp=2)] [�Ű�����][RET][��������] .....
// �Ű�����, RET�� ���� �Լ��� ������ ����.
// �Ű����� : ����� , push push �ؼ� ���ÿ� �־���.
// ret : call �Ҷ� , �־���.
// �׷��ٸ� ���� hp�� ������Ű�� ������ ��� �ؾ�? : ������, ������ ����� ���ؼ�...
int main() {

	cout << "���� ������ ���� : " << globalValue << endl;
	Test();
	//���� ����
	int localValue = 1;

	int hp = 1;
	cout << "increase ȣ�� �� : " << hp << endl;
	IncreaseHp(hp);
	cout << "increase ȣ�� �� : " << hp << endl;


	return 0;
}