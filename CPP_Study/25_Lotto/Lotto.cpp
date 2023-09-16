#include<iostream>
using namespace std;

// 오늘의 주제 : 로또 번호 생성기
void SwapByRef(int& i, int& j)
{
	int temp;
	temp = i;
	i = j;
	j = temp;
}
void SwapByPointer(int* i, int* j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
// 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
void SortByMun(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = i+1; j < count; j++)
		{
			if (numbers[i] > numbers[j])
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}
void Sort(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		// i번째 값이 제일 좋은 후보라고 가정
		int best = i;
		// 다른 후보와 비교를 통해 제일 좋은 후보를 찾아 나선다.
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[j] < numbers[best])
			{
				best = j;
			}

		}

		if (i != best) // i가 best가 아닐때만 변경.
			Swap(numbers[i], numbers[best]);

	}
}
// 3) 로또 번호 생성
// 내 풀이
void ChooseLotto1(int numbers[])
{
	// TODO : 랜덤으로 1~45 사이의 숫자 6개를 골라주세요!(단, 중복이 없어야함.)

	for (int i = 0; i < 6; i++)
	{
		int flag = 0;
		int randomNumber;
		while (true)
		{
			randomNumber = (rand() % 45) + 1;

			for (int j = 0; j < i; j++)
			{
				if (randomNumber == numbers[i])
				{
					flag = 1;
					break;
				}
			}

			if (flag == 0) break;
		}
		numbers[i] = randomNumber;

	}

	Sort(numbers, 6);

}
void ChooseLotto2(int numbers[])// Rookiss 풀이
{

	int count = 0;
	while (count != 6)
	{
		int randValue = 1 + (rand() % 45);// 1~45

		// 이미 찾은 값인지?
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				found = true;
				break;
			}
		}

		// 못 찾았으면 추가!
		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}


	}

	// TODO : 랜덤으로 1~45 사이의 숫자 6개를 골라주세요!(단, 중복이 없어야함.)
	Sort(numbers, 6);


}

int main()
{
	// 1) Swqp 함수 만들기
	int a = 1;
	int b = 2;

	// 내 풀이
	//SwapByRef(a, b);
	//cout << a << " " << b << endl;

	//a = 1; b = 2;
	//SwapByPointer(&a, &b);
	//cout << a << " " << b << endl;

	//output a=2, b=1

	// Rookiss 풀이
	a = 1; b = 2;

	Swap(a, b);

	
	// 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
	int numbers[6] = { 1,42,3,15,5,6 };

	int size1 = sizeof(numbers);// 6개*4바이트 = 24 바이트
	int size2 = sizeof(int);// 4

	//Sort(numbers, 6);// sizeof(numbers)/sizeof(int) --- 배열의 인덱스 구하기
	//SortByMun(numbers, sizeof(numbers) / sizeof(int));
	//// 1,3, 5,6,15,42
	//for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	//{
	//	cout << numbers[i] << " ";
	//}
	//cout << endl;

	//Sort(numbers, sizeof(numbers) / sizeof(int));
	//for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	//{
	//	cout << numbers[i] << " ";
	//}
	//cout << endl;


	// 3) 로또 번호 생성기

	srand((unsigned)time(0)); // 랜덤 시드 설정

	//ChooseLotto1(numbers);// 내풀이
	//cout << "------------------로또 번호 생성기------------------"<<endl;
	//for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	//{
	//	cout << numbers[i] << " ";
	//}
	//cout << endl;

	cout << "------------------로또 번호 생성기------------------" << endl;
	for (int i = 0; i < 5; i++)
	{
		ChooseLotto2(numbers);// Rookiss 풀이
		for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
		{
			cout << numbers[i] << " ";
		}
		cout << endl;
	}



	return 0;
}