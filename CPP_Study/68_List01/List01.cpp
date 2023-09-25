#include<iostream>
using namespace std;
#include<vector>
#include<list>

// 오늘의 주제 : list

// vector는 동적배열방식
// List는 node 방식

// vector : 동적배열

// 단일/ 이중 / 원형
// list : 연결리스트

// 노드안에 노드가 아님!

// 건물 설계도를 완성하기 위해서는 건물 설계도를 완성해야함? ====> 말이 안됨.! 따라서 포인터만! 됨.
//class Node2
//{
//public:
//	Node2 _next;
//	int _data;
//};

// [data(4) next(4/8) ] ---> size가 8또는 12로 고정
class Node
{
public:
	Node* _next;// 다음 노드의 주소 
	Node* _prev;// 이중 연결
	int _data;
};
// 우리가 STL 리스트로 사용하게 될 경우에는 이중연결리스트로 만들어져 있다.


int main()
{
	// list (연결 리스트)
	// - list의 동작 원리
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	list<int> li;
	for (int i = 0; i < 100; i++)
	{
		li.push_back(i);
	}

	li.push_front(10);// List에는 push_front가 있다.
	// 벡터에는 push_front가 없다.!
	// 벡터같은 경우 삽입/삭제하는것이 비효율적이기 때문이다.
	// list는 push /front가 어느정도 효율적으로 작동하기 때문.


	int size = li.size();
	//int capacity = li.capacity();// 리스트에는 동적배열의 형태가 아니기 때문에 용량의 개념이 없기 때문에 capacity가 없다.
	
	int first = li.front();
	int last = li.back();// 마지막 데이터 추출 !!  li.end()와 다른거임.!!!

	// [] : list에는 임의접근이 없다!!
	// li[3] = 10;// 없음
	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

	for (list<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << *it << endl;
	}

	li.insert(itBegin, 100);// 첫 위치에 100 삽입
	li.erase(li.begin());// 첫번째 위치 data 삭제
	li.pop_front();// 첫번째 위치 data 삭제
	
	li.remove(10);// vector와 다르게 remove가 있다. ---> value가 10인 원소를 삭제!!!




	return 0;
}