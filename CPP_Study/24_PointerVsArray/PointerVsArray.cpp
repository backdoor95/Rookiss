#include<iostream>
using namespace std;

// 오늘의 주제 : 포인터 vs 배열

void Test(int a)
{
	a++;
}

// 배열은 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 치환한다. (char[]-> char*)
// 즉 배열의 내용 전체를 넘긴게 아니라, 시작 주소(포인터)만 넘긴거
void Test(char a[])
{
	a[0] = 'X';
}
int main()
{
	// 문자열 = 문자 배열
	"Hello World";// \0 포함 12자리

	// 배열 : 같은 데이터의 묶음

	cout << "Hello World" << endl;
	// 문자열 끝에는 \0를 붙여야함. 문자의 끝을 의미

	char msg[] = { 'H','e','l','l','o','\0' };

	char msg2[] = "Hello World";

	const char* msg3 = "Hello World";
	// char* msg3 = "Hello World"; // 이거는 에러뜸


	// .data 주소[H][e][l][l][o][ ][W][o][r][l][d][\0]  -- .data 영역에 저장됨. 정확히는 read only data(.rdata)
	// test1[ 주소 ] << 8바이트
	const char* test1 = "Hello World"; // 꼭 const가 붙어야함.

	const char* temp1 = "Hello World";


	// .data 주소[H][e][l][l][o][ ][W][o][r][l][d][\0]  -- .data 영역에 저장됨. 정확히는 read only data(.rdata)
	// [H][e][l][l][o][ ][W][o][r][l][d][\0] -- 4바이트씩 복사
	// test2 = 주소
	char test2[] = "Hello World";
	test2[0] = 'R';

	char test3[12];

	//test3 = test2; -- 이거 에러남.

	/*
	* 1 word = 2 byte = 16 bit
		char test2[] = "Hello World";
003E25CE  mov         eax,dword ptr [string "Hello World" (03E9B30h)]  03E9B30h여기 주소로 가서 dword(4 바이트)를 긁어와서 eax에 넣음.
003E25D3  mov         dword ptr [test2],eax  
003E25D6  mov         ecx,dword ptr ds:[3E9B34h]  
003E25DC  mov         dword ptr [ebp-48h],ecx  
003E25DF  mov         edx,dword ptr ds:[3E9B38h]  
003E25E5  mov         dword ptr [ebp-44h],edx  

즉 4바이트씩 긁어와서 복사함.
	
	*/

	// 배열과 포인터는 다르다.

	// 포인터는 [주소를 담는 바구니]
	// 배열은 [닭장] 즉, 그 자체로 같은 데이터끼리 붙어있는 '바구니 모음'
	// - 다만 [배열 이름]은 '바구니 모음'의 [시작 주소]


	// 배열을 함수의 인자로 넘기게 되면?

	int a = 0;
	Test(a);
	cout << a << endl;

	// test2가 바뀔까? 안바뀔까 --> 바뀐다.
	Test(test2);
	cout << test2 << endl;


	return 0;
}