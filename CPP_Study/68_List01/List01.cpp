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
// [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [6] <->[_Myhead : end()] <-> // 더미노드

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
	// - 중간 삽입/삭제 (GOOD/GOOD)
	// - 처음/끝 삽입/삭제 (GOOD/GOOD)
	// - 임의 접근 --> 리스트에서는 느리기 때문에 임의접근을 막아둠!

	list<int> li;
	for (int i = 0; i < 100; i++)
	{
		li.push_back(i+1);
	}

	//li.push_front(10);// List에는 push_front가 있다.
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

	list<int>::iterator itTest1 = --itBegin;// 안됨
	list<int>::iterator itTest2 = --itEnd;// 됨
	list<int>::iterator itTest3 = ++itBegin;// 안됨.
	// 더미 노드를 만들어놓은 것은 잘못된 이동을 방지하지 위함!

	//list<int>::iterator it2 = itBegin + 10; // 벡터는 산술적으로 빠르게 연산가능하나, list에서는 주소를 타고 넘어가야하기 때문에 비효율적이여서 문법적으로 막아둠.
	



	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());

	// 리스트 이터레이터에는 해당 노드의 포인터를 들고 있다.!!

	for (list<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << *it << endl;
	}

	//li.insert(itBegin, 100);// 첫 위치에 100 삽입
	//li.erase(li.begin());// 첫번째 위치 data 삭제
	//li.pop_front();// 첫번째 위치 data 삭제
	//li.remove(10);// vector에는 remove가 없다!! list는 remove가 있다. ---> value가 10인 원소를 삭제!!!

	////////////////////////////////////////////////////////////////////

	// * 임의 접근이 안 된다! -- 1
	// * 그런데 중간 삽입/삭제가 빠르다? -- 2
	// ex) 50번째 데이터를 삭제하고 싶다!!

	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50; i++)// 1
	{
		++it;
	}
	//li.erase(it + 50);// 이게 안됨!!
	li.erase(it);// 이렇게 해야함.// 2

	// 결론 : 1, 2를 분리해서 봐야한다.

	list<int> li2;

	list<int>::iterator itRemember;

	for (int i = 0; i < 100; i++) // 3.
	{
		if (i == 50)
		{
			itRemember = li2.insert(li2.end(), i);// insert를 하면 insert한 위치를 반환해준다.
		}
		else
		{
			li2.push_back(i);
		}
	}

	li2.erase(itRemember);// 3방식: 해당 이터레이터를 기억을 해두었다가 이렇게 사용할수도 있다.


	////////////////////////////////////////////////////////////////////
	return 0;
}