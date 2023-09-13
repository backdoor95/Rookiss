#include<iostream>
using namespace std;
#include<iomanip> // manipulate : �����ϴ�. --> input output�� ���� |  setfill('0') , setw(2)
// ������ ���� : ��������
// ������ ������� ���ڸ� �׸����̴�.
// --> �ҿ뵹�� ���

const int MAX = 100;
int N;// �̷� ���� ������ �������� �����ص���.
int board[MAX][MAX] = {};// �迭�� ũ��� const�� �־������.

enum Direction
{
	D_Right=0,
	D_Left=1,
	D_Up=2,
	D_Down=3
};
void PrintBoard()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";// setfill('0') : 0���� ä���ٰ��̴�. | setw(2) : 2 �ڸ��� ����
		}
		cout << endl;
	}
}
// �� Ǯ��
void SetBoardByMun()
{
	// 01 02 03 04 05 
	// 16 17 18 19 06
	// 15 24 25 20 07
	// 14 23 22 21 08
	// 13 12 11 10 09
	int x = 0;
	int y = 0;
	int X = N;
	int Y = N;
	int count = 1;
	int flag=0;

	while (count<=(N*N))
	{

		if (flag == D_Right)
		{
			for (int i = 0; i < X - 1; i++)
			{
				board[y][x++] = count++;
			}
			board[y][x] = count++;
			y++;
			Y--;
			flag = D_Down;
			continue;
		}
		if (flag == D_Down)
		{
			for (int i = 0; i < Y - 1; i++)
			{
				board[y++][x] = count++;
			}
			board[y][x] = count++;
			x--;
			X--;
			flag = D_Left;
			continue;
		}
		if (flag == D_Left)
		{
			for (int i = 0; i < X - 1; i++)
			{
				board[y][x--] = count++;
			}
			board[y][x] = count++;
			y--;
			Y--;
			flag = D_Up;
			continue;
		}
		if (flag == D_Up)
		{
			for (int i = 0; i < Y - 1; i++)
			{
				board[y--][x] = count++;
			}
			board[y][x] = count++;
			x++;
			X--;
			flag = D_Right;
			continue;
		}

		//PrintBoard();
		cout << endl << endl;
	}

}

// ROOKISS Ǯ��
enum DIR
{
	RIGHT =0,
	DOWN=1,
	LEFT=2,
	UP=3
};

bool CanGo(int y, int x)
{
	if (y < 0 || y >= N)
		return false;
	if (x < 0 || x >= N)
		return false;
	if (board[y][x] != 0)
		return false;
	return true;
}
// ver 1.0 -- �������� Ǯ��
void SetBoard()
{
	int dir = RIGHT;
	
	int num = 1;
	int y = 0;
	int x = 0;

	while (true)
	{
		board[y][x] = num;

		if (num == N * N)
			break;// ���� �κ�

		int nextY;
		int nextX;
		
		switch (dir)
		{
		case RIGHT:
			nextY = y;
			nextX = x + 1;
			break;
		case DOWN:
			nextY = y + 1;
			nextX = x ;
			break;
		case LEFT:
			nextY = y;
			nextX = x - 1;
			break;
		case UP:
			nextY = y - 1;
			nextX = x;
			break;
		}

		if (CanGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
		{
			switch (dir)
			{
			case RIGHT:
				dir = DOWN;
				break;
			case DOWN:
				dir = LEFT;
				break;
			case LEFT:
				dir = UP;
				break;
			case UP:
				dir = RIGHT;
				break;
			}
		}


	}

}

// ver 2.0 -- �ڷᱸ�� �˰����� ������ Ǯ��
void SetBoard2()
{
	int dir = RIGHT;

	int num = 1;
	int y = 0;
	int x = 0;

	// �� �κ��� ������ �ٸ��κ�
	int dy[] = { 0,1,0,-1 };
	int dx[] = { 1,0,-1,0 };

	while (true)
	{
		board[y][x] = num;

		if (num == N * N)
			break;// ���� �κ�

		// �̷��� �ϸ� switch-case �� �Ƚᵵ��.!!!
		int nextY = y + dy[dir];
		int nextX = x + dx[dir];

		
		if (CanGo(nextY, nextX))
		{
			y = nextY;
			x = nextX;
			num++;
		}
		else
		{
			// switch - case �� ��ü
			dir = (dir + 1) % 4;
		}


	}

}

int main()
{
	cin >> N;

	//SetBoardByMun();
	//SetBoard();
	SetBoard2();
	PrintBoard();
	return 0;
}