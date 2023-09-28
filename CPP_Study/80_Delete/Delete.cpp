#include<iostream>
#include<vector>
#include<list>
using namespace std;

// 오늘의 주제 : delete(삭제된 함수)

class Knight
{
public:

	void operator=(const Knight& k) = delete;// 이렇게 사용하자! 단, public 으로 하는게 관례
	// 우리가 이 함수를 제공하지 않겠다라는 명시적인 메시지를 전해줄수 있다.

private:
	// 정의되지 않은 비공개 함수
	//void operator=(const Knight& k); // 굉좡히 안좋은 방법임.


	// 모든 것을 뚫는 창 vs 절대 방패
	friend class Admin;// Admin 한테는 뒷길을 열어줌. private에 접근할수 있게 됨.

private:
	int _hp = 100;
};

class Admin
{
public:
	void CopyKnight(const Knight& k)
	{
		Knight k1;
		// 복사 연산
		k1 = k;
	}
};

int main()
{
	Knight k1;

	Knight k2;

	// 복사 연산자
	//k1 = k2;


	return 0;
}