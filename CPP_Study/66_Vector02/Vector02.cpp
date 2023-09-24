#include<iostream>
using namespace std;
#include<vector>
// 오늘의 주제 :Vector02


int main()
{
	//컨테이너 (Container) : 데이터를 저장하는 객체(자료구조 Data Structure)
	// vector(동적 배열)
	// - vector의 동작원리(size/capacity)
	// - 중간 삽입/ 삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근


	// 컨테이너 마다 반복자를 들고있다.
	// 반복자(iterator) : 포인터와 유사한 개념. 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로 이동 가능
	vector<int> v(10);//size 10개

	for (int i = 0; i < v.size(); i++) // 여기서 경고가 뜸!
	{
		v[i] = i;
	}

	// 해결법 1. 
	for (int i = 0; i < static_cast<unsigned int>(v.size()); i++)
	{
		v[i] = i;
	}

	// 해결법 2.
	// size_type을 정해주면 알맞은 타입을 맞춰준다.
	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		v[i] = i;
	}

	// using 은 typedef과 유사한 기능을 하는 놈이다. c++11 에서 나옴.
	// 포인터와 이터레이터 비교
	// 온갖 컨테이너들이 자신만의 이터레이터를 가지고 있다.
	vector<int>::iterator it;
	int* ptr;

	// 벡터도 내부적으로 배열로 구성됨.

	it = v.begin();// 벡터의 이터레이터를 반환
	ptr = &v[0];

	// 포인터는 말 그대로 주인님이 딱히 없음.
	// 이터레이터는 누구에 소속된 그런 이터레이터다 라는 차이가 있다.

	// 이터레이터를 포인터 마냥 사용가능함. 이터레이터가 내부적으로 포인터를 들고 있음.

	cout << *it << endl;
	cout << *ptr << endl;

	it++;// 다음 데이터로 이동하라는 의미
	++it;

	ptr++;//다음 데이터로 이동하라는 의미
	++ptr;

	it--;
	--it;
	ptr--;
	--ptr;// 뒤로가기

	it += 2;// 다음다음 데이터로 이동
	it = it - 2;// 뒤로뒤로 이동

	ptr += 2;
	ptr = ptr - 2;


	vector<int>::iterator itBegin = v.begin(); // 처음값
	vector<int>::iterator itEnd = v.end(); // 여기에는 해당 배열의 마지막 다음값이 들어있다. 즉, 쓰레기값이 들어있다.


	// vector<int>::iterator 나중에  auto로 바꿀수 있다.!!!
	// 더 복잡해 보이는데 왜 이걸쓸까?
	// iterator는 vector뿐 아니라, 다른 컨테이너에도 공통적으로 있는 개념
	// STL 한정해서 통일성이 생기기 때문에 다른 자료구조로 다른 컨테이너로 넘어가기 굉장히 수월해짐.
	// cf) 다른 컨테이너는 v[i]와 같은 인덱스 접근이 안 될 수도 있음.
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)// ++it 가 it++ 보다 살짝 빠름
	{
		cout << (*it) << endl;
	}
	/*
	    _CONSTEXPR20 _Vector_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _CONSTEXPR20 _Vector_iterator operator++(int) noexcept {
        _Vector_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }
	
	*/

	int* ptrBegin = &v[0];// v.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10;// v.end()._Ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ptr++)
	{
		cout << *ptr << endl;
	}


	// const int* ;
	// 데이터를 수정하지 않고, 읽기만 가능
	vector<int>::const_iterator cit1 = v.cbegin();
	// *cit1=100;// 이거 안됨.

	// 역방향 반복자
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	{
		cout << *it << endl;
	}


	return 0;
}