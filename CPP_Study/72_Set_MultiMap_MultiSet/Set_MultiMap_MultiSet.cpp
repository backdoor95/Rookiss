#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>
using namespace std;

// ���� �����̳�
// ������ ���� : set, multimap, multiset  -- map�� ���

int main()
{
	//key, value(data)
	// ���࿡ data�� key�� ����ϰ� ������
	// key�� �ܵ������� ��� -> set (key = value)
	set<int> s;

	// �ְ�
	// ����
	// ã��
	// ��ȸ

	//�ְ�
	s.insert(10);
	s.insert(30);
	s.insert(20);
	s.insert(50);
	s.insert(40);
	s.insert(70);
	s.insert(90);
	s.insert(80);
	s.insert(100);

	//����
	s.erase(40);

	// set�� map�̶� �� �Ȱ��� ���� key = value�ϻ�

	//ã��
	set<int>::iterator findIt = s.find(50);
	if (findIt == s.end())
	{
		cout << "�� ã��" << endl;
	}
	else
	{
		cout << "ã��" << endl;
	}

	// ��ȸ�ϰ�
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << endl;
	}

	// s[5] =50;// �� ������ �����ִ�.
	cout << "--------------------------------------------" << endl;

	// multimap : map���� �ߺ�Ű�� ����ϴ°� multimap
	// multiset : set���� �ߺ�Ű�� ����ϴ°� multiset
	// multimap, multiset�� ���� �Ⱦ���.

	multimap<int, int> mm;
	
	//�ְ�
	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(2, 400));
	mm.insert(make_pair(1, 200));
	mm.insert(make_pair(2, 500));
	mm.insert(make_pair(1, 300));

	//mm[1] = 500;// ��������. insert�� �־����.

	//����
	//unsigned int count = mm.erase(1);// key =1 �ΰ͵� ���� ����--> count = 3

	//ã��
	//multimap<int,int>::iterator itFind = mm.find(1);// ��� ���� �����ϴ°� �ƴ϶� �ϳ��� �����ϰ� ������, ù��°�� ������ ��ȯ��.
	//// key�� 1�γ��� ��� ��ȯ�ϴ°� �ƴ�.
	//if (itFind != mm.end())
	//	mm.erase(itFind);

	// ver 1.0
	pair < multimap<int, int>:: iterator, multimap<int, int>::iterator > itPair;
	itPair = mm.equal_range(1);

	for (multimap<int,int>::iterator it = itPair.first; it != itPair.second; ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	// ver 2.0
	multimap<int,int>::iterator itBegin = mm.lower_bound(1);
	multimap<int,int>::iterator itEnd = mm.upper_bound(1);

	for (multimap<int, int>::iterator it = itBegin; it != itEnd; ++it)
	{
		cout << it->first << " " << it->second << endl;
	}


	cout << "--------------------------------------------" << endl;
	// multiset?
	multiset<int> ms;

	//�ְ�
	ms.insert(100);
	ms.insert(100);
	ms.insert(100);
	ms.insert(200);
	ms.insert(200);

	// ã��

	// ver 1.0
	multiset<int>::iterator findIt2 = ms.find(100);

	pair < multiset<int>::iterator, multiset<int>::iterator > itPair2;
	itPair2 = ms.equal_range(100);

	for (multiset<int>::iterator it = itPair2.first; it != itPair2.second; ++it)
	{
		cout << *it << endl;
	}

	cout << "--------------------------------------------" << endl;

	// ver 2.0
	multiset<int>::iterator itBegin2 = ms.lower_bound(100);
	multiset<int>::iterator itEnd2 = ms.upper_bound(100);

	for (multiset<int>::iterator it = itBegin2; it != itEnd2; ++it)
	{
		cout << *it << endl;
	}
	

	// ��� �ǹ������� multimap, multiset�� ���� ���� ����.
	// set�� ���� �ʿ��Ҷ��� ����.

	// map, set, multimap, multiset�� ���ؼ� ��������� ������ ����!
	return 0;
}