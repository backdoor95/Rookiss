#include<iostream>
using namespace std;
#include "Test1.h"

// 오늘의 주제 : 파일 분할 관리

// 프로그램이 빌드 되는 과정은 위에서부터 순차적으로 빌드가 된다.


int main()
{
	Test_1();

	return 0;
}

// TIP
// 헤더 파일은 최대한 간단하게 유지시켜주는게 중요하다. --> 중첩을 방지해야한다.
