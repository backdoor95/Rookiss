#include<iostream>
using namespace std;

// �����
// 
// F5 - �ѹ濡 ����, ���� break point ���� �̵�.

// F10 - ���ν���(�Լ�)���� ����

// F11 - �� �پ� �ڵ� ����

// ������ ���� �ּҿ��� �����ؼ� ���� �ּҷ� �̵��Ѵ�.
// �Լ� = 1.�Ű�����, 2.��ȯ �ּҰ� , 3.�������� �� ����

// ������� ���
// ����� ����� x86�� ������ ���� x64�� ������ ��, ������� ���ݾ� �ٸ��ٴ°� �˰Ե�. 
//
// call �ϸ� return �ּҰ� ���ÿ� �־�����.





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

	int a = 3;
	int b = 5;
	int result = MultiplyBy(b, a);

	PrintNumber(result);
	return 0;
}