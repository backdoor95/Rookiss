#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<map>
using namespace std;

//오늘의 주제 : auto

class Knight
{
public:
	int _hp;
};

template<typename T>
void Print(T t)
{
	cout << t << endl;
}

int main()
{
	// Modern C++(C++11)

	//int a = 3;
	//float b = 3.14f;
	//double c = 1.23;
	//Knight d = Knight();
	//const char* e = "rookiss";

	auto a = 3;
	auto b = 3.14f;
	auto c = 1.23;
	auto d = Knight();
	auto e = "rookiss";

	// auto는 일종의 조커카드
	// 형식 연역 (type deduction) : 타입 추론
	// -> 말이 되게 잘 맞춰봐~(추론)
	// 추론 규칙은 생각보다 복잡 --> 이건 나중에 실력이 쌓이면 알아봐라

	//auto f = &d;
	//const auto test1 = b;// const float으로 받음
	//auto* test2 = e;
	//
	
	//주의 !
	// 기본 auto는 const, & 무시!!!!!!!!!!!!!!!!!!
	int& reference = a;
	const int cst = a;

	auto test1 = reference;// 여기서 auto는 int
	auto test2 = cst;// 여기서 auto는 int


	// rookiss가 했던 실수
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		auto data = v[i];// int& data = v[i]인줄 알았는데, 아래 방식으로 작동함.
		//int data = v[i]; 복사해서 data에 집어넣는것임.!! 참조를 유지못함.
		// 해결법
		auto& data2 = v[i]; // 레퍼런스를 똑같이 참조를 유지하고 싶으면, auto에 힌트를 줘야함.
		// 이 오른쪽에 있는 참조 자체는 유지해야한다고 힌트를 줘야함.
	}

	// 아무튼 이제 기존의 타입은 잊어버리고 auto만 사용할래요~~
	// Rookiss 주관적인 생각 == NO! ---> 가독성에서 손해가 나기 때문
	// -> 타이핑이 길어지는 경우 OK
	// -> 가독성을 위해 일반적으로는 놔두는게 좋다.


	map<int, int> m;
	auto ok = m.insert(make_pair(1, 100));

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}


	return 0;
}