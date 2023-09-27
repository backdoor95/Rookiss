#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

// 오늘의 주제 : 중괄호 초기화 { }
class Knight
{
public:
	Knight()
	{
		cout << "Knight()" << endl;
	}

	Knight(int a, int b)
	{
		cout << "Knight(int, int)" << endl;
	}

	Knight(initializer_list<int> li)// 우선순위가 제일 높아짐.
	{
		cout << "Knight(initializer_list)" << endl;
	}

};

int main()
{
	// 중괄호 초기화 { }
	int a = 0;
	int b(0);
	int c{ 0 };

	Knight k1;
	Knight k2 = k1;// 복사 생성자 (대입 연산자X)


	Knight k4;// 기본 생성자
	k4 = k1;// 대입 연산자


	Knight k3{ k1 };

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2(10, 1);// 10개를 1로 초기화
	int arr[] = { 1,2,3,4, };

	//C++11

	// 중괄호 초기화
	// 1) vector등 container과 잘 어울린다.
	vector<int> v3{ 1,2,3,4 };// 1,2,3,4를 push_back를 한 것과 같음.

	// 2) 축소 변환 방지
	int x = 0;
	//double y(x);// 에러 발생 안남.
	double y{ x };// 에러 발생


	// 3) Bonus
	Knight k5{ };// 이렇게 하면 기본 생성자 버전으로 생성이된다.

	Knight k6{ 1,2,3,4,5 };//initializer_list생성자 만들어야함.

	Knight k7{ 1,2 };//initializer_list생성자 호출됨. 원래 의도는 정수 2개를 받는 생성자를 호출하려고 했음.

	// 중괄호 초기화의 단점은 "생태 파괴범"--> 모든 생성자를 막아버리는 효과!

	

	// 괄호 초기화 ()를 기본으로 간다-- 대부분!!
	// - 전통적인 C++ (거부감이 없음)
	// - vector 등 특이한 케이스에 대해서만 { } 사용

	// 중괄호 초기화 { }를 기본으로 간다
	// - 초기화 문법의 일치화
	// - 축소 변환 방지

	// 결론 둘중 하나를 정해서 작업할것!

	return 0;
}