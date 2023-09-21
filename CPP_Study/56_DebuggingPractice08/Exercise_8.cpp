#include <iostream>
using namespace std;
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"
#include "Pet.h"

// [Bug Report #8]
// 펫을 궁수의 생성자에서 만드는 것이
// 깔끔하지 않다는 사장님의 지적에 따라
// 일단 밖으로 빼서 펫을 생성하게 수정했습니다.

// 그런데 막상 밖으로 빼니 또 크래시가 납니다.
// 가만히 있으면 중간은 간다던데...
// 뭐가 문제일까요?

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	while (true)
	{
		// 나중엔 궁수, 법사 등 추가 예정
		Player* p = nullptr;

		switch (rand() % 3)
		{
			case 0:
			{
				p = new Knight();
				p->_hp = 100;
				p->_attack = 100;
				break;
			}	
			case 1:
			{
				// 여기서 같이 만들어준다
				// 이런 저런 펫 정보 추가될 예정
				//Pet pet;// 수정 전

				/*
				디버그 모드에서 일부러 고정 쓰레기값을 넣어서
				CCCC가 바뀌면, 그것을 오버플로우로 인식해서 크래시를 냅니다.
				예시)
				CCCCCCCC
				CCCCCCCC
				CCCCCCCC
				CCCCCCCC
				CCCCCCCC
				CCCCCCCC
				
				
				
				*/

				// 내 풀이: pet의 생명주기가 case 1: {~~~~} 이기 때문에
				// delete할때 엉뚱한 곳을 지우게 된다.

				// Rookiss 풀이
				// Archer를 삭제할때, 유효하지 않은 값들을 지우려고 하기 때문
				// 로컬영역을 건드렸기 때문에.
				// 어차피  { }를 벗어나면 소멸자가 호출됨.

				// 해결법
				Pet* pet = new Pet();// 수정 후 : 이렇게 힙 영역에 만들어주면됨.

				// Archer를 만들 때 pet 정보도 넘겨준다
				// 
				//p = new Archer(&pet); // 수정 전
				p = new Archer(pet); // 수정 후
				p->_hp = 100;
				p->_attack = 100;

				break;
			}		
			case 2:
			{
				p = new Mage();
				p->_hp = 100;
				p->_attack = 100;
				break;
			}			
		}

		delete p;
	}

}
