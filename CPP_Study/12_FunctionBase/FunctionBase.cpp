#include<iostream>
using namespace std;

// ������ ���� : �Լ� (����������� ���ν���, c#: �޼ҵ�, ��ƾ)

/*

input���� ������ �ް�, output���� ������ ������ �����ش�.

��ȯŸ�� �Լ��̸�([����Ÿ�� �Ű�����])
{
	�Լ� ����

	return ~~~~;


}


*/

// Hello World�� �ֿܼ� ����ϴ� �Լ��� ������!
// input ����, output :����
// Ÿ�� : int, float, double, char ,~~~ , void

void PrintHelloWorld()// �Ϲ������� �빮�ڷ� ����, �Ű������� void �ϳ��� ���ٸ� �����ص���.
{
	cout << "Hello World" << endl;
	return;// void ��ȯ Ÿ���϶� �����ص��ǰ�, �̷��� ������ �ص���. // �Լ��� ��������.!
	cout << "Test" << endl;// �� �ڵ�� ������ �ȵ�.
}

//������ �Է�(�Լ�) �޾Ƽ�, �ֿܼ� ����ϴ� �Լ��� ������.
// input : int // output : ����
void PrintNumber(int number)
{
	cout << "�Ѱ��ֽ� ���ڴ� " << number << " �Դϴ�." << endl;
}

// 2�� ���ϰ� ����� ��� �Լ��� ������
int MultiplyBy2(int a)
{
	int b = a * 2;
	return b;
}

// �� ���ڸ� ���ؼ� ������� ��� �Լ��� ������
//input : int, int /output : int

int MultiplyBy(int a, int b)
{
	int c = a * b;
	return c;
}

int main()
{

	PrintHelloWorld();

	PrintNumber(2);

	//int result = MultiplyBy2(3);

	int a = 3;
	int b = 5;
	int result = MultiplyBy(b, a);

	return 0;
}