#include<iostream>
#include"Game.h"

// " ", < > ������
// ["" : Ŀ���� ���̺귯�� ],[ <>: c++ ���� ���̺귯��]



using namespace std;


// ������ ���� : TextRPG #4
// .cpp , .h ���� ���� ����¹� -> 1. ���� ��Ŭ�� 2. �߰� Ŭ�� 3. Ŭ���� Ŭ��
// C++�� �ַ�� Ž���⿡�� ������ ������ �Ǵ°� ó�� ��������, �����δ� �׳� ������ ��ġ�� ���ִ�.--> Creature, Game ������ �������� ���� �����̴�.

// ��� ������ ����� ���õ� �ֵ��� ��Ƶδ°�
// cpp ���Ͽ����� ���漱�� x -> �Ƚ��ϰ� include�� �÷��൵��.

int main()
{
	srand((unsigned int)time(nullptr));
	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}


	return 0;
}