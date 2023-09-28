#include<iostream>
#include<algorithm>
#include<list>
#include<vector>

// 오늘의 주제 : using 

typedef __int64	id;

using id2 = int;

// 1) 직관성
typedef void (*MyFunc)();

using MyFunc2 = void(*)();// 코드의 가독성이 높아짐

// 2) 템플릿
//typedef은 템플릿을 활용할 수 없다.
//template<typename T>
//typedef void

template<typename T>
using List = std::list<T>;

template<typename T>
using List2 = std::vector<T>;

//template<typename T>
//typedef std::vector<T> List3; // 문법이 통과가 안됨.


// 그러면 using 없던 시절에는 어떻게 했을까?
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

	// typedef은 using에 대해서 장점이 없다!!


	return 0;
}