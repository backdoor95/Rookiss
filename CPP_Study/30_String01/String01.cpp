#include<iostream>
using namespace std;

// ������ ���� : ��������

// ���� 1) ���ڿ� ���̸� ����ϴ� �Լ�
// �� Ǯ�� 
int StrLenByMun(const char* str)
{
	// str�̶�� ���ڿ��� ���̸� ��ȯ
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
// Rookiss Ǯ��
int StrLen(const char* str)
{
	
	// str�̶�� ���ڿ��� ���̸� ��ȯ
	int count = 0;
	while (str[count] != '\0')
		count++;
	return count;
}

// ����2) ���ڿ� ���� �Լ�
// �� Ǯ��
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

// Rookiss Ǯ��
char* StrCpy(char* dest, char* src)
{
	// ver 1.
	//int i = 0;

	//while (src[i] != '\0') //while(src[i]) �̷��� �ص���.
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
		//// dest, src �Ѵ� char �������̱� ������ 1byte�� ������.
		//dest++;
		//src++;
		// ���� ������ ���ٷ� �Ϸ���
		 *dest++=*src++;
	}
	*dest = '\0';
	return ret;// dest�� ��ȯ�ϸ� �ȵȴ�. �ֳ��ϸ� dest�� �ʱⰪ�� �ƴ϶� \0�� ����Ű�� �ִ� �ּ��̱� ����.
	// �׷��� ret�� ��ȯ�ؾ��Ѵ�.

}

// ����3) ���ڿ� �����̴� �Լ�
char* StrCat(char* dest, char* src)
{

}
#pragma warning(disable: 4996)
int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE];

	int len = sizeof(a);// �迭�� ũ�⸦ ��ȯ(100)! ���빰�� ũ�⸦ ��ȯ�ϴ°� �ƴ�.
	cout << len<<endl;

	int len2 = strlen(a);// 5�� ��ȯ ���ڿ� �ڿ� null ���� ��ȯ
	cout << len2<<endl;

	int len3 = StrLen(a);
	cout << len3 << endl;

	//b = a;// a�� b�� �迭�̰�, �迭�� �̸��� �����̸��ϻ�. �ϳ��ϳ��� �����ؼ� �־������.


	//#pragma warning(disable: 4996) �� �ϸ� ������ �ȳ���.
	//char *c = strcpy(b, a);// �̰� �������� ����. string buffer overflow ��� ������. 
	// ���÷� b�� ũ�Ⱑ 2�϶�, �߻� ���ɼ�!! b�� ������ ����
	//cout << c << endl;
	//cout << b << endl;

	strcpy_s(b, a);// �̰Ŵ� ���� ũ����� üũ���شٰ� �����.
	cout << b << endl;

	StrCpyByMun(b, a);
	cout << b << endl;

	StrCpy(b, a);
	cout << b << endl;

	char c[BUF_SIZE] = "World";

	strcat(a,c);// cat�� concatenate : ������Ű��.

	return 0;
}