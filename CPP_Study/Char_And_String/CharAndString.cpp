#include<iostream>
using namespace std;
// 오늘의 주제 : 문자와 문자열
// bool은 그냥 정수지만, 참/거짓을 나타내기 위해 사용한다 했었음.
// 사실 char도 마찬가지. 그냥 정수지만 '문자' 의미를 나타내기 위해 사용

// char : 알파벳 / 숫자 문자를 나타낸다.
// wchar_t : 유니코드 문자를 나타낸다.
// ASCII (American Standard Code for Information Interchange)


// '문자'의 의미로 작은 따옴표 '' 사용
char ch = 'a';
char ch2 = '1';
char ch3 = 'a' + 1;

// 국제화 시대에는 영어만으로 서비스 할 수 없음
// 전 세계 모든 문자에 대해 유일 코드를 부여한 것이 유니코드(unicode)
// 참고) 유니코드에서 가장 많은 번호를 차지하는게 한국어/중국어 ~

// 유니코드는 표기 방식이 여러가지가 있다. 대표적으로 UTF8 UTF16
//UTF8
// - 알파벳, 숫자 1바이트 (ASCII 동일한 번호)
// - 유럽 지역의 문자는 2바이트
// - 한글, 한자 등 3바이트

//UTF16
// - 알파벳, 숫자, 한글, 한자 등 거의 대부분 문자 2바이트
// - 매우 예외적인 고대 문자만 4바이트(사실상 무시해도됨)

// 유니코드를 입력해주기 위해서 L를 붙인다.
wchar_t wch = L'\'';//0xc548;//L'안'; // UTF16를 저장하는 타입

//Escape Sequence
// 표기하기 애매한 애들을 표현
// \0 = 아스키코드0 = NULL 의미함.
// \t = 아스키코드9 = Tab
// \n = 아스키코드10 = LineFeed (한줄 아래로)
// \r = 아스키코드13 = CarriageReturn(커서 <<)(커서를 맨 처음으로 리턴)
// 엔터키[Enter] = \r\n
// \' = 따옴표 출력

// 문자열
// 문자들이 열을 지어서 모여 있는 것 ( 문자 배열?)
// 정수 (1~8바이트) 고정길이로
//Ex) 길이차체가 가변이다.
// [\00 == NULL] 마지막(끝)에 null(0)이 들어감.

char str[] = { 'h','e','l','l','o' };// 여기서 선언을 하면 데이타 영역에 생성이 되어서 [hello]라고 출력이됨.
// 왜냐하면 data 영역은 0으로 이미 초기화가 되어있기 때문.!!
char str3[] = "Hello World";// 큰따옴표를 사용해서 문자열을 표현!, 마지막에 null이 붙어있다.

int main() {

	cout << ch << endl;
	cout << ch2 << endl;
	cout << ch3 << endl;
	cout << wch << endl;

	// cout은 char 전용
	wcout.imbue(locale("kor"));
	wcout << wch << endl;

	cout << str << endl;

	char str1[] = { 'h','e','l','l','o' };// 여기서 이렇게 선언하면 뒤에 이상한 값이 붙는다. \0을 만날때 까지. 스택에 있는값이 출력이됨.
	cout << str1 << endl;

	char str2[] = { 'h','e','l','l','o','\0'};// 여기서 이렇게 선언하면 뒤에 이상한 값이 붙는다. \0을 만날때 까지. 스택에 있는값이 출력이됨.
	cout << str2 << endl;

	cout << str3 << endl;

	return 0;
}