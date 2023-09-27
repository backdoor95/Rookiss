#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

// ������ ���� : �߰�ȣ �ʱ�ȭ { }
class Knight
{
public:
	Knight()
	{
		cout << "Knight()" << endl;
	}

	Knight(int a, int b)
	{
		cout << "Knight(int, int)" << endl;
	}

	Knight(initializer_list<int> li)// �켱������ ���� ������.
	{
		cout << "Knight(initializer_list)" << endl;
	}

};

int main()
{
	// �߰�ȣ �ʱ�ȭ { }
	int a = 0;
	int b(0);
	int c{ 0 };

	Knight k1;
	Knight k2 = k1;// ���� ������ (���� ������X)


	Knight k4;// �⺻ ������
	k4 = k1;// ���� ������


	Knight k3{ k1 };

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2(10, 1);// 10���� 1�� �ʱ�ȭ
	int arr[] = { 1,2,3,4, };

	//C++11

	// �߰�ȣ �ʱ�ȭ
	// 1) vector�� container�� �� ��︰��.
	vector<int> v3{ 1,2,3,4 };// 1,2,3,4�� push_back�� �� �Ͱ� ����.

	// 2) ��� ��ȯ ����
	int x = 0;
	//double y(x);// ���� �߻� �ȳ�.
	double y{ x };// ���� �߻�


	// 3) Bonus
	Knight k5{ };// �̷��� �ϸ� �⺻ ������ �������� �����̵ȴ�.

	Knight k6{ 1,2,3,4,5 };//initializer_list������ ��������.

	Knight k7{ 1,2 };//initializer_list������ ȣ���. ���� �ǵ��� ���� 2���� �޴� �����ڸ� ȣ���Ϸ��� ����.

	// �߰�ȣ �ʱ�ȭ�� ������ "���� �ı���"--> ��� �����ڸ� ���ƹ����� ȿ��!

	

	// ��ȣ �ʱ�ȭ ()�� �⺻���� ����-- ��κ�!!
	// - �������� C++ (�źΰ��� ����)
	// - vector �� Ư���� ���̽��� ���ؼ��� { } ���

	// �߰�ȣ �ʱ�ȭ { }�� �⺻���� ����
	// - �ʱ�ȭ ������ ��ġȭ
	// - ��� ��ȯ ����

	// ��� ���� �ϳ��� ���ؼ� �۾��Ұ�!

	return 0;
}