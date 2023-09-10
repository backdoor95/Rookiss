#include<iostream>
using namespace std;

// ������ ���� : ������ vs �迭

void Test(int a)
{
	a++;
}

// �迭�� �Լ� ���ڷ� �ѱ��, �����Ϸ��� �˾Ƽ� �����ͷ� ġȯ�Ѵ�. (char[]-> char*)
// �� �迭�� ���� ��ü�� �ѱ�� �ƴ϶�, ���� �ּ�(������)�� �ѱ��
void Test(char a[])
{
	a[0] = 'X';
}
int main()
{
	// ���ڿ� = ���� �迭
	"Hello World";// \0 ���� 12�ڸ�

	// �迭 : ���� �������� ����

	cout << "Hello World" << endl;
	// ���ڿ� ������ \0�� �ٿ�����. ������ ���� �ǹ�

	char msg[] = { 'H','e','l','l','o','\0' };

	char msg2[] = "Hello World";

	const char* msg3 = "Hello World";
	// char* msg3 = "Hello World"; // �̰Ŵ� ������


	// .data �ּ�[H][e][l][l][o][ ][W][o][r][l][d][\0]  -- .data ������ �����. ��Ȯ���� read only data(.rdata)
	// test1[ �ּ� ] << 8����Ʈ
	const char* test1 = "Hello World"; // �� const�� �پ����.

	const char* temp1 = "Hello World";


	// .data �ּ�[H][e][l][l][o][ ][W][o][r][l][d][\0]  -- .data ������ �����. ��Ȯ���� read only data(.rdata)
	// [H][e][l][l][o][ ][W][o][r][l][d][\0] -- 4����Ʈ�� ����
	// test2 = �ּ�
	char test2[] = "Hello World";
	test2[0] = 'R';

	char test3[12];

	//test3 = test2; -- �̰� ������.

	/*
	* 1 word = 2 byte = 16 bit
		char test2[] = "Hello World";
003E25CE  mov         eax,dword ptr [string "Hello World" (03E9B30h)]  03E9B30h���� �ּҷ� ���� dword(4 ����Ʈ)�� �ܾ�ͼ� eax�� ����.
003E25D3  mov         dword ptr [test2],eax  
003E25D6  mov         ecx,dword ptr ds:[3E9B34h]  
003E25DC  mov         dword ptr [ebp-48h],ecx  
003E25DF  mov         edx,dword ptr ds:[3E9B38h]  
003E25E5  mov         dword ptr [ebp-44h],edx  

�� 4����Ʈ�� �ܾ�ͼ� ������.
	
	*/

	// �迭�� �����ʹ� �ٸ���.

	// �����ʹ� [�ּҸ� ��� �ٱ���]
	// �迭�� [����] ��, �� ��ü�� ���� �����ͳ��� �پ��ִ� '�ٱ��� ����'
	// - �ٸ� [�迭 �̸�]�� '�ٱ��� ����'�� [���� �ּ�]


	// �迭�� �Լ��� ���ڷ� �ѱ�� �Ǹ�?

	int a = 0;
	Test(a);
	cout << a << endl;

	// test2�� �ٲ��? �ȹٲ�� --> �ٲ��.
	Test(test2);
	cout << test2 << endl;


	return 0;
}