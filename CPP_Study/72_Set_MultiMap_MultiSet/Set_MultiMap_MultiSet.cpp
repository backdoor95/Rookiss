#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>
using namespace std;

// 연관 컨테이너
// 오늘의 주제 : set, multimap, multiset  -- map과 비슷

int main()
{
	//key, value(data)
	// 만약에 data를 key로 사용하고 싶을때
	// key만 단독적으로 사용 -> set (key = value)
	set<int> s;

	// 넣고
	// 빼고
	// 찾고
	// 순회

	//넣고
	s.insert(10);
	s.insert(30);
	s.insert(20);
	s.insert(50);
	s.insert(40);
	s.insert(70);
	s.insert(90);
	s.insert(80);
	s.insert(100);

	//빼고
	s.erase(40);

	// set는 map이랑 다 똑같음 단지 key = value일뿐

	//찾고
	set<int>::iterator findIt = s.find(50);
	if (findIt == s.end())
	{
		cout << "못 찾음" << endl;
	}
	else
	{
		cout << "찾음" << endl;
	}

	// 순회하고
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << endl;
	}

	// s[5] =50;// 이 문법은 막혀있다.
	cout << "--------------------------------------------" << endl;

	// multimap : map에서 중복키를 허용하는게 multimap
	// multiset : set에서 중복키를 허용하는게 multiset
	// multimap, multiset은 자주 안쓰임.

	multimap<int, int> mm;
	
	//넣고
	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(2, 400));
	mm.insert(make_pair(1, 200));
	mm.insert(make_pair(2, 500));
	mm.insert(make_pair(1, 300));

	//mm[1] = 500;// 막혀있음. insert로 넣어야함.

	//빼고
	//unsigned int count = mm.erase(1);// key =1 인것들 전부 삭제--> count = 3

	//찾고
	//multimap<int,int>::iterator itFind = mm.find(1);// 모든 값을 삭제하는게 아니라 하나만 삭제하고 싶을때, 첫번째로 만난놈만 반환함.
	//// key가 1인놈을 모두 반환하는건 아님.
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

	//넣고
	ms.insert(100);
	ms.insert(100);
	ms.insert(100);
	ms.insert(200);
	ms.insert(200);

	// 찾고

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
	

	// 결론 실무에서는 multimap, multiset를 거의 쓰지 않음.
	// set는 가끔 필요할때가 있음.

	// map, set, multimap, multiset에 대해서 어느정도는 숙지를 하자!
	return 0;
}