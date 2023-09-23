#include<iostream>
#include<vector>
using namespace std;

// ������ ���� : vector01

int main()
{
	// �������� vector�� ���� ���
	// STL = Standard Template Library
	// ���α׷����� �� �ʿ��� �ڷᱸ��/�˰������
	// ���ø����� �����ϴ� ���̺귯��

	// �����̳�(Container) : �����͸� �����ϴ� ��ü (�ڷᱸ�� Data Structure)

	// Vector �� ��� ����� �н��ϴ°� �Ұ���!
	// ������ ���ؼ� �˾ƺ����̴�.
	// 
	// vector(���� �迭)
	// - vector�� ���� ���� (size/capacity)
	// - �߰� ����/����
	// - ó��/��, ����/����
	// - ���� ����

	// �迭
	// �迭�����δ� ������ �����ϱ� ��ƴ�.
	const int MAX_SIZE = 10;
	int arr[MAX_SIZE] = { };

	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i] << endl;
	}

	// ���� �迭
	// vector�� ���ø����� ������� �ִ�.
	// ���ø� Ŭ�����̴�. 
	// ����ó�� ����� �þ�� �پ������.
	// �ſ� �ſ� �߿��� ���� -> � ������ �ηȱ淡 �迭�� '����������' ����� ���ΰ�?

	// 1) (�������� �ΰ�) �޸𸮸� �Ҵ��Ѵ�.
	// 2) �����б��� �� á����, �޸𸮸� �����Ѵ�.
	// ����
	int arr1[100];
	int* arr2 = new int[100];
	delete arr2;
	arr2 = new int[1000];
	// Q1) �������� ��ŭ�� �����ұ�?
	// Q2) ������ ��ŭ �ؾ� �ұ�?
	// Q3) ������ �����͸� ��� ó���ұ�?

/*
	vector<int> v; 
	v.push_back(1);// �о�־���
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	// TMI : if		|	while	|	for		| do-while---> Tab Ű ������ �ڵ��ϼ�

	int vectorSize = v.size();

	for (int i = 0; i < vectorSize; i++)
	{
		cout << v[i] << endl;
	}
*/


	vector<int> v;

	cout << v.size() << " " << v.capacity() << endl; // �ʹݿ��� 0 0 �̴�.

	// size : ���� ��� ������ ����
	// 1 2 3 4 5 6....
	// capacity : �������� ������ �뷮 ����
	// 1 2 3 4 5 9 13 19 28 42 63---> ���� 1.5�辿 �ø�. (�̻� ���(���� ���)�� �����ϱ� ���ؼ�)



	v.resize(1000);// vector�� size�� ������ ����
	vector<int> v2(1000);// �̷��� resize �Ҽ��� �ִ�.

	vector<int> v3(1000, 0);// �̷��� resize �Ҽ��� �ִ�. �׸��� 0 ���� �ʱ�ȭ. ���ϴ� ������ �ʱ�ȭ �� �� �ִ�.
	
	vector<int> v4 = v;// v�� v4�� ���縦 �Ѵ�.

	cout << "v2 size and capacity" << endl;
	cout << v2.size() << " " << v2.capacity() << endl; // resize �� �ϸ�, �ڵ�����capacity�� �þ.


	v.reserve(1000); // ó������ capacity�� 1000���� ����.!

	cout << v.size() << " " << v.capacity() << endl; // resize �� �ϸ�, �ڵ�����capacity�� �þ.
	
	for (int i = 0; i < 1000; i++)
	{
		// v[i] = 100;// �̹�resize�� �κп��� ���� �����ϱ�
		v.push_back(100);// ���࿡ resize(1000)�� ������ 1001��°�� ���Եȴ�.
		cout << v.size() << " " << v.capacity() << endl;
	}

	// size�� �پ����� capacity�� �پ���� �ʴ´�.

	//v.clear();// data ������ --> size �� 0�� ��
	
	// ���࿡ capacity���� �ٿ��ְ� ������?
	v.clear();
	//vector<int> v2 = v;


	vector<int>().swap(v);// ���뺤���ϰ� v �� swap��.
	// vector<int>() : �̰Ŵ� �ӽú�����. ���⿡�� �ƹ��� ������ ����. �ӽ� �����̹Ƿ� ������ ������ �Ҹ�ȴ�.
	cout << v.size() << " " << v.capacity() << endl;
	//cout << v2.size() << " " << v2.capacity() << endl;

	/*************************************/
	v.front();
	v.back();

	v.pop_back();// �������� �ִ� �����͸� ������.
	/****************************************/


	/*
	C++ STL(Standard Template Library)���� back()�� pop_back()�� �� �� ������ �����̳��� std::vector, std::deque, std::list ��� ����� �� �ִ� ��� �Լ��Դϴ�. �׷��� �׵��� ���Ұ� ������ �ٸ��ϴ�.

back():

back() �Լ��� �����̳��� ������ ��ҿ� �����Ͽ� �� ���� ��ȯ�մϴ�.
�����̳��� ������ ��Ҹ� �������� ������, �����̳ʸ� �������� �ʽ��ϴ�.
���� ���, std::vector<int> myVector = {1, 2, 3};�� �ִٸ�, myVector.back()�� 3�� ��ȯ�մϴ�.
pop_back():

pop_back() �Լ��� �����̳��� ������ ��Ҹ� �����մϴ�.
�����̳��� ũ�⸦ �ϳ� ���̰�, ������ ��Ұ� �����˴ϴ�.
���� ���, std::vector<int> myVector = {1, 2, 3};�� �ִٸ�, myVector.pop_back()�� ȣ���ϸ� myVector�� ���� {1, 2}�� �˴ϴ�.
������ ���ϸ�, back()�� ������ ����� ���� ���� �� ����ϰ�, pop_back()�� ������ ��Ҹ� ������ �� ����մϴ�. �� �� �Լ��� �ַ� ������ �����̳ʿ��� �۾��� ������ �� �����մϴ�.
	
	*/


	return 0;
}