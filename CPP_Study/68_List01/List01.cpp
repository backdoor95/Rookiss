#include<iostream>
using namespace std;
#include<vector>
#include<list>

// ������ ���� : list

// vector�� �����迭���
// List�� node ���

// vector : �����迭

// ����/ ���� / ����
// list : ���Ḯ��Ʈ
// [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [6] <->[_Myhead : end()] <-> // ���̳��

// ���ȿ� ��尡 �ƴ�!

// �ǹ� ���赵�� �ϼ��ϱ� ���ؼ��� �ǹ� ���赵�� �ϼ��ؾ���? ====> ���� �ȵ�.! ���� �����͸�! ��.
//class Node2
//{
//public:
//	Node2 _next;
//	int _data;
//};

// [data(4) next(4/8) ] ---> size�� 8�Ǵ� 12�� ����
class Node
{
public:
	Node* _next;// ���� ����� �ּ� 
	Node* _prev;// ���� ����
	int _data;
};
// �츮�� STL ����Ʈ�� ����ϰ� �� ��쿡�� ���߿��Ḯ��Ʈ�� ������� �ִ�.


int main()
{
	// list (���� ����Ʈ)
	// - list�� ���� ����
	// - �߰� ����/���� (GOOD/GOOD)
	// - ó��/�� ����/���� (GOOD/GOOD)
	// - ���� ���� --> ����Ʈ������ ������ ������ ���������� ���Ƶ�!

	list<int> li;
	for (int i = 0; i < 100; i++)
	{
		li.push_back(i+1);
	}

	//li.push_front(10);// List���� push_front�� �ִ�.
	// ���Ϳ��� push_front�� ����.!
	// ���Ͱ��� ��� ����/�����ϴ°��� ��ȿ�����̱� �����̴�.
	// list�� push /front�� ������� ȿ�������� �۵��ϱ� ����.


	int size = li.size();
	//int capacity = li.capacity();// ����Ʈ���� �����迭�� ���°� �ƴϱ� ������ �뷮�� ������ ���� ������ capacity�� ����.
	
	int first = li.front();
	int last = li.back();// ������ ������ ���� !!  li.end()�� �ٸ�����.!!!

	// [] : list���� ���������� ����!!
	// li[3] = 10;// ����
	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	list<int>::iterator itTest1 = --itBegin;// �ȵ�
	list<int>::iterator itTest2 = --itEnd;// ��
	list<int>::iterator itTest3 = ++itBegin;// �ȵ�.
	// ���� ��带 �������� ���� �߸��� �̵��� �������� ����!

	//list<int>::iterator it2 = itBegin + 10; // ���ʹ� ��������� ������ ���갡���ϳ�, list������ �ּҸ� Ÿ�� �Ѿ���ϱ� ������ ��ȿ�����̿��� ���������� ���Ƶ�.
	



	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());

	// ����Ʈ ���ͷ����Ϳ��� �ش� ����� �����͸� ��� �ִ�.!!

	for (list<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << *it << endl;
	}

	//li.insert(itBegin, 100);// ù ��ġ�� 100 ����
	//li.erase(li.begin());// ù��° ��ġ data ����
	//li.pop_front();// ù��° ��ġ data ����
	//li.remove(10);// vector���� remove�� ����!! list�� remove�� �ִ�. ---> value�� 10�� ���Ҹ� ����!!!

	////////////////////////////////////////////////////////////////////

	// * ���� ������ �� �ȴ�! -- 1
	// * �׷��� �߰� ����/������ ������? -- 2
	// ex) 50��° �����͸� �����ϰ� �ʹ�!!

	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50; i++)// 1
	{
		++it;
	}
	//li.erase(it + 50);// �̰� �ȵ�!!
	li.erase(it);// �̷��� �ؾ���.// 2

	// ��� : 1, 2�� �и��ؼ� �����Ѵ�.

	list<int> li2;

	list<int>::iterator itRemember;

	for (int i = 0; i < 100; i++) // 3.
	{
		if (i == 50)
		{
			itRemember = li2.insert(li2.end(), i);// insert�� �ϸ� insert�� ��ġ�� ��ȯ���ش�.
		}
		else
		{
			li2.push_back(i);
		}
	}

	li2.erase(itRemember);// 3���: �ش� ���ͷ����͸� ����� �صξ��ٰ� �̷��� ����Ҽ��� �ִ�.


	////////////////////////////////////////////////////////////////////
	return 0;
}