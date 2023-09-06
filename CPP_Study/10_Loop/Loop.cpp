#include<iostream>
using namespace std;

// 오늘의 주제 : 반복문
// 데이터를 메모리에 할당,가공하고 방법에 대해 알아봄
// 가공한 데이터를 이용해서 무엇인가를 하고 싶다면?

int main() {

	//while : ~동안에
	// if-else :굉장히 유용
	// 하지만 한 번만 실행하는게 아니라, 특정 조건까지 계속 반복해야 하는 상황
	//ex) 게임을 끌때까지 계속 게임을 실행해라
	//ex) 목적지에 도달할때까지 ~ 계속 이동하라

	/*
	while (조건식)
	{
		명령문
	}
	*/


	//int count = 0;

	// 해당 영역 주석처리 = CTRL + K + C
	// 
	// 해당 영역 주석해졔 = CTRL + K + U
	// 
	//while (count < 5) 
	//{
	//	cout << "hello world" << endl;
	//	count++;
	//}


	//do
	//{
	//	cout << "hello world" << endl;
	//} while (false);// do - while은 거의 사용하지 않음.. 
	// 이거는 적어도 한번은 실행됨.


	// break : 반복문에서 빠져나가라

	// continue : 해당 조건을 만족하면 뒷 부분을 스킵


	for (int count = 0; count < 5; count++)// 초기식:조건식:제어식
	{
		cout << "Hello World" << endl;

		//
		
		// 
		
		//

	}


	// break, continue

	// 루프문의 흐름제어 break, continue

	int round = 1;
	int hp = 100;
	int damage = 10;

	// 무한 루프 : 전투 시작
	while (true) 
	{
		hp -= damage;
		if (hp < 0)
			hp = 0;// 음수 체력을 0으로 보정

		// 시스템 메시지
		cout << "Round " << round << " 몬스터 체력 " << hp << endl;

		if (hp == 0)
		{
			cout << "몬스터 처치!" << endl;
			break;
		}

		if (round == 5)
		{
			cout << "제한 라운드 종료" << endl;
			break;
		}

		round++;
	}



	// 1 ~ 10 사이의 홀수만 출력하기

	for (int count = 1;count<=10;count++)
	{
		bool isEven = ((count % 2) == 0);// 이런 방식 깔끔하고 좋아보임!

		if (isEven)
			continue;

		if (isEven == false)
		{
			cout << count << endl;
		}
	}








}