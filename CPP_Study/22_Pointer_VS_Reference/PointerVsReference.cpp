#include<iostream>
using namespace std;

// 오늘의 주제 : 참조

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// [매개변수][RET][지역변수(info)] [매개변수(&info)][RET][지역변수]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// 특정 조건을 만족하는 몬스터를 찾는 함수
StatInfo* FindMonster()
{
	// TODO : Heap 영역에서 뭔가를 찾아봄.
	// 찾았다!
	// return monster ~;


	return nullptr;
}

StatInfo globalInfo;
/*
* 포인터에서 const를 사용할 수 있다.
* 포인터에도 const를 붙여서 원치않는 작업을 막아서 안정성을 높일 수 있다.
* 근데 포인터에서는 const는 필수가 아니다. but 참조에서는 어지간 해서는 const가 세트로 붙음.
* 
1) * 앞에 const를 붙이는 경우
---1. void PrintInfo(const StatInfo* info) - 이 방법이 많이 쓰임.
---2. void PrintInfo(StatInfo const* info)// 이렇게 쓰는 사람도 있다.

2) * 뒤에 const를 붙이는 경우
---   void PrintInfo(StatInfo*const info)

3) * 앞, 뒤 모두const를 붙이는 경우
	  void PrintInfo(const StatInfo* const info)

*/
void PrintInfo(const StatInfo* const info)
{
	//항상 포인터를 nullptr 체크
	if (info == nullptr)
		return;// 

	if (!info)// 이렇게도 null 체크 가능, 근데 위에꺼가 더 가독성이 좋다.
		return;


	cout << "-------------------------" << endl;
	cout << "HP: " << info->hp << endl;
	cout << "ATT: " << info->attack << endl;
	cout << "DEF: " << info->defence << endl;
	cout << "-------------------------" << endl;

	
	// 별 뒤에 붙인다면?
	// StatInfo* const info
	// info라는 바구니의 내용물(주소)을 바꿀 수 없음.
	// info는 주소값을 갖는 바구니 -> 이 주소값이 고정이다!

	
	// 별 이전에 붙인다면?
	// const StatInfo* info
	// info가 '가리키고 있는' 바구니의 내용물을 바꿀 수 없음
	// '원격' 바구니의 내용물을 바꿀 수 없음.

	// 그냥 전부 바꿀수 없게 하려면 
	// *  앞, 뒤로 const를 붙여주면됨.
	// const StatInfo* const info

	// 1.info[ 주소값 ]      2.주소값[ 데이터 ]
	// 1. void PrintInfo(StatInfo* const info) 일때, 에러발생.
	// 주소값을 못 바꿈
	//info = &globalInfo;

	// 2. void PrintInfo(const StatInfo* info) 일때, 에러발생
	// 해당 주소값의 내용물을 못 바꿈.
	//info->hp = 10000;


}

// 이름 바꾸기 단축키 : ctrl + R R
void PrintInfo(const StatInfo& info)// 만약에 100% 확률로 info를 수정하지 않을거라는 확신이 있다면
// const를 붙여주자. 어지간해서는 reference랑 const가 세트로 다니는 경우가 많다.
{
	cout << "-------------------------" << endl;
	cout << "HP: " << info.hp << endl;
	cout << "ATT: " << info.attack << endl;
	cout << "DEF: " << info.defence << endl;
	cout << "-------------------------" << endl;

	// 신입이 왔다.
	//info.hp = 2;// 에러 발생, const이기 때문에 못 바꿈
}


// 원래 공용으로 사용하는 헤더에 따로 빼놈.
// 뒤에 아무것도 없음. 컴파일 될때 아무런 의미가 없음
#define OUT
// c#에서는 out이라는 문법이 있다.
// c++에서는 바뀔수도 있다라는 힌트를 주는 용도로 쓰임.
// 언리얼 엔진 샘플에서도 이런 방식을 많이씀.
void ChangeInfo(OUT StatInfo& info)
{
	info.hp = 1000;
}

int main()
{
	StatInfo info;
	CreateMonster(&info);

	// 포인터 vs 참조 세기의 대결
	// 성능 : 똑같음
	// 편의성 : 참조 승!

	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만은 아니다.
	// 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있다.
	// 참조는 자연스럽게 모르고 지나칠 수도 있다.
	// 참조가 인줄 모르고 원본을 훼손할 수 있다.
	// ex) 마음대로 고친다면?
	// const를 사용해서 이런 마음대로 고치는 부분 개선가능

	// 참고로 포인터도 const를 사용 가능.
	// * 기준으로 앞에 붙이느냐, 뒤에 붙이느냐에 따라 의미가 달라진다.


	// 2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름 (별칭?)
	// -> 참조하는 대상이 없으면 안됨.
	// 반면 포인터는 그냥 어떤 ~주소라는 의미
	// -> 대상이 실존하지 않을 수도 있음.
	// reference는 사칙연산 안됨. 포인터는 됨.
	// 포인터에서 '없다'는 의미로?  --> nullptr or NULL
	// 프로그램이 뻗는 이유중 80%는 유효하지 않은 주소때문.
	// 
	// 참조 타입은 이런 nullptr이 없다.
	// 무조건 어떤 값을 가리키기 때문


	// StatInfo* pointer = &info;// 이렇게 해도됨.
	StatInfo* pointer = nullptr;// NULL를 넣어도되나, null 포인터라는 의미에서 nullptr를 쓴다.
	int a = NULL;// nullptr를 못넣음. 에러남.

	pointer = &info;
	PrintInfo(pointer);
	PrintInfo(&info);

	//StatInfo& reference; // 에러가난다. reference는 무조건 참조를 하고 있어야함.
	StatInfo& reference = info;
	PrintInfo(reference);

	PrintInfo(info);

	// 그래서 결론?
	// 사실 Team By Team ... 정해진 답은 없다.
	// ex) 구글에서 만든 오픈소스를 보면 거의 무조건 포인터 사용
	// ex) 언리얼 엔진에선 reference도 애용

	
	// Rookiss 선호 스타일
	// - 없는 경우도 고려해야 한다면 pointer (null 체크 필수)
	// - 바뀌지 않고 읽는 용도(readonly)만 사용하면 const ref&
	// - 그 외 일반적으로 ref(명시적으로 호출할 때 OUT을 붙인다.)
	// -- 단, 다른 사람이 pointer를 만들어놓은걸 이어서 만든다면, 계속 pointer (섞어 사용하진 않는다. ref로 바꾸지 않는다는 의미.)
	ChangeInfo(OUT info);// 이렇게 하면 가독성 측면에서 이걸 더 주의깊게 확인할 수 있다.

	// 보너스) 포인터로 사용하던걸 참조로 넘겨주려면?
	PrintInfo(pointer);

	// 보너스) 참조로 사용하던걸 포인터로 넘겨주려면?


	return 0;

}