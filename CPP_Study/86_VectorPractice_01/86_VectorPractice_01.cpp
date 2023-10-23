// 86_VectorPractice_01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include<vector>
#include <iostream>
using namespace std;


int main()
{
	const int MAX_SIZE = 10;
	int arr[MAX_SIZE] = {};

	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i] << endl;
	}

	int arr1[100];
	int* arr2 = new int[100];

	delete arr2;

	arr2 = new int[1000];

	vector<int>v;

	// size : 실제 데이터의 개수
	// capacity : 수용 가능한 용량 개수 ---> 1.5배씩 증가.!
	cout << v.size() << " " << v.capacity() << endl;

	v.reserve(1000);



}

