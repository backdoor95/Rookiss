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
// 내 풀이
char* StrCatByMun(char* dest, char* src)
{
	char* ret = dest;

	while (*dest)
	{
		dest++;
	}

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';

	return ret;

}
// Rookiss 풀이
char* StrCat(char* dest, char* src)
{
	// ver 1.0
	// 
	//int len = StrLen(dest);

	//int i = 0;
	//while (src[i] != '\0')
	//{
	//	dest[len + i] = src[i];
	//	i++;
	//}
	//dest[len + i] = '\0';
	//return dest;

	// ver 2.0
	char* ret = dest;
	while (*dest != '\0')
		dest++;

	while (*src != '\0')// == *src
	{
		*dest = *src;
		dest++;
		src++;
		// == (*dest++=*src++)
	}
	*dest = '\0';
	return ret;
}

//문제 4) 문자열 비교하는 함수
// 내 풀이
int StrCmpByMun(char* dest, char* src)
{

	while ((*dest)&&(*src))
	{
		if (*dest == *src)
		{
			dest++;
			src++;
			continue;
		}

		if (*dest - *src > 0)
		{
			return 1;
		}

		if (*dest - *src < 0)
		{
			return -1;
		}

	}

	if (*dest == '\0' && *src == '\0')
		return 0;

	return *dest - *src > 0 ? 1 : -1;
}
//Rookiss 풀이
int StrCmp(char* a, char* b)
{
	int i = 0;
	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] > b[i])
			return 1;
		if (a[i] < b[i])
			return -1;
		i++;
	}
	return 0;
}

// 문제 5 ) 문자열을 뒤집는 함수
// 내 풀이
void ReverseStrByMun(char* str)
{
	int index = 0;
	int count = 0;
	char temp;
	while (str[index])
	{
		index++;
	}
	count = index;

	// 1글자라면? --> 아무런 조치를 취하지 않아도됨.
	// 2글자라면? --> [(count==2)/2 = 1 ]
	// 3글자라면? --> [(count==3)/2 = 1 ]
	for (int j = 0; j < count / 2; j++)
	{
		char temp = str[j];
		str[j] = str[count - 1 - j];
		str[count - 1 - j] = temp;
	}

}
// Rookiss 풀이
void ReverseStr(char* str)
{
	int len = StrLen(str);

	for (int i = 0; i < len/2; i++)
	{
		int temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}

	return;
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


	//strcat(a,c);// cat은 concatenate : 연접시키다.
	StrCatByMun(a, c);
	cout << a << endl;
	StrCat(a, c);

	// 내용을 비교
	char d[BUF_SIZE] = "Hello";
	//  a==d 이거는 주소를 비교하는것이다. 주의할것!
	
	int value = strcmp(a, d);// 순서와도 연동되어있다. 아스키 코드표에 따라서 비교함. [<0, 0, >0]
	// a = "aaa", d="bbb" --> value = -1
	// a = "bbb", d="aaa" --> value = +1
	// 글자수가 다르면, '\0'과 비교를 한다.
	cout << "strcmp 함수 결과값 : " << value << endl;

	value = StrCmpByMun(a, d);
	cout << "StrCmpByMun 함수 결과값 : " << value << endl;

	value = StrCmp(a, d);
	cout << "StrCmp 함수 결과값 : " << value << endl;

	cout << "ORIGINAL a = " << a << endl;
	ReverseStrByMun(a);
	cout << "REVERSE a = " << a << endl;

	ReverseStr(a);
	cout << "Rookiss REVERSE a = " << a << endl;
	return 0;
}