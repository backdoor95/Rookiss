#include<iostream>
using namespace std;

int main()
{
	srand(time(0));// 시드 설정 srand는 rand와 짝궁이다.

	// 우리가 얻고 싶은것 1, 2, 3
	//int value = (rand() % 3) + 1;// 0~ 32767

	int Percentage = 0;// 비긴건 승률에서 제외, 승/패 만 적용
	int win = 0;
	int lose = 0;
	int input;
	int computer;
	int result;
	string m;
	string c;

	// 내 풀이 
	while (true)
	{
		cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;
		
		if (win==0&&lose==0)
		{
			cout << "현재 승률 : 없음" << endl;
		}
		else
		{
			cout << "현재 승률 : " << (win*100) / (win + lose) << endl;
		}

		cout << ">";
		cin >> input;


		// 1. 탈출 조건
		if (input < 1 || input>3)
		{
			cout << "게임을 종료합니다." << endl;
			break;
		}

		computer = (rand() % 3) + 1;

		// 
		result = input - computer;


		// 2. 세팅
		if (input == 1)
		{
			m = "가위(님)";
		}
		else if (input == 2)
		{
			m = "바위(님)";
		}
		else if(input == 3)
		{
			m = "보(님)";
		}


		if (computer == 1)
		{
			c = "가위(컴퓨터)";
		}
		else if (computer == 2)
		{
			c = "바위(컴퓨터)";
		}
		else if (computer == 3)
		{
			c = "보(컴퓨터)";
		}

		
		// 풀이 1. [하드코딩]
		//if (input == 1)
		//{

		//}
		//else if (input == 2)
		//{

		//}
		//else if (input == 3)
		//{

		//}


		// 풀이 2. [개선안]
		// 가위 1, 바위 2, 보 3
		// result = input - computer
		switch (result)
		{
		case 2:// 님 = 보(3) , 컴 = 가위(1) [컴퓨터 승리]
			cout << m << " vs " << c << " 졌습니다!" << endl<<endl;
			lose++;
			break;// break, continue 둘중에 뭘 써야하지... 둘 다 같은 결과가 나옴. 나중에 헷갈리면 아래에 break, continue주석을 보기
		case 1:// 내가 이긴 경우
			cout << m << " vs " << c << " 이겼습니다!" << endl<<endl;
			win++;
			break;
		case 0:// 비긴 경우
			cout << m << " vs " << c << " 비겼습니다!" << endl<<endl;
			break;
		case -1:// 컴퓨터가 이긴 경우
			cout << m << " vs " << c << " 졌습니다!" << endl<<endl;
			lose++;
			break;
		case -2:// 님 = 가위(1) , 컴 = 보(3) [나 승리]
			cout << m << " vs " << c << " 이겼습니다!" << endl<<endl;
			win++;
			break;

		}

	}

	// Rookiss 풀이

	// 숫자 자체를 코드안에 때려 넣는건 매우 안좋은 습관이다.
	// 내 코드는 숫자를 그냥 안에 넣었는데, 그 부분을 아래와 같이 고치도록 하자.
	// 
	// 상수화 : 이름을 지어줘서 변수로 사용
	// 이렇게 하는게 바람직함!.

	const int SCISSORS = 1;
	const int ROCK = 2;
	const int PAPER = 3;

	int wins = 0;
	int total = 0;

	// switch - case 에서 break가 걸려있으면, switch - case를 나가는것이다.
	// 아니면 for문, while를 나가는것이다.

	// 눈으로 찾는게 어렵다면 break point를 설정해서 F5실행해서 디버깅하자!!
	// 조사식에서 wins/total 이런식으로 검색도 가능하다.

	// 정수와 정수를 나누면 정수이다.

	while (true)// 실질적으로 main안에 무한 루프가 있다.
	{
		cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;
		cout << "> ";

		if (total == 0)
		{
			cout << "현재 승률 : 없음" << endl;
		}
		else
		{
			//int winPercentage = wins / total * 100;// 승률 -> 이렇게 하면 계속 0이 뜸. 생각보다 연산순서가 중요하다.
			int winPercentage = (wins * 100) / total;// 승률
			cout << "현재 승률 : " << winPercentage << endl;
		}

		//컴퓨터
		int computerValue = 1 + (rand() % 3);

		// 사용자
		int input;
		cin >> input;

		if (input == SCISSORS)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "가위(님) vs 가위(컴퓨터) 비겼습니다!" << endl;
				break;
			case ROCK:
				cout << "가위(님) vs 바위(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			case PAPER:
				cout << "가위(님) vs 보(컴퓨터) 이겼습니다!" << endl;
				wins++;
				total++;
				break;

			}

		}
		else if (input == ROCK)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "바위(님) vs 가위(컴퓨터) 이겼습니다!" << endl;
				wins++;
				total++;
				break;
			case ROCK:
				cout << "바위(님) vs 바위(컴퓨터) 비겼습니다!" << endl;
				break;
			case PAPER:
				cout << "바위(님) vs 보(컴퓨터) 졌습니다!" << endl;
				total++;
				break;

			}
		}
		else if (input == PAPER)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "보(님) vs 가위(컴퓨터) 졌습니다!" << endl;
				total++;
				break;
			case ROCK:
				cout << "보(님) vs 바위(컴퓨터) 이겼습니다!" << endl;
				wins++;
				total++;
				break;
			case PAPER:
				cout << "보(님) vs 보(컴퓨터) 비겼습니다!" << endl;
				break;

			}
		}
		else
		{
			break;
		}


	}




}