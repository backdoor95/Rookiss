#include<iostream>
using namespace std;


// 열거형
// 원래 const를 상수로 만들어서 관리
const int SCISSORS = 1;// const는 초기값을 반드시 넣어줘야함. ENUM은 안 넣어줘도됨.
const int ROCK = 2;
const int PAPER = 3;
//근데 상수인건 알겠는데, 너무 따로 따로 노는 느낌?
// 
// const 는 꼭 메모리에 올라가는건 아니다. 경우에 따라서 올라갈 수도 있고, 안올라갈수도 있다.
// 메모리에 안 올라 간다면, 그냥 SCISSORS는 1로 치환해서 작동을 한다.
// main 밖에다가 const를 만든다면 메모리에 올라가지 않는다느걸 확인함.
// 
// -*************************정리*****************************
// 만약에 컴파일러가 빌드를 하면서 분석하다가 예를 들어서 auto에다가 주소를 넣을 일이 생기면(주소를 참조할일),
// const 변수를 메모리에 주소를 할당하게 된다.(이 경우에는 그냥 전역으로 선언해서 main함수안에 auto 변수에 const 변수의 주소를 넣을 경우이다.
// 아래 예시 있으니까 참고할것.
// 
// 또는 main안에 const 변수를 만들게 되면, stack 메모리에 올라간다.
// 
// 경우에 따라서 컴파일러가 최적화를 할 수 있다면 메모리에 안올리고 그냥 값으로 대체하면서 사용함.
//***************************************************************


//

// 숫자를 지정 안하면 첫 값은 0부터 시작
// 그 다음ㄸ 값들은 이전 값 + 1
// enum은 빌드를 하는 단계(컴파일하는 단계)에서 완벽하게 바꿔치기됨.
// 최종 결과물은 값들로 대체가 됨.

// 열거형을 아무리 늘린다고 하더라도. 메모리 상에 잡히는 부분이 아니다.
// 가독성을 높이기 위해서 1이라는 값 대신 사용함.
enum ENUM_SRP // enum 이름 짓기
{
	ENUM_SCISSORS = 1,// 1
	ENUM_ROCK,//2
	ENUM_PAPER// 마지막은( , )를 넣어줘도 되고 안넣어줘도됨.// 3
};

//const를 사용하는것 보다 enum을 사용하는게 더 낫다.


// #이 붙은거 -> 전처리 지시문
// #include<iostream>이라는 파일을 찾아서 해당 내용을 그냥 복붙!
// 
// 전처리란? 
// ctrl + shift + b = 빌드
// 빌드의 과정 : 1.전처리(준비운동) 2.컴파일(통역, 본운동) 3.링크(최종 결과물들을 엮는다)
#define DEFINE_SCISSORS 1// define은 매크로를 만드는 전처리명령 : DEFINE_SCISSORS 문구가 등장하면 1로 대체
#define DEFINE_SCISSORS2 1+2// 1 + 2 로 바꿔치기 함. 3이라고 생각하면 안됨.
#define DEFINE_TEST cout<<"Hello World"<<endl;
// define 보다는 enum을 우선하자!
// 디버깅할때 전처리단계를 지나면 값이 안뜬다.!!
// enum을 쓴다면, 디버깅 할때 값이 뜬다.!!
// define은 지양하자.



int main()
{

	DEFINE_TEST;

	srand(time(0));// 시드 설정 srand는 rand와 짝궁이다.
	// 이럴 경우 스택 메모리에 const 변수가 할당 된다.
	//const int SCISSORS = 1;// const는 초기값을 반드시 넣어줘야함. ENUM은 안 넣어줘도됨.
	//const int ROCK = 2;
	//const int PAPER = 3;
	
//	auto a = &SCISSORS;// 이렇게 하면 
	

		// Rookiss 풀이

	// 숫자 자체를 코드안에 때려 넣는건 매우 안좋은 습관이다.
	// 내 코드는 숫자를 그냥 안에 넣었는데, 그 부분을 아래와 같이 고치도록 하자.
	// 
	// 상수화 : 이름을 지어줘서 변수로 사용
	// 이렇게 하는게 바람직함!.

	//const int SCISSORS = 1;
	//const int ROCK = 2;
	//const int PAPER = 3;

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

		if (input == ENUM_SCISSORS)
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