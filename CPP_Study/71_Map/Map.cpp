#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<map>
using namespace std;

// 오늘의 주제 : map

class Player
{
public:
	Player(): _playerId(0){ }
	Player(int playerId): _playerId(playerId){ }


public:
	int _playerId;
};
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	// 연관 컨테이너
	// map은 시퀀스가 아니라 연관 컨테이너임.

	vector<Player*>	 v;

	// 10만명 입장
	for (int i = 0; i < 100000; i++)
	{
		Player* p = new Player(i);
		v.push_back(p);
	}

	// 5만명이 퇴장
	for (int i = 0; i < 50000; i++)
	{
		int randIndex = rand() % v.size();

		Player* p = v[randIndex];
		delete p;
		v.erase(v.begin() + randIndex);
	}

	// (ID = 2만 플에이어)가 (ID = 1만 Player)를 공격하고 싶어요
	// Q) ID = 1만인 Player를 찾아주세요!
	// A) 찾아본다

	bool found = false;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->_playerId == 10000)
		{
			found = true;
			break;
		}
	}

	// 벡터 자체는 데이터를 관리하고 편리하게 관리할 수 있다는 장점이 있지만
	// 결국 벡터나 리스트 같은 선형 자료 구조의 가장 큰 단점은 데이터를 빠르게 찾을수 있는 마땅한 방법이 없다.


	// vector, list의 치명적인 단점
	// -> 원하는 조건에 해당하는 데이터를 빠르게 찾을 수 [없다]


	// 연관 컨테이너 : 데이터가 실질적으로 갖고 있는 값에 따라 가지고 뭔가를 저장하는 형태로 동작한다.

	// map : 균형 이진 트리 (AVL)
	// - 노드 기반

	class Node
	{
	public:
		Node* _left;
		Node* _right;
		//DATA
		//int		_key;
		//Player* _value;
		pair<int, Player*> _data;
	};

	// (Key, Value)
	map<int, int> m;

	pair<map<int, int>::iterator, bool> ok;
	ok = m.insert(make_pair(1, 100));
	ok = m.insert(make_pair(1, 200));// 같은 key 값, 다른 value ---> 이미 값이 들어갔으면 이건 안들어감.(덮어써지는게 아니라, 무시됨)
	
	ok.first;// 왼쪽
	ok.second;//오른쪽

	// 10만명
	for (int i = 0; i < 100000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5만명 퇴장
	for (int i = 0; i < 50000; i++)
	{
		int randomValue = rand() % 50000;

		// Erase By Key
		m.erase(randomValue);// erase에 4가지 버전이 있음, 키 값을 넣어서
	}

	// Q) ID = 1만인 Player 찾고 싶다!
	// A) 매우 빠르게 찾을 수 있음.
	unsigned int count = 0;
	count = m.erase(10000);// 삭제되면 1반환
	count = m.erase(10000);// 삭제 안되면 0반환

	//map<int,int>::iterator findIt = m.find(10000);// map의 이터레이터를 뱉어줌.
	//// map에 들어가있는 경우
	//if (findIt != m.end())
	//{
	//	cout << "찾음" << endl;
	//}
	//else
	//{
	//	cout << "못찾음" << endl;
	//}


	// map 순회
	for (map<int,int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		pair<const int, int>& p = *it;
		int key = p.first; // 방식 1
		int key2 = it->first;// 방식 2
		int value = p.second;
		int value2 = it->second;
		cout << key << " " << value << endl;
		cout << key2 << " " << value2 << endl;
	}

	// 없으면 추가, 있으면 수정- ver 1.0
	map<int, int>::iterator findIt = m.find(10000);// map의 이터레이터를 뱉어줌.
	// map에 들어가있는 경우
	if (findIt != m.end())
	{
		findIt->second = 200;
	}
	else
	{
		m.insert(make_pair(10000, 200));
	}

	// 없으면 추가, 있으면 수정 - ver 2.0
	m[5] = 500; // 1. 5라는 key값이 없으면, 그 키값을 추가한 다음 500을 넣음.| 2. 5라는 key값이 있으면, value를 500으로 수정

	m.clear();
	// [] 연산자 사용할 때 주의
	// 대입을 하지 않더라도 (key/value) 형태의 데이터가 추가된다!
	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;
		//  [] 연산자 자체가 없음면 추가한다는 기본적인 기능을 가지고 있기 때문에
		// 없으면 새로운 노드를 추가하고 그 기본값을 여기서 int의 기본값인 0으로 세팅해준다.
		// 값이 있는지 여부를 판단할때는 find를 사용하자.!

	}

	// 넣고		(insert, [])
	// 빼고		(erase)
	// 찾고		(find, [])
	// 반복자	(map::iterator) (*it) pair<key,value>&

	//map은 벡터와 다르게 연속해서 저장하는 개념이 아니다.
	//따라서 중간에 있는 데이터를 삭제, 추가할때 빠르게 트리가 재구성 --> 효율적으로 동작!

	return 0;
}