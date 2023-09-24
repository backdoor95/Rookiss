#include<iostream>
using namespace std;
#include<vector>
// ������ ���� :Vector02


int main()
{

	/// �������� ��û ���� ����.!!
	//�����̳� (Container) : �����͸� �����ϴ� ��ü(�ڷᱸ�� Data Structure)
	// vector(���� �迭)
	// - vector�� ���ۿ���(size/capacity)
	// - �߰� ����/ ����
	// - ó��/�� ����/����
	// - ���� ����


	// �����̳� ���� �ݺ��ڸ� ����ִ�.
	// �ݺ���(iterator) : �����Ϳ� ������ ����. �����̳��� ����(������)�� ����Ű��, ����/���� ���ҷ� �̵� ����
	vector<int> v(10);//size 10��

	v.reserve(1000);// capacity 1000 ����

	for (int i = 0; i < v.size(); i++) // ���⼭ ��� ��!
	{
		v[i] = i;
	}

	// �ذ�� 1. 
	for (int i = 0; i < static_cast<unsigned int>(v.size()); i++)
	{
		v[i] = i;
	}

	// �ذ�� 2.
	// size_type�� �����ָ� �˸��� Ÿ���� �����ش�.
	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		v[i] = i;
	}

	// using �� typedef�� ������ ����� �ϴ� ���̴�. c++11 ���� ����.
	// �����Ϳ� ���ͷ����� ��
	// �°� �����̳ʵ��� �ڽŸ��� ���ͷ����͸� ������ �ִ�.
	vector<int>::iterator it;
	int* ptr;

	// ���͵� ���������� �迭�� ������.

	it = v.begin();// ������ ���ͷ����͸� ��ȯ
	ptr = &v[0];

	// �����ʹ� �� �״�� ���δ��� ���� ����.
	// ���ͷ����ʹ� ������ �Ҽӵ� �׷� ���ͷ����ʹ� ��� ���̰� �ִ�.

	// ���ͷ����͸� ������ ���� ��밡����. ���ͷ����Ͱ� ���������� �����͸� ��� ����.

	cout << *it << endl;
	cout << *ptr << endl;

	it++;// ���� �����ͷ� �̵��϶�� �ǹ�
	++it;

	ptr++;//���� �����ͷ� �̵��϶�� �ǹ�
	++ptr;

	it--;
	--it;
	ptr--;
	--ptr;// �ڷΰ���

	it += 2;// �������� �����ͷ� �̵�
	it = it - 2;// �ڷεڷ� �̵�

	ptr += 2;
	ptr = ptr - 2;


	vector<int>::iterator itBegin = v.begin(); // ó����
	vector<int>::iterator itEnd = v.end(); // ���⿡�� �ش� �迭�� ������ �������� ����ִ�. ��, �����Ⱚ�� ����ִ�.


	// vector<int>::iterator ���߿�  auto�� �ٲܼ� �ִ�.!!!
	// �� ������ ���̴µ� �� �̰ɾ���?
	// iterator�� vector�� �ƴ϶�, �ٸ� �����̳ʿ��� ���������� �ִ� ����
	// STL �����ؼ� ���ϼ��� ����� ������ �ٸ� �ڷᱸ���� �ٸ� �����̳ʷ� �Ѿ�� ������ ��������.
	// cf) �ٸ� �����̳ʴ� v[i]�� ���� �ε��� ������ �� �� ���� ����.
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)// ++it �� it++ ���� ��¦ ����
	{
		cout << (*it) << endl;
	}
	/*
	    _CONSTEXPR20 _Vector_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _CONSTEXPR20 _Vector_iterator operator++(int) noexcept {
        _Vector_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }
	
	*/

	int* ptrBegin = &v[0];// v.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10;// v.end()._Ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ptr++)
	{
		cout << *ptr << endl;
	}


	// const int* ;
	// �����͸� �������� �ʰ�, �б⸸ ����
	vector<int>::const_iterator cit1 = v.cbegin();
	// *cit1=100;// �̰� �ȵ�.

	// ������ �ݺ���
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
	{
		cout << *it << endl;
	}

	//  ---- Vector 03 Start----
	// - �߰� ����/ ���� (BAD) ������ ����.
	// - ó��/�� ����/����
	// - ���� ����(Random Access)

	// vector = ���� �迭 = �������� Ŀ���� �迭 = �迭
	// ���Ұ� �ϳ��� �޸� ��ΰ� �����ϰ� ����ȴ�!!


	// 1. [-�߰� ���� / ����(BAD) ������ ����.]---> ��ȿ�������� ����
	// [							]
	// [0] [1] [2] [3] [4] [] []
	// [0] [1] [] [2] [3] [4] []// �ش� ���Ҹ� ä��� ���ؼ� ���� ���Ұ� ����������.
	// [0] [1] [5] [2] [3] [4] []


	// 2. [- ó��/�� ����/����]
	//  1) ó�� ����/�����ϴ°� BAD
	//  2) ���� ����/�����ϴ°� GOOD
	//v.push_back(1);
	//v.pop_back();// v.push_front �� ����!!! ��ȿ�����̱� ����


	// 3. [ - ���� ����]
	v[2] = 3;
	// List �� �ٸ� �����̳ʵ��� �̷� ���������� �Ұ����ϴ�.

	// 2��°�� 5 �����ϰ�, 2��° ���ͷ����� ��ȯ
	vector<int>::iterator insertIt = v.insert(v.begin()+2, 5	);// 2��°�� 5�� �־�� �׸��� ���� 2���� �ִ� ���� ���ķ� ��ĭ�� �ڷ� �з���.
	
	// ������ ��ġ�� ��ȯ
	vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);
	
	// ������ ��ġ�� ��ȯ
	vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4);// v.begin() + 4 �̰Ŵ� ���Ե��� �ʴ´�.!!!

	// ���࿡ �ٸ����� capacity�� �� ���� ������ ���� �޸� ������ ����������(dddddddd, dddddddd, ..._ �̷������� ���ֹ���)
	// �޸𸮸� ���� �����ϰ� �ű⿡ �����Ѵ�.

	// ��~ ��ĵ�� �ϸ鼭, 3�̶�� �����Ͱ� ������ �ϰ� �����ϰ� �ʹ�.
	// ���� �����ڵ� �ϴ� �Ǽ�!!!
	for (vector<int>::iterator it = v.begin(); it < v.end();)// ++it �� ����, else ���� �־���.
	{
		int data = *it;
		if (data == 3)
		{
			//v.erase(it);// ���ͷ����ʹ� erase�ϴ� ���� ��ȿ���� ����. it�� Myprocy �� null �� �ٲ�� ������ ++it �Ҷ�, crash�� �Ͼ.
			//break;// 1. break�� �ؼ� ���������ų�
			it = v.erase(it);// �̷��� �Ǹ� Myproxy�� null �� �ƴϴ�.!!
		}
		else
		{
			++it;
		}

	}

	// v.clear() �ϸ� ���;���. break�� 

	return 0;
}