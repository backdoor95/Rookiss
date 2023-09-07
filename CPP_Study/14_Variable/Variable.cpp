#include<iostream>
using namespace std;

// 오늘의 주제 : 지역 변수와 값(value) 전달

// 전역 변수-- 지양해야한다. 관리가 어렵기 때문. // 자유도가 높은 대신에 데이터가 꼬일수 있는 확률이 높기때문이다.
int globalValue = 0;

void Test() 
{
	cout << "전역 변수의 값은 : " << globalValue << endl;
	globalValue++;
}

void IncreaseHp(int hp)
{
	int finalHp = hp + 1;
	hp = hp + 1;
}
// 스택의 그림을 잘 그릴줄 알아야한다.
// [매개변수][RET][지역변수(hp=1)] [매개변수(hp=1)][RET][지역변수(finalHp=2)] [매개변수][RET][지역변수] .....
// 매개변수, RET는 이전 함수가 세팅을 해줌.
// 매개변수 : 어셈블리 , push push 해서 스택에 넣어줌.
// ret : call 할때 , 넣어줌.
// 그렇다면 진퉁 hp를 증가시키고 싶으면 어떻게 해야? : 포인터, 참조의 방법을 통해서...
int main() {

	cout << "전역 변수의 값은 : " << globalValue << endl;
	Test();
	//지역 변수
	int localValue = 1;

	int hp = 1;
	cout << "increase 호출 전 : " << hp << endl;
	IncreaseHp(hp);
	cout << "increase 호출 후 : " << hp << endl;


	return 0;
}