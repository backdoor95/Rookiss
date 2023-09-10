#include<iostream>
using namespace std;

// 오늘의 주제 : 배열

struct StatInfo
{
	int hp = 0xAAAAAAAA;// 이렇게 초기값을 설정할 수 있다.
	int attack= 0xBBBBBBBB;
	int defence=0xDDDDDDDD;
};

int main()
{
	// 근데 몬스터가 최대 1만 마리!
	// 같은 몬스터를 편리하게 관리할 수 없을까?
	
	//TYPE 이름[개수];

	// 배열의 크기는 상수여야 함. (VS 컴파일러 기준)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];// 개수는 상수를 넣어야함.


	// 여태껏 변수들의 [이름]은 바구니의 이름이었음.
	int a = 10;
	int b = a;

	// 그런데 배열은 [이름] 조금 다르게 동작한다
	//StatInfo players[10];
	// players = monsters;

	// 그럼 배열의 이름은 뭐지?
	// 배열의 이름은 곧 배열의 시작 주소
	// 정확히는 시작 위치를 가리키는 TYPE* 포인터
	auto WhoAmI = monsters;

	// 주소[ (100,10,1) ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ....
	// monster_0[ 주소 ]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// 포인터의 덧셈
	// 진짜 1을 더하라는게 아니라, StatInfo 타입 바구니 한개씩 이동하라는 의미
	// StatInfo[ ] 주소[ (200,20,2) ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ....
	// monster_1[ 주소 ]
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// 포인터와 참조는 자유자재로 변환 가능하다.
	// StatInfo[ ] StatInfo[ ] monster_2,주소[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ....
	// monster_2[ 주소 ]
	StatInfo&monster_2 = *(monsters + 2);// * 이게 붙으면 해당 주소로 이동하라는 뜻
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	//[주의] 이거는 완전 다른 의미다.
	// StatInfo[ ] StatInfo[ ] 주소[ 내용물 ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ....
	// temp[ 내용물 ]---> 3번째 내용물을 '복사'하라는 의미다.
	// 배열에 있는 실제 데이터를 '조작'하는건 아니다.
	StatInfo temp = *(monsters + 2);// * 이게 붙으면 해당 주소로 이동하라는 뜻
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	// 이를 조금 더 자동화 한다!
	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);// * 이게 붙으면 해당 주소로 이동하라는 뜻
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = (i + 1);
	}

	// 근데 *(monster+i) 너무 불편하고 가독성이 떨어진다.. 더 편한 방법?
	// 인덱스!
	// 배열은 0번 부터 시작. N번째 인덱스에 해당하는 데이터에 접근하려면 배열이름[N]
	// *(monsters+i) = monsters[i]


	monsters[0].hp = 100;
	monsters[0].attack = 10;
	monsters[0].defence = 1;
	for (int i = 0; i < 10; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = (i + 1);
	}

	// 배열 초기화 문법 몇가지
	int numbers[5] = {};// 모든 값이 0으로 세팅
	/*
		int numbers[5] = {};// 모든 값이 0으로 세팅
00B654E8  xor         eax,eax  
00B654EA  mov         dword ptr [numbers],eax  
00B654F0  mov         dword ptr [ebp-124h],eax  
00B654F6  mov         dword ptr [ebp-120h],eax  
00B654FC  mov         dword ptr [ebp-11Ch],eax  
00B65502  mov         dword ptr [ebp-118h],eax  
	*/
	int numbers1[10] = { 1,2,3,4,5 };// 설정한 애들은 설정한 값들로, 나머지 값들은 0으로 초기화
	/*
		int numbers1[10] = { 1,2,3,4,5 };
00955508  mov         dword ptr [numbers1],1  
00955512  mov         dword ptr [ebp-154h],2  
0095551C  mov         dword ptr [ebp-150h],3  
00955526  mov         dword ptr [ebp-14Ch],4  
00955530  mov         dword ptr [ebp-148h],5  
0095553A  xor         eax,eax  
0095553C  mov         dword ptr [ebp-144h],eax  
00955542  mov         dword ptr [ebp-140h],eax  
00955548  mov         dword ptr [ebp-13Ch],eax  
0095554E  mov         dword ptr [ebp-138h],eax  
00955554  mov         dword ptr [ebp-134h],eax  

	*/

	int numbers2[] = { 1,2,3,4,11,245,666,73,2,1 };// 데이터 개수만큼의 크기에 해당하는 배열로 만들어준다.

	char helloStr[]={'H','e','l','l','o','\0'};

	// 배열 요약:
	// 1) 선언한다.
	int arr[10] = {};
	// 2) 인덱스로 접근해서 사용
	arr[1] = 1;
	


	return 0;
}