#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<deque>

// 오늘의 주제 : deque

// deque : double ended queue  (vector와 list의 중간 형태) 짬뽕된 형태인데 벡터쪽에 가깝다.
// 뜻 : 양방향으로 큐처럼 사용
// deque도 배열형태, 용량이 다찼을때, 다른영역을 생성함. 근데 기존에 있던걸 삭제하고 복사하는게 아니다. 추가하기위한 영역을 생성
// 통을 하나 만들어서 이어붙인다고 생각하면됨. 
// [		]
// [		]
// [		]
// [		]
// vector와 사용법이 굉장히 유사함.

int main()
{
	// 시퀀스 컨테이너 
	// 데이터가 삽입 순서대로 나열되는 형태
	// vector / list / deque

	deque<int> dq;

	dq.push_back(1);
	dq.push_front(2);
	cout << dq[0] << endl;

	// vector와 마찬가지로 배열 기반으로 동작
	// 다만 메모리 할당 정책이 다르다.

	// vector
	// 이전을 하고 통으로 복붙
	vector<int>v(3, 1);// 크기 3, 1로 초기화
	// [1 1 1]

	//deque : 앞뒤로 통을 늘리수 있다.
	// [    3 3]
	// [1 1 1 2]
	// [2      ]
	deque<int> dq(3, 1);

	v.push_back(2);
	v.push_back(2);

	dq.push_back(2);
	dq.push_back(2);

	dq.push_front(3);
	dq.push_front(3);

	// - deque의 동작 원리
	// - 중간 삽입/삭제 [BAD / BAD] vector와 마찬가지로 한칸씩 땡겨와야함.
	// - 처음/끝 삽입/삭제 [GOOD/GOOD]
	// - 임의 접근 (GOOD)
	// 필연적으로 중간 삽입/삭제가 느린이유는 임의접근을 빠르게 지원하기 위한 조건!!

	dq[3] = 10;
	cout << dq[3] << endl;

	deque<int>::iterator it;

	/*
	    _Size_type _Block = _Mycont->_Getblock(_Myoff);//어떤 블록에 소속이 되어있는지 
        _Size_type _Off   = _Myoff % _Block_size;// offset을 따로 구함.
        return _Mycont->_Map[_Block][_Off];// ex) 몇 동 , 몇 호 ---> 임의접근!
	
	*/
	// list는 임의 접근이 불가!

	// 데크는 양방향으로 사용하는 큐다. 
	// 벡터는 앞에다가 밀어넣는게 매우 느림
	// 데크는 앞에 밀어넣는게 빠름. ---> 양방향으로 빠르게 동작하는게 가능해짐.

	return 0;
}