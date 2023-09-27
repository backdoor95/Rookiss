#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<map>
using namespace std;

//������ ���� : auto

class Knight
{
public:
	int _hp;
};

template<typename T>
void Print(T t)
{
	cout << t << endl;
}

int main()
{
	// Modern C++(C++11)

	//int a = 3;
	//float b = 3.14f;
	//double c = 1.23;
	//Knight d = Knight();
	//const char* e = "rookiss";

	auto a = 3;
	auto b = 3.14f;
	auto c = 1.23;
	auto d = Knight();
	auto e = "rookiss";

	// auto�� ������ ��Ŀī��
	// ���� ���� (type deduction) : Ÿ�� �߷�
	// -> ���� �ǰ� �� �����~(�߷�)
	// �߷� ��Ģ�� �������� ���� --> �̰� ���߿� �Ƿ��� ���̸� �˾ƺ���

	//auto f = &d;
	//const auto test1 = b;// const float���� ����
	//auto* test2 = e;
	//
	
	//���� !
	// �⺻ auto�� const, & ����!!!!!!!!!!!!!!!!!!
	int& reference = a;
	const int cst = a;

	auto test1 = reference;// ���⼭ auto�� int
	auto test2 = cst;// ���⼭ auto�� int


	// rookiss�� �ߴ� �Ǽ�
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		auto data = v[i];// int& data = v[i]���� �˾Ҵµ�, �Ʒ� ������� �۵���.
		//int data = v[i]; �����ؼ� data�� ����ִ°���.!! ������ ��������.
		// �ذ��
		auto& data2 = v[i]; // ���۷����� �Ȱ��� ������ �����ϰ� ������, auto�� ��Ʈ�� �����.
		// �� �����ʿ� �ִ� ���� ��ü�� �����ؾ��Ѵٰ� ��Ʈ�� �����.
	}

	// �ƹ�ư ���� ������ Ÿ���� �ؾ������ auto�� ����ҷ���~~
	// Rookiss �ְ����� ���� == NO! ---> ���������� ���ذ� ���� ����
	// -> Ÿ������ ������� ��� OK
	// -> �������� ���� �Ϲ������δ� ���δ°� ����.


	map<int, int> m;
	auto ok = m.insert(make_pair(1, 100));

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}


	return 0;
}