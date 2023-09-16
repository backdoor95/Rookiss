#include<iostream>
using namespace std;

// ������ ���� : �ζ� ��ȣ ������
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
// 2) ���� �Լ� ����� (���� ���ڰ� ���� ������ ����)
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
		// i��° ���� ���� ���� �ĺ���� ����
		int best = i;
		// �ٸ� �ĺ��� �񱳸� ���� ���� ���� �ĺ��� ã�� ������.
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[j] < numbers[best])
			{
				best = j;
			}

		}

		if (i != best) // i�� best�� �ƴҶ��� ����.
			Swap(numbers[i], numbers[best]);

	}
}
// 3) �ζ� ��ȣ ����
// �� Ǯ��
void ChooseLotto1(int numbers[])
{
	// TODO : �������� 1~45 ������ ���� 6���� ����ּ���!(��, �ߺ��� �������.)

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
void ChooseLotto2(int numbers[])// Rookiss Ǯ��
{

	int count = 0;
	while (count != 6)
	{
		int randValue = 1 + (rand() % 45);// 1~45

		// �̹� ã�� ������?
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				found = true;
				break;
			}
		}

		// �� ã������ �߰�!
		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}


	}

	// TODO : �������� 1~45 ������ ���� 6���� ����ּ���!(��, �ߺ��� �������.)
	Sort(numbers, 6);


}

int main()
{
	// 1) Swqp �Լ� �����
	int a = 1;
	int b = 2;

	// �� Ǯ��
	//SwapByRef(a, b);
	//cout << a << " " << b << endl;

	//a = 1; b = 2;
	//SwapByPointer(&a, &b);
	//cout << a << " " << b << endl;

	//output a=2, b=1

	// Rookiss Ǯ��
	a = 1; b = 2;

	Swap(a, b);

	
	// 2) ���� �Լ� ����� (���� ���ڰ� ���� ������ ����)
	int numbers[6] = { 1,42,3,15,5,6 };

	int size1 = sizeof(numbers);// 6��*4����Ʈ = 24 ����Ʈ
	int size2 = sizeof(int);// 4

	//Sort(numbers, 6);// sizeof(numbers)/sizeof(int) --- �迭�� �ε��� ���ϱ�
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


	// 3) �ζ� ��ȣ ������

	srand((unsigned)time(0)); // ���� �õ� ����

	//ChooseLotto1(numbers);// ��Ǯ��
	//cout << "------------------�ζ� ��ȣ ������------------------"<<endl;
	//for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
	//{
	//	cout << numbers[i] << " ";
	//}
	//cout << endl;

	cout << "------------------�ζ� ��ȣ ������------------------" << endl;
	for (int i = 0; i < 5; i++)
	{
		ChooseLotto2(numbers);// Rookiss Ǯ��
		for (int i = 0; i < sizeof(numbers) / sizeof(int); i++)
		{
			cout << numbers[i] << " ";
		}
		cout << endl;
	}



	return 0;
}