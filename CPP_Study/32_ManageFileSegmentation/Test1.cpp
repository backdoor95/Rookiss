#include<iostream>
using namespace std;
#include "Test1.h" // 여기에 있는 파일을 복붙아는 코드

// 각각의 cpp 파일은 서로 독립적이다. 빌드될때도 독립적으로 빌드가 된다.

void Test_1()// 정의부
{
	Test_2();
}

void Test_2()
{
	cout << "Hello World" << endl;
}

void Test_3()
{

}