#include<iostream>
using namespace std;

// 오늘의 주제 : 함수 마무리

// 오버로딩 (중복 정의 : 함수 이름의 재사용)
// - 매개변수 갯수가 다르거나
// - 매개변수 타입이 다르거나 (순서가 다른걸 포함)

int Add(int a, int b)
{
	int result = a + b;
	return result;
}

int Add(int a, int b=0)
{
	int result = a + b;
	return result;
}


int Add(int a)// 이렇게 빌드를 하면 모호하기 때문에 컴파일러가 에러를 낸다.
{
	int result = a + 1;
	return result;
}

//float Add(int a, int b)// 반환 형식만 다른건 오버로딩이 안됨.
//{
//	int result = a + b;
//	return result;
//}

float AddFloat(int a, float b)
{
	float result = a + b;
	return result;
}


float AddFloat(float a, float b)
{
	float result = a + b;
	return result;
}

// 기본 인자값
void SetPlayerInfo1(int hp, int mp, int attack, int guildId = 0)
{

}

//void SetPlayerInfo2(int hp, int mp, int attack=0, int guildId)// 이렇게하면, 기본 인수가 매개 변수 목록의 끝에 없다고 에러뜸.
//{// 그래서 항상 기본값을 설정하는 매개변수는 뒷쪽에다가 몰아 넣어야함.
//
//	
// 
// 
// 
//}

//void SetPlayerInfo3(int hp, int mp, int attack=1, int guildId=2)// 
//{// 그래서 항상 기본값을 설정하는 매개변수는 뒷쪽에다가 몰아 넣어야함.
//
//	
// 
// 
// 
//}


// 스택 오버플로우
// 너무 함수를 많이 호출하면 발생함.

int Factorial(int n)
{
	// 재귀함수는 기저사항 필요
	if (n <= 1) return 1;

	return n * Factorial(n - 1);
}




int main() {

	float result = AddFloat(1.5f, 2.1f);
	cout << result << endl;

	SetPlayerInfo1(100, 40, 10);
//	SetPlayerInfo2(100, 40, 10, 0);

	// 5! = 5*4*3*2*1 = 5*4!

	int result2 = Factorial(5);
	cout << result2 << endl;

	return 0;
}