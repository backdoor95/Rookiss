#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<map>
using namespace std;

// ������ ���� : map

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

	// ���� �����̳�
	// map�� �������� �ƴ϶� ���� �����̳���.

	vector<Player*>	 v;

	// 10���� ����
	for (int i = 0; i < 100000; i++)
	{
		Player* p = new Player(i);
		v.push_back(p);
	}

	// 5������ ����
	for (int i = 0; i < 50000; i++)
	{
		int randIndex = rand() % v.size();

		Player* p = v[randIndex];
		delete p;
		v.erase(v.begin() + randIndex);
	}

	// (ID = 2�� �ÿ��̾�)�� (ID = 1�� Player)�� �����ϰ� �;��
	// Q) ID = 1���� Player�� ã���ּ���!
	// A) ã�ƺ���

	bool found = false;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->_playerId == 10000)
		{
			found = true;
			break;
		}
	}

	// ���� ��ü�� �����͸� �����ϰ� ���ϰ� ������ �� �ִٴ� ������ ������
	// �ᱹ ���ͳ� ����Ʈ ���� ���� �ڷ� ������ ���� ū ������ �����͸� ������ ã���� �ִ� ������ ����� ����.


	// vector, list�� ġ������ ����
	// -> ���ϴ� ���ǿ� �ش��ϴ� �����͸� ������ ã�� �� [����]


	// ���� �����̳� : �����Ͱ� ���������� ���� �ִ� ���� ���� ������ ������ �����ϴ� ���·� �����Ѵ�.

	// map : ���� ���� Ʈ�� (AVL)
	// - ��� ���

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

	// 5���� ����
	for (int i = 0; i < 50000; i++)
	{
		int randomValue = rand() % 50000;

		// Erase By Key
		m.erase(randomValue);// erase�� 4���� ������ ����, Ű ���� �־
	}

	// Q) ID = 1���� Player ã�� �ʹ�!
	// A) �ſ� ������ ã�� �� ����.

	m.find(10000);

	return 0;
}