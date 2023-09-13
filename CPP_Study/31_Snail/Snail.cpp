#include<iostream>
using namespace std;
#include<iomanip> // manipulate : 조종하다. --> input output를 조작 |  setfill('0') , setw(2)
// 오늘의 주제 : 연습문제
// 달팽이 모양으로 숫자를 그릴것이다.
// --> 소용돌이 모양

const int MAX = 100;
int N;// 이런 작은 문제는 전역으로 선언해도됨.
int board[MAX][MAX] = {};// 배열의 크기는 const를 넣어줘야함.

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
			cout << setfill('0') << setw(2) << board[y][x] << " ";// setfill('0') : 0으로 채워줄것이다. | setw(2) : 2 자리를 보장
		}
		cout << endl;
	}
}
// 내 풀이
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

// ROOKISS 풀이
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
// ver 1.0 -- 직관적인 풀이
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
			break;// 종료 부분

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

// ver 2.0 -- 자료구조 알고리즘을 적용한 풀이
void SetBoard2()
{
	int dir = RIGHT;

	int num = 1;
	int y = 0;
	int x = 0;

	// 이 부분이 위에와 다른부분
	int dy[] = { 0,1,0,-1 };
	int dx[] = { 1,0,-1,0 };

	while (true)
	{
		board[y][x] = num;

		if (num == N * N)
			break;// 종료 부분

		// 이렇게 하면 switch-case 를 안써도됨.!!!
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
			// switch - case 를 대체
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