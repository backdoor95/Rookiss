#include<iostream>
#include<algorithm>
#include<list>
#include<vector>

// ������ ���� : using 

typedef __int64	id;

using id2 = int;

// 1) ������
typedef void (*MyFunc)();

using MyFunc2 = void(*)();// �ڵ��� �������� ������

// 2) ���ø�
//typedef�� ���ø��� Ȱ���� �� ����.
//template<typename T>
//typedef void

template<typename T>
using List = std::list<T>;

template<typename T>
using List2 = std::vector<T>;

//template<typename T>
//typedef std::vector<T> List3; // ������ ����� �ȵ�.


// �׷��� using ���� �������� ��� ������?
template<typename T>
struct List4
{
	typedef list<T> myType;
};


int main()
{
	id playerId = 0;

	List<int> li;

	li.push_back(1);
	li.push_back(2);
	li.push_back(3);

	List4<int>::myType li2;

	// typedef�� using�� ���ؼ� ������ ����!!


	return 0;
}