#include<iostream>
using namespace std;

int main() 
{
	int input;
	cin >> input;// �Է�



	cout << "hello world"<<endl;


	// 1. �����
	/*
		�������� � ������ �Է��ϸ�
		N*N���� ���� ������� ���ھ��!
	*/
	// �� Ǯ�� = Rookiss Ǯ�� 
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	// 2. ����� 2ź
	// 1������ �����ؼ� ���������� �ٸ��� �����ϰ� ���ּ���
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl << endl << endl;
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl << endl << endl;

	//3. ����� 3ź
	// n������ �����ؼ� �ٸ��� �Ѱ��� �پ�鵵��

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < (input - i); j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl << endl << endl;


	// ������
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}




}