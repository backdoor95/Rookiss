#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>
using namespace std;

// ������ ���� : ��������


int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// Q1) number��� ���ڰ� ���Ϳ� üũ�ϴ� ��� (bool, ù ���� iterator)
	{
		int number = 50;

		bool found = false;
		vector<int>::iterator it;

		// TODO
		// �� Ǯ��
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			if (*it == number)
			{
				found = true;
				break;
			}
		}
		cout << "found = " << found << endl;

		// Rookiss Ǯ��
		vector<int>::iterator it = v.end();
		for (int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if (data == number)
			{
				found = true;
				it = v.begin() + i;
				break;
			}
		}
		int a = 3;
	}

	// Q2) 11�� ������ ���ڰ� ���Ϳ� �ִ��� üũ�ϴ� ��� (bool, ù ���� iterator)
	{
		bool found = false;
		vector<int>::iterator it;

		//TODO - �� Ǯ��

		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			int data = *it;
			if (data % 11 == 0)
			{
				found == true;
				break;
			}

		}

		cout << "found : " << found << endl;



		// Rookiss Ǯ��
		for (int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if ((data % 11) == 0)
			{
				found = true;
				it = v.begin() + i;// list������ ������.
				break;
			}
		}

	}

	// Q3) Ȧ���� ������ ������? (count)
	{
		int count = 0;
		//TODO
		for (unsigned int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if (data % 2 != 0)
			{
				count++;
			}
		}
		cout << "Count : " << count << endl;
	}

	// Q4) ���Ϳ� �� �ִ� ��� ���ڵ鿡 3�� �����ּ���!
	{

		for (unsigned int i = 0; i < v.size(); i++)
		{
			// ver 1.0
			int& data = v[i]; // ���۷����� ���� 3�� ���ϰų�
			data *= 3;
			//ver 2.0
			v[i] *= 3;// v[i] ��ü�� ������ ����ش�.
		}

	}

	return 0;
}