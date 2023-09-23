#include<iostream>
#include<vector>
using namespace std;

// 오늘의 주제 : vector01

int main()
{
	// 면접에서 vector를 자주 물어봄
	// STL = Standard Template Library
	// 프로그래밍할 때 필요한 자료구조/알고리즘들을
	// 템플릿으로 제공하는 라이브러리

	// 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// Vector 의 모든 기능을 학습하는건 불가능!
	// 원리에 대해서 알아볼것이다.
	// 
	// vector(동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝, 삽입/삭제
	// - 임의 접근

	// 배열
	// 배열만으로는 게임을 구성하기 어렵다.
	const int MAX_SIZE = 10;
	int arr[MAX_SIZE] = { };

	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i] << endl;
	}

	// 동적 배열
	// vector는 템플릿으로 만들어져 있다.
	// 템플릿 클래스이다. 
	// 고무줄처럼 사이즈가 늘어났다 줄어들어다함.
	// 매우 매우 중요한 개념 -> 어떤 마법을 부렸길래 배열을 '유동적으로' 사용한 것인가?

	// 1) (여유분을 두고) 메모리를 할당한다.
	// 2) 여유분까지 꽉 찼으면, 메모리를 증설한다.
	// 예시
	int arr1[100];
	int* arr2 = new int[100];
	delete arr2;
	arr2 = new int[1000];
	// Q1) 여유분은 얼만큼이 적당할까?
	// Q2) 증설을 얼만큼 해야 할까?
	// Q3) 기존의 데이터를 어떻게 처리할까?

/*
	vector<int> v; 
	v.push_back(1);// 밀어넣어줌
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	// TMI : if		|	while	|	for		| do-while---> Tab 키 누르면 자동완성

	int vectorSize = v.size();

	for (int i = 0; i < vectorSize; i++)
	{
		cout << v[i] << endl;
	}
*/


	vector<int> v;

	cout << v.size() << " " << v.capacity() << endl; // 초반에는 0 0 이다.

	// size : 실제 사용 데이터 개수
	// 1 2 3 4 5 6....
	// capacity : 여유분을 포함한 용량 개수
	// 1 2 3 4 5 9 13 19 28 42 63---> 보통 1.5배씩 늘림. (이사 비용(복사 비용)을 절약하기 위해서)



	v.resize(1000);// vector의 size를 강제로 지정
	vector<int> v2(1000);// 이렇게 resize 할수도 있다.

	vector<int> v3(1000, 0);// 이렇게 resize 할수도 있다. 그리고 0 으로 초기화. 원하는 값으로 초기화 할 수 있다.
	
	vector<int> v4 = v;// v를 v4에 복사를 한다.

	cout << "v2 size and capacity" << endl;
	cout << v2.size() << " " << v2.capacity() << endl; // resize 를 하면, 자동으로capacity가 늘어남.


	v.reserve(1000); // 처음부터 capacity가 1000으로 시작.!

	cout << v.size() << " " << v.capacity() << endl; // resize 를 하면, 자동으로capacity가 늘어남.
	
	for (int i = 0; i < 1000; i++)
	{
		// v[i] = 100;// 이미resize된 부분에서 값을 수정하기
		v.push_back(100);// 만약에 resize(1000)을 했으면 1001번째에 들어가게된다.
		cout << v.size() << " " << v.capacity() << endl;
	}

	// size가 줄어들더라도 capacity는 줄어들지 않는다.

	//v.clear();// data 날리기 --> size 가 0이 됨
	
	// 만약에 capacity까지 줄여주고 싶으면?
	v.clear();
	//vector<int> v2 = v;


	vector<int>().swap(v);// 깡통벡터하고 v 랑 swap함.
	// vector<int>() : 이거는 임시벡터임. 여기에는 아무런 정보도 없음. 임시 벡터이므로 이줄이 끝나면 소멸된다.
	cout << v.size() << " " << v.capacity() << endl;
	//cout << v2.size() << " " << v2.capacity() << endl;

	/*************************************/
	v.front();
	v.back();

	v.pop_back();// 마지막에 있던 데이터를 빼낸다.
	/****************************************/


	/*
	C++ STL(Standard Template Library)에서 back()과 pop_back()은 둘 다 시퀀스 컨테이너인 std::vector, std::deque, std::list 등에서 사용할 수 있는 멤버 함수입니다. 그러나 그들의 역할과 동작은 다릅니다.

back():

back() 함수는 컨테이너의 마지막 요소에 접근하여 그 값을 반환합니다.
컨테이너의 마지막 요소를 변경하지 않으며, 컨테이너를 수정하지 않습니다.
예를 들어, std::vector<int> myVector = {1, 2, 3};가 있다면, myVector.back()은 3을 반환합니다.
pop_back():

pop_back() 함수는 컨테이너의 마지막 요소를 제거합니다.
컨테이너의 크기를 하나 줄이고, 마지막 요소가 삭제됩니다.
예를 들어, std::vector<int> myVector = {1, 2, 3};가 있다면, myVector.pop_back()을 호출하면 myVector는 이제 {1, 2}가 됩니다.
간단히 말하면, back()은 마지막 요소의 값을 읽을 때 사용하고, pop_back()은 마지막 요소를 삭제할 때 사용합니다. 이 두 함수는 주로 시퀀스 컨테이너에서 작업을 수행할 때 유용합니다.
	
	*/


	return 0;
}