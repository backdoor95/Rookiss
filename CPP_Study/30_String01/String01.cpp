#include<iostream>
using namespace std;

// 오늘의 주제 : 연습문제

// 문제 1) 문자열 길이를 출력하는 함수
// 내 풀이 
int StrLenByMun(const char* str)
{
	// str이라는 문자열의 길이를 반환
	int len = 0;
	
	while (true)
	{
		if (str[len] == NULL)
		{
			break;
		}
		len++;
	}

	return len;
}
// Rookiss 풀이
int StrLen(const char* str)
{
	
	// str이라는 문자열의 길이를 반환
	int count = 0;
	while (str[count] != '\0')
		count++;
	return count;
}

// 문제2) 문자열 복사 함수
// 내 풀이
char* StrCpyByMun(char* dest, char* src)
{
	int index = 0;
	while (src[index]!='\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';

	return dest;
}

// Rookiss 풀이
char* StrCpy(char* dest, char* src)
{
	// ver 1.
	//int i = 0;

	//while (src[i] != '\0') //while(src[i]) 이렇게 해도됨.
	//{
	//	dest[i] = src[i];
	//	i++;
	//}

	//dest[i] = '\0';
	//return dest;

	// ver 2

	char* ret = dest;
	while (*src != '\0')//while(*src)
	{
		//*dest = *src;
		//// dest, src 둘다 char 포인터이기 때문에 1byte씩 증가함.
		//dest++;
		//src++;
		// 위에 세줄을 한줄로 하려면
		 *dest++=*src++;
	}
	*dest = '\0';
	return ret;// dest를 반환하면 안된다. 왜냐하면 dest의 초기값이 아니라 \0를 가리키고 있는 주소이기 때문.
	// 그래서 ret를 반환해야한다.

}

// 문제3) 문자열 덧붙이는 함수
char* StrCat(char* dest, char* src)
{

}
#pragma warning(disable: 4996)
int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE];

	int len = sizeof(a);// 배열의 크기를 반환(100)! 내용물의 크기를 반환하는게 아님.
	cout << len<<endl;

	int len2 = strlen(a);// 5를 반환 문자열 뒤에 null 빼고 반환
	cout << len2<<endl;

	int len3 = StrLen(a);
	cout << len3 << endl;

	//b = a;// a와 b는 배열이고, 배열의 이름은 시작이름일뿐. 하나하나씩 복사해서 넣어줘야함.


	//#pragma warning(disable: 4996) 를 하면 에러가 안나옴.
	//char *c = strcpy(b, a);// 이건 안전하지 않음. string buffer overflow 우려 때문에. 
	// 예시로 b의 크기가 2일때, 발생 가능성!! b는 목적지 버퍼
	//cout << c << endl;
	//cout << b << endl;

	strcpy_s(b, a);// 이거는 버퍼 크기까지 체크해준다고 보면됨.
	cout << b << endl;

	StrCpyByMun(b, a);
	cout << b << endl;

	StrCpy(b, a);
	cout << b << endl;

	char c[BUF_SIZE] = "World";

	strcat(a,c);// cat은 concatenate : 연접시키다.

	return 0;
}