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

	m.find(10000);

	return 0;
}