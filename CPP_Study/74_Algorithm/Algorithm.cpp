#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<deque>
using namespace std;

// 오늘의 주제 : 알고리즘

int main()
{
	// 자료구조 (데이터를 저장하는 구조)
	// 알고리즘 (데이터를 어떻게 사용할 것인가?)

	// 현업에서 자주사용하는것 위주
	// 코드의 간결성에 있어서 훨씬 많은 장점이 있다.
	// find
	// find_if
	// count
	// count_if
	// all_of
	// any_of
	// none_of
	// for_each
	// remove
	// remove_if





	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// Q1) number라는 숫자가 벡터에 체크하는 기능 (bool, 첫 등장 iterator)
	{
		int number = 50;
		bool found = false;

		vector<int>::iterator itFind = find(v.begin(), v.end(), number);// v.begin() 포함, v.end() 미포함
		//find는 list에서도 잘 동작한다.
		if (itFind == v.end())
			cout << "못찾았음" << endl;
		else
			cout << "찾았음" << endl;

	}


	// Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능 (bool, 첫 등장 iterator)
	{
		struct CanDivideBy11
		{
			bool operator()(int n)// operator 오버로딩해준다.
			{
				return (n % 11) == 0;
			}
		};

		// 3번째 인자는 조건을 넣어준다(Pred) prdicate
		vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivideBy11());// 1. 함수객체
		//vector<int>::iterator itFind = find_if(v.begin(), v.end(), [](int n){return (n%11)==0;});// 2. 람다 사용
			//3번째 인자에  1. 함수 객체, 2. 람다 문법 사용할 수 있다.

		if (itFind == v.end())
			cout << "못찾았음" << endl;
		else
			cout << "찾았음" << endl;

	}


	// Q3) 홀수인 숫자의 개수는? (count)
	{
		struct IsOdd
		{
			bool operator ()(int n)
			{
				return (n % 2) != 0;
			}
		};

		int n = count_if(v.begin(), v.end(), IsOdd());

		// 모든 데이터가 조건을 만족하냐?
		// 모든 데이터가 홀수냐?
		bool b1 = all_of(v.begin(), v.end(), IsOdd());
		// 홀수인 데이터가 하나라도 있습니까?
		bool b2 = any_of(v.begin(), v.end(), IsOdd());
		// 모든 데이터가 홀수가 아닙니까?
		bool b3 = none_of(v.begin(), v.end(), IsOdd());
	}


	// Q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱해주세요!
	{
		struct MultiplyBy3
		{
			void operator()(int& n)
			{
				n = n * 3;
			}
		};

		for_each(v.begin(), v.end(), MultiplyBy3());

	}

	// remove, remove_if : 살짝 묘하게 동작함.
	// 홀수인 데이터를 일괄 삭제
	{
		//for (vector<int>::iterator it = v.begin(); it != v.end();)// data를 건드릴때, for 안에서 it를 ++ 해주는것 보다. 아래에서 증가시켜주는게 좋다. --> 더 깔끔해진다.
		//{
		//	if ((*it % 2) != 0)
		//	{
		//		it = v.erase(it);
		//	}
		//	else
		//	{
		//		++it;
		//	}
		//}//이터레이터로 루프를 돌때, 벡터 자체를 건드리는 행위는 굉장히 위험하다. ---> 이 부분에서 버그가 많이 발생함.

		v.clear();
		v.push_back(1);
		v.push_back(4);
		v.push_back(3);
		v.push_back(1);
		v.push_back(5);
		v.push_back(8);
		v.push_back(2);

		// 4를 삭제
		remove(v.begin(), v.end(), 4);

		//
		struct IsOdd
		{
			bool operator ()(int n)
			{
				return (n % 2) != 0;
			}
		};

		// 1 4 3 5 8 2
		// 4 8 2 5 8 2 ??? 왜 이렇게 된걸까?
		/*
		* 출처 : https://en.cppreference.com/w/cpp/algorithm/remove
template<class ForwardIt, class UnaryPredicate>
ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = std::find_if(first, last, p);
    if (first != last)
        for (ForwardIt i = first; ++i != last;)
            if (!p(*i)) // 남겨줘야할 원소들
                *first++ = std::move(*i);//남겨줘야하는 애들 복사해서 바꿔치기
    return first;// [4 8 2 ]       [5 8 2 ]-> 필요한 데이터를 모아놓고 그 다음에 나머지 쓰레기 값들 (더 이상 사용하지 않아서 날려도 되는)의 첫 위치를 반환해줌.
	!! 이 부분을 주의할것
}
		데이터를 찾자마자 애를 삭제하고 찾자마자 삭제하고 이런 식으로 동작한다고 하면은 삭제를한 다음에
		모든 데이터들을 한 칸씩 당겨줘야 되는 그런 매우 비효율적인 동작이 일어남.
		그래서 remove_if는 불필요한 데이터를 삭제하는게 아니라 필요한 데이터만 남겨두는 쪽에 가깝게 동작을 하고 있다.
		*/


		vector<int>::iterator it = remove_if(v.begin(), v.end(), IsOdd());
		v.erase(it, v.end());// 이렇게 해야[ 5 8 2 ]가 날라감.!!!
		//v.erase(remove_if(v.begin(), v.end(), IsOdd()), v.end());// 한줄로 처리하기 ---> 이걸 많이 사용한다고 함.!


		// remove를 사용할 때는 항상 이 vector 기준으로 보면 erase가 같이 사용한다.



	}


	// 결론
	// 알고리즘 시리즈들이 익숙해지면 훨씬 더 코드 가독성이 높아지고, 코드의 재사용성도 높아진다.
	// 

	return 0;
}