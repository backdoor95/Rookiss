#include<iostream>
using namespace std;

// 오늘의 주제 : 템플릿 기초

// typename T을 붙이면 '조커카드' (어떤 타입도 다 넣을 수 있음)
// 그런데 무조건 typename을 붙여야 하는 것은 아니다
// template< > 안에 들어가는건 [골라줘야 하는 목록]이라고 볼 수 있음

template<typename T, int SIZE>// int SIZE = 10 도 가능---> template<class T, int SIZE> 도 가능
class RandomBox
{
public:
	T GetRandomData()
	{
		int idx = rand() % SIZE;
		return _data[idx];
	}

public:
	T _data[SIZE];
};

// 템플릿 특수화
template<int SIZE>// int SIZE = 10 도 가능
class RandomBox<double, SIZE>
{
public:
	double GetRandomData()
	{
		cout << "RandomBox Double" << endl;
		int idx = rand() % SIZE;
		return _data[idx];
	}

public:
	double _data[SIZE];
};

void Hello(int number)
{

}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	Hello(10);
	Hello(20);

	// 템플릿 : 함수나 클래스를 찍어내는 틀
	// 1) 함수 템플릿
	// 2) 클래스 템플릿

	RandomBox<int,10> rb1;
	for (int i = 0; i < 10; i++)
	{
		rb1._data[i] = i;
	}
	int value1 = rb1.GetRandomData();
	cout << value1 << endl;


	RandomBox<double,20> rb2;
	for (int i = 0; i < 20; i++)
	{
		rb2._data[i] = i + 0.5;
	}
	double value2 = rb2.GetRandomData();
	cout << value2 << endl;

	// rb1, rb2 는 2개가 독립적으로 만들어진다.
	// 타입이 100% 일치할때만!!! rb1 = rb2; 가능함.

	return 0;
}