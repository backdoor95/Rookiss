#include<iostream>
using namespace std;

// ������ ���� : ���� ������

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}

void SetMessage(const char** a)
{
	*a = "Bye";
}

void SetMessage2(const char*& a)// *���ٰ� &(����)�� ���ϼ� �ִ�.
{
	a = "Wow";
}

int main()
{
	int a = 0;
	SetNumber(&a);
	cout << a << endl;


	// .rdata Hello�ּ�[H][e][l][l][o][\0]
	// .rdate Bye�ּ�[B][y][e][\0]
	// msg[ Hello�ּ� ] << 8����Ʈ
	const char* msg = "Hello";

											// [�Ű�����(a(Hello�ּ�))]���� �Ʒ� �ּҷ� �ٲ� 
	//[�Ű�����][RET][��������(msg(Hello�ּ�))] [�Ű�����(a(Bye�ּ�))][RET][��������]
	SetMessage(msg);
	cout << msg << endl; // �ٲ��� �ʴ� ����: ���� ������, ó�� a���� Hello �ּҰ� ����Ǿ��ִ�.
	// �ٵ� Bye �ּҰ� ����ǰ�, �Լ������� ������鼭 a ���� ���� �����.

	// �ּ�2[ ] << 1����Ʈ
	// �ּ�1[ �ּ� 2]<< 8����Ʈ
	// pp[ �ּ�1 ] << 8����Ʈ
	const char** pp = &msg;
	// .rdata Hello�ּ�[H][e][l][l][o][\0]
	// msg[ Hello�ּ� ]<< 8����Ʈ
	// pp[ &msg ] << 8����Ʈ

	//[�Ű�����][RET][��������(msg(Hello�ּ�))] [�Ű�����(a(&msg msg���ּ�))][RET][��������]
	SetMessage(&msg);

	//*pp = "Bye";
	cout << msg << endl;


	// ���� ������ : ȥ��������?
	// �׳� ���ı���� �����ϸ� �ȴ�.
	const char** pp2;//�����ʿ��� �������� �м��ϸ� �ȴ�.
	// ����� tip = *�� �ϳ��� ��鼭 Ÿ�� ���ٰ� �����ϸ� �����ϱ� ���ϴ�.


	// ������ �̿��� ���
	// ������ ���������� �����Ϳ� ���� ����.
	//[�Ű�����][RET][��������(msg(Hello�ּ�))] [�Ű�����(a(&msg msg���ּ�))][RET][��������]
	SetMessage2(msg);// 
	cout << msg << endl;

	return 0;
}