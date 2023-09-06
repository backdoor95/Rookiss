#include<iostream>
using namespace std;

int main() 
{
	int input;
	cin >> input;// 입력



	cout << "hello world"<<endl;


	// 1. 별찍기
	/*
		유저들이 어떤 정수를 입력하면
		N*N개의 별을 찍었으면 좋겠어요!
	*/
	// 내 풀이 = Rookiss 풀이 
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	// 2. 별찍기 2탄
	// 1개부터 시작해서 순차적으로 줄마다 증가하게 해주세요
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

	//3. 별찍기 3탄
	// n개부터 시작해서 줄마다 한개씩 줄어들도록

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < (input - i); j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl << endl << endl;


	// 구구단
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}




}