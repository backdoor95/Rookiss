#include<iostream>
using namespace std;

//������ ���� : ȣ�� ����

//�Լ� ���� - ������ ������ �������.
void Func1();
void Func2(int a, int b);//����ο��� �Ű����� �̸��� �����ص���. (int, int)
void Func3(float a);

//����δ� ������ ���Ϸ� ���� �ɰ��̴�.

//������ �κе� ������ ���Ϸ� �����ϰ� �ɰ��̴�.


//����� ����϶�, ȣ�� ������ ������ڵ带 ��� call ���� �ּҸ� ����Ű�� �ִ�.
// ������ �Ʒ��� �ִ� ȣ�⽺�ÿ� �� ������ ���������ӿ��� ��� ��ȯ�ּҰ��̶� �����Ǿ��ִ�.
// ���߿� ȣ�⽺���� ���̺��� �� ���̴�.

int main()
{
	cout << "main" << endl;
	Func1();
	return 0;
}



void Func1()
{
	cout << "Func1" << endl;
	// push 2 // ������ �Ű��������� stack�� push �Ѵ�.
	// push 1
	// call Func2 // �Լ��� ��ġ�� ���� ���ϸ�, ���� ������ �߻��Ѵ�. ���� �Լ� ������ �����ؾ���.-> ctrl+shift + b�� �ϸ� ���� ����!
	Func2(1, 2);
	Func3(10.0f);
}

void Func2(int a, int b)
{
	cout << "Func2" << endl;
	Func3(10);
}

void Func3(float a)
{
	cout << "Func3" << endl;
}

