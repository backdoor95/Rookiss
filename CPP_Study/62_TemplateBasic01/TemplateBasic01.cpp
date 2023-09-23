#include<iostream>
using namespace std;

// ������ ���� : ���ø� ����

//void Print(int a)
//{
//	cout << a << endl;
//}
//void Print(float a)
//{
//	cout << a << endl;
//}
//void Print(double a)
//{
//	cout << a << endl;
//}
//void Print(const char* a)
//{
//	cout << a << endl;
//}

class Knight
{
public:
	// ...

public:
	int _hp = 123;
};

template<typename T> 
void Print(T a)
{
	cout << a << endl;
}

// ���ø� Ư��ȭ
// �ٸ� ��Ģ�� ������ ������
template<>// ����ī�尡 ����, �츮�� ��������� �ϴϱ� <> ���̸� ���������.
void Print(Knight a)
{
	cout << "Knight!!!!!!!!!!!!!!!!!" << endl;
	cout << a._hp << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}


//template<class T> // typename ��ſ� class �� �����ϴ�. �׷��� ����� class��� �ϸ� ���� �� Ŭ������ �־���� �� �� ���Ƽ� typename�� ��ȣ��.
//void Print(T a)
//{
//	cout << a << endl;
//}


int Add(int a, int b)
{
	return a + b;
}

float Add(float a, float b)
{
	return a + b;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}

// ������ �����ε�( �����Լ� ����)
ostream& operator <<(ostream& os, const Knight& k) // out-stream
{
	os << k._hp;
	return os;
}


int main()
{
	// ���ø� : �Լ��� Ŭ���� ���� Ʋ
	// 1) �Լ� ���ø�
	// 2) Ŭ���� ���ø�

	Print(50);
	Print<int>(50);// �̷��� ��������� Ÿ���� �����ټ� �ִ�.
	Print(50.0f);
	Print<int>(50.0f);
	Print(50.0);
	Print("Template Joker!!");
	// ���� �Լ��� �����ϴ°� �ƴ϶� 
	// ��¥�� ���� �Լ��� �����.

	/*
		Print(50);
00122B3F  push        32h  
00122B41  call        Print<int> (0121267h)  
00122B46  add         esp,4  
	Print<int>(50);// �̷��� ��������� Ÿ���� �����ټ� �ִ�.
00122B49  push        32h  
00122B4B  call        Print<int> (0121267h)  
00122B50  add         esp,4  
	Print(50.0f);
00122B53  push        ecx  
00122B54  movss       xmm0,dword ptr [__real@42480000 (0129B84h)]  
00122B5C  movss       dword ptr [esp],xmm0  
00122B61  call        Print<float> (0121442h)  
00122B66  add         esp,4  
	Print<int>(50.0f);
00122B69  push        32h  
00122B6B  call        Print<int> (0121267h)  
00122B70  add         esp,4  
	Print(50.0);
00122B73  sub         esp,8  
00122B76  movsd       xmm0,mmword ptr [__real@4049000000000000 (0129B78h)]  
00122B7E  movsd       mmword ptr [esp],xmm0  
00122B83  call        Print<double> (012132Ah)  
00122B88  add         esp,8  
	Print("Template Joker!!");
00122B8B  push        offset string "Template Joker!!" (0129B4Ch)  
00122B90  call        Print<char const *> (012117Ch)  
00122B95  add         esp,4  
	
	
	*/

	// ���ø� --> ��Ŀ ī��

	int result1 = Add(1, 2);
	float result2 = Add<float>(1.11f, 2.22f);

	//Print(int, cont char*); // --> typename�� 2���� �����.
	Print("Hello", 100);

	// ���ø� Ư��ȭ

	Knight k1;
	Print(k1);


	return 0;
}