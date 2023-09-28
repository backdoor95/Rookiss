#include<iostream>

// 오늘의 주제 : 전달 참조 (forwarding reference)

using namespace std;

class Knight
{
public:
	Knight() { cout << "기본 생성자" << endl; }
	Knight(const Knight&) { cout << "복사 생성자" << endl; }
	Knight(Knight&&) noexcept { cout << "이동 생성자" << endl; }

};

void Test_RValueRef(Knight&& k)// 오른값 참조 --> 이동대상 << 이라는 힌트
{

}

void Test_Copy(Knight k)
{

}

// 함수를 한번에 처리할 수 있게 되었음 
template<typename T>
void Test_ForwardingRef(T&& param)// 전달 참조
{
	//[T&&] 이런식으로 해야 전달 참조임. 
	// const T&& 이렇게 하나라도 더 붙여주는 순간 전달 참조로 동작하지 않음.
	// const T&& << 오른값 참조로 동작함.

	//TODO
	Test_Copy(param);// 

	Test_Copy(move(param));// 이렇게 해야 이동생성자가 호출됨.

	// 우리가 넘겨준 값이 
	// 왼값 참조라면 복사하는 형태로 - 1
	TestCopy(param);

	// 오른값 참조라면 이동하는 형태로 - 2
	TestCopy(move(param));

	// 1, 2를 알아서 해주는 것 ---> 한번에 처리가능!
	Test_Copy(forward<T>(param));

	


}

int main()
{
	// 보편 참조 (universal reference) or 전달참조라고 부름 
	// 전달 참조 (forwarding reference) C++17

	// &&  &를 두 번 -> 오른값 참조


	Knight k1;

	//Test_RValueRef(k1);// k1이 왼값이기때문에 오류발생
	Test_RValueRef(move(k1));// rvalue_cast

	// 경우에 따라서는 왼값 참조, 오른값 참조 로 변할수 있다.
	Test_ForwardingRef(move(k1));// 오른값 넣어줫으면 오른값 참조
	Test_ForwardingRef(k1);// 왼쪽값 넣어줬으면 왼값 참조

	// 카멜레온 같은놈
	auto&& k2 = k1;// 왼쪽 참조로 변환
	auto&& k3 = move(k1);// 오른쪽 참조로 변환

	// 정리 :  전달 참조는 템플렛이나 auto와 같은 문법으로 병행해서 사용할때만 등장한다.

	// 공통점 : 형식 연역( type deduction)이 일어날 때

	// 전달 참조를 구별하는 방법
	// ------------------------------------------------------------------------------------

	Knight& k4 = k1;// 왼값 참조
	Knight&& k5 = move(k1);// 오른값 참조 o , k5 자체는 왼값이다.

	// 오른값 : 왼값이 아니다 = 단일식에서 벗어나면 사용x
	// 오른값 참조 : 오른값만 참조할 수 있는 참조 타입

	//Test_RValueRef(k5);// 오류발생 오른값 참조 o , k5 자체는 왼값이다
	Test_RValueRef(move(k5));// 오류발생

	
	Test_ForwardingRef(k1);
	Test_ForwardingRef(move(k1));

	// 총정리 : 전달 참조는 무조건 forward를 사용하자!!

	return 0;
}
