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
// �� Ǯ��
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
// Rookiss Ǯ��
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

//���� 4) ���ڿ� ���ϴ� �Լ�
// �� Ǯ��
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
//Rookiss Ǯ��
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

// ���� 5 ) ���ڿ��� ������ �Լ�
// �� Ǯ��
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

	// 1���ڶ��? --> �ƹ��� ��ġ�� ������ �ʾƵ���.
	// 2���ڶ��? --> [(count==2)/2 = 1 ]
	// 3���ڶ��? --> [(count==3)/2 = 1 ]
	for (int j = 0; j < count / 2; j++)
	{
		char temp = str[j];
		str[j] = str[count - 1 - j];
		str[count - 1 - j] = temp;
	}

}
// Rookiss Ǯ��
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


	//strcat(a,c);// cat�� concatenate : ������Ű��.
	StrCatByMun(a, c);
	cout << a << endl;
	StrCat(a, c);

	// ������ ��
	char d[BUF_SIZE] = "Hello";
	//  a==d �̰Ŵ� �ּҸ� ���ϴ°��̴�. �����Ұ�!
	
	int value = strcmp(a, d);// �����͵� �����Ǿ��ִ�. �ƽ�Ű �ڵ�ǥ�� ���� ����. [<0, 0, >0]
	// a = "aaa", d="bbb" --> value = -1
	// a = "bbb", d="aaa" --> value = +1
	// ���ڼ��� �ٸ���, '\0'�� �񱳸� �Ѵ�.
	cout << "strcmp �Լ� ����� : " << value << endl;

	value = StrCmpByMun(a, d);
	cout << "StrCmpByMun �Լ� ����� : " << value << endl;

	value = StrCmp(a, d);
	cout << "StrCmp �Լ� ����� : " << value << endl;

	cout << "ORIGINAL a = " << a << endl;
	ReverseStrByMun(a);
	cout << "REVERSE a = " << a << endl;

	ReverseStr(a);
	cout << "Rookiss REVERSE a = " << a << endl;
	return 0;
}