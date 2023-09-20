#include<iostream>
#include"Game.h"

// " ", < > 차이점
// ["" : 커스텀 라이브러리 ],[ <>: c++ 공식 라이브러리]



using namespace std;


// 오늘의 주제 : TextRPG #4
// .cpp , .h 파일 같이 만드는법 -> 1. 폴더 우클릭 2. 추가 클릭 3. 클래스 클릭
// C++은 솔루션 탐색기에는 폴더로 정리가 되는것 처럼 보이지만, 실제로는 그냥 동일한 위치에 모여있다.--> Creature, Game 폴더는 가상폴더 같은 느낌이다.

// 헤더 파일은 선언과 관련된 애들을 모아두는곳
// cpp 파일에서는 전방선언 x -> 안심하고 include를 늘려줘도됨.

int main()
{
	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}


	return 0;
}