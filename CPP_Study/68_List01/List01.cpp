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
	// - �߰� ����/����
	// - ó��/�� ����/����
	// - ���� ����

	list<int> li;
	for (int i = 0; i < 100; i++)
	{
		li.push_back(i);
	}

	li.push_front(10);// List���� push_front�� �ִ�.
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

	for (list<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);// ù ��ġ�� 100 ����
	li.erase(li.begin());// ù��° ��ġ data ����
	li.pop_front();// ù��° ��ġ data ����
	
	li.remove(10);// vector�� �ٸ��� remove�� �ִ�. ---> value�� 10�� ���Ҹ� ����!!!




	return 0;
}