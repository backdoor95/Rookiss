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
	srand(static_cast<unsigned int>(time(nullptr)));
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

	pair<map<int, int>::iterator, bool> ok;
	ok = m.insert(make_pair(1, 100));
	ok = m.insert(make_pair(1, 200));// ���� key ��, �ٸ� value ---> �̹� ���� ������ �̰� �ȵ�.(��������°� �ƴ϶�, ���õ�)
	
	ok.first;// ����
	ok.second;//������

	// 10����
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
	unsigned int count = 0;
	count = m.erase(10000);// �����Ǹ� 1��ȯ
	count = m.erase(10000);// ���� �ȵǸ� 0��ȯ

	//map<int,int>::iterator findIt = m.find(10000);// map�� ���ͷ����͸� �����.
	//// map�� ���ִ� ���
	//if (findIt != m.end())
	//{
	//	cout << "ã��" << endl;
	//}
	//else
	//{
	//	cout << "��ã��" << endl;
	//}


	// map ��ȸ
	for (map<int,int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		pair<const int, int>& p = *it;
		int key = p.first; // ��� 1
		int key2 = it->first;// ��� 2
		int value = p.second;
		int value2 = it->second;
		cout << key << " " << value << endl;
		cout << key2 << " " << value2 << endl;
	}

	// ������ �߰�, ������ ����- ver 1.0
	map<int, int>::iterator findIt = m.find(10000);// map�� ���ͷ����͸� �����.
	// map�� ���ִ� ���
	if (findIt != m.end())
	{
		findIt->second = 200;
	}
	else
	{
		m.insert(make_pair(10000, 200));
	}

	// ������ �߰�, ������ ���� - ver 2.0
	m[5] = 500; // 1. 5��� key���� ������, �� Ű���� �߰��� ���� 500�� ����.| 2. 5��� key���� ������, value�� 500���� ����

	m.clear();
	// [] ������ ����� �� ����
	// ������ ���� �ʴ��� (key/value) ������ �����Ͱ� �߰��ȴ�!
	for (int i = 0; i < 10; i++)
	{
		cout << m[i] << endl;
		//  [] ������ ��ü�� ������ �߰��Ѵٴ� �⺻���� ����� ������ �ֱ� ������
		// ������ ���ο� ��带 �߰��ϰ� �� �⺻���� ���⼭ int�� �⺻���� 0���� �������ش�.
		// ���� �ִ��� ���θ� �Ǵ��Ҷ��� find�� �������.!

	}

	// �ְ�		(insert, [])
	// ����		(erase)
	// ã��		(find, [])
	// �ݺ���	(map::iterator) (*it) pair<key,value>&

	//map�� ���Ϳ� �ٸ��� �����ؼ� �����ϴ� ������ �ƴϴ�.
	//���� �߰��� �ִ� �����͸� ����, �߰��Ҷ� ������ Ʈ���� �籸�� --> ȿ�������� ����!

	return 0;
}