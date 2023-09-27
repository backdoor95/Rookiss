#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<deque>
using namespace std;

// ������ ���� : �˰���

int main()
{
	// �ڷᱸ�� (�����͸� �����ϴ� ����)
	// �˰��� (�����͸� ��� ����� ���ΰ�?)

	// �������� ���ֻ���ϴ°� ����
	// �ڵ��� ���Ἲ�� �־ �ξ� ���� ������ �ִ�.
	// find
	// find_if
	// count
	// count_if
	// all_of
	// any_of
	// none_of
	// for_each
	// remove
	// remove_if





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

		vector<int>::iterator itFind = find(v.begin(), v.end(), number);// v.begin() ����, v.end() ������
		//find�� list������ �� �����Ѵ�.
		if (itFind == v.end())
			cout << "��ã����" << endl;
		else
			cout << "ã����" << endl;

	}


	// Q2) 11�� ������ ���ڰ� ���Ϳ� �ִ��� üũ�ϴ� ��� (bool, ù ���� iterator)
	{
		struct CanDivideBy11
		{
			bool operator()(int n)// operator �����ε����ش�.
			{
				return (n % 11) == 0;
			}
		};

		// 3��° ���ڴ� ������ �־��ش�(Pred) prdicate
		vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivideBy11());// 1. �Լ���ü
		//vector<int>::iterator itFind = find_if(v.begin(), v.end(), [](int n){return (n%11)==0;});// 2. ���� ���
			//3��° ���ڿ�  1. �Լ� ��ü, 2. ���� ���� ����� �� �ִ�.

		if (itFind == v.end())
			cout << "��ã����" << endl;
		else
			cout << "ã����" << endl;

	}


	// Q3) Ȧ���� ������ ������? (count)
	{
		struct IsOdd
		{
			bool operator ()(int n)
			{
				return (n % 2) != 0;
			}
		};

		int n = count_if(v.begin(), v.end(), IsOdd());

		// ��� �����Ͱ� ������ �����ϳ�?
		// ��� �����Ͱ� Ȧ����?
		bool b1 = all_of(v.begin(), v.end(), IsOdd());
		// Ȧ���� �����Ͱ� �ϳ��� �ֽ��ϱ�?
		bool b2 = any_of(v.begin(), v.end(), IsOdd());
		// ��� �����Ͱ� Ȧ���� �ƴմϱ�?
		bool b3 = none_of(v.begin(), v.end(), IsOdd());
	}


	// Q4) ���Ϳ� �� �ִ� ��� ���ڵ鿡 3�� �����ּ���!
	{
		struct MultiplyBy3
		{
			void operator()(int& n)
			{
				n = n * 3;
			}
		};

		for_each(v.begin(), v.end(), MultiplyBy3());

	}

	// remove, remove_if : ��¦ ���ϰ� ������.
	// Ȧ���� �����͸� �ϰ� ����
	{
		//for (vector<int>::iterator it = v.begin(); it != v.end();)// data�� �ǵ帱��, for �ȿ��� it�� ++ ���ִ°� ����. �Ʒ����� ���������ִ°� ����. --> �� ���������.
		//{
		//	if ((*it % 2) != 0)
		//	{
		//		it = v.erase(it);
		//	}
		//	else
		//	{
		//		++it;
		//	}
		//}//���ͷ����ͷ� ������ ����, ���� ��ü�� �ǵ帮�� ������ ������ �����ϴ�. ---> �� �κп��� ���װ� ���� �߻���.

		v.clear();
		v.push_back(1);
		v.push_back(4);
		v.push_back(3);
		v.push_back(1);
		v.push_back(5);
		v.push_back(8);
		v.push_back(2);

		// 4�� ����
		remove(v.begin(), v.end(), 4);

		//
		struct IsOdd
		{
			bool operator ()(int n)
			{
				return (n % 2) != 0;
			}
		};

		// 1 4 3 5 8 2
		// 4 8 2 5 8 2 ??? �� �̷��� �Ȱɱ�?
		/*
		* ��ó : https://en.cppreference.com/w/cpp/algorithm/remove
template<class ForwardIt, class UnaryPredicate>
ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = std::find_if(first, last, p);
    if (first != last)
        for (ForwardIt i = first; ++i != last;)
            if (!p(*i)) // ��������� ���ҵ�
                *first++ = std::move(*i);//��������ϴ� �ֵ� �����ؼ� �ٲ�ġ��
    return first;// [4 8 2 ]       [5 8 2 ]-> �ʿ��� �����͸� ��Ƴ��� �� ������ ������ ������ ���� (�� �̻� ������� �ʾƼ� ������ �Ǵ�)�� ù ��ġ�� ��ȯ����.
	!! �� �κ��� �����Ұ�
}
		�����͸� ã�ڸ��� �ָ� �����ϰ� ã�ڸ��� �����ϰ� �̷� ������ �����Ѵٰ� �ϸ��� �������� ������
		��� �����͵��� �� ĭ�� ������ �Ǵ� �׷� �ſ� ��ȿ������ ������ �Ͼ.
		�׷��� remove_if�� ���ʿ��� �����͸� �����ϴ°� �ƴ϶� �ʿ��� �����͸� ���ܵδ� �ʿ� ������ ������ �ϰ� �ִ�.
		*/


		vector<int>::iterator it = remove_if(v.begin(), v.end(), IsOdd());
		v.erase(it, v.end());// �̷��� �ؾ�[ 5 8 2 ]�� ����.!!!
		//v.erase(remove_if(v.begin(), v.end(), IsOdd()), v.end());// ���ٷ� ó���ϱ� ---> �̰� ���� ����Ѵٰ� ��.!


		// remove�� ����� ���� �׻� �� vector �������� ���� erase�� ���� ����Ѵ�.



	}


	// ���
	// �˰��� �ø������ �ͼ������� �ξ� �� �ڵ� �������� ��������, �ڵ��� ���뼺�� ��������.
	// 

	return 0;
}