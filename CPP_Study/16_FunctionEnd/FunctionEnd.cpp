#include<iostream>
using namespace std;

// ������ ���� : �Լ� ������

// �����ε� (�ߺ� ���� : �Լ� �̸��� ����)
// - �Ű����� ������ �ٸ��ų�
// - �Ű����� Ÿ���� �ٸ��ų� (������ �ٸ��� ����)

int Add(int a, int b)
{
	int result = a + b;
	return result;
}

int Add(int a, int b=0)
{
	int result = a + b;
	return result;
}


int Add(int a)// �̷��� ���带 �ϸ� ��ȣ�ϱ� ������ �����Ϸ��� ������ ����.
{
	int result = a + 1;
	return result;
}

//float Add(int a, int b)// ��ȯ ���ĸ� �ٸ��� �����ε��� �ȵ�.
//{
//	int result = a + b;
//	return result;
//}

float AddFloat(int a, float b)
{
	float result = a + b;
	return result;
}


float AddFloat(float a, float b)
{
	float result = a + b;
	return result;
}

// �⺻ ���ڰ�
void SetPlayerInfo1(int hp, int mp, int attack, int guildId = 0)
{

}

//void SetPlayerInfo2(int hp, int mp, int attack=0, int guildId)// �̷����ϸ�, �⺻ �μ��� �Ű� ���� ����� ���� ���ٰ� ������.
//{// �׷��� �׻� �⺻���� �����ϴ� �Ű������� ���ʿ��ٰ� ���� �־����.
//
//	
// 
// 
// 
//}

//void SetPlayerInfo3(int hp, int mp, int attack=1, int guildId=2)// 
//{// �׷��� �׻� �⺻���� �����ϴ� �Ű������� ���ʿ��ٰ� ���� �־����.
//
//	
// 
// 
// 
//}


// ���� �����÷ο�
// �ʹ� �Լ��� ���� ȣ���ϸ� �߻���.

int Factorial(int n)
{
	// ����Լ��� �������� �ʿ�
	if (n <= 1) return 1;

	return n * Factorial(n - 1);
}




int main() {

	float result = AddFloat(1.5f, 2.1f);
	cout << result << endl;

	SetPlayerInfo1(100, 40, 10);
//	SetPlayerInfo2(100, 40, 10, 0);

	// 5! = 5*4*3*2*1 = 5*4!

	int result2 = Factorial(5);
	cout << result2 << endl;

	return 0;
}