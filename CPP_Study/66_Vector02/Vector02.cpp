#include<iostream>
using namespace std;
#include<vector>
// ������ ���� :Vector02


int main()
{
	//�����̳� (Container) : �����͸� �����ϴ� ��ü(�ڷᱸ�� Data Structure)
	// vector(���� �迭)
	// - vector�� ���ۿ���(size/capacity)
	// - �߰� ����/ ����
	// - ó��/�� ����/����
	// - ���� ����


	// �����̳� ���� �ݺ��ڸ� ����ִ�.
	// �ݺ���(iterator) : �����Ϳ� ������ ����. �����̳��� ����(������)�� ����Ű��, ����/���� ���ҷ� �̵� ����
	vector<int> v(10);//size 10��

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


	return 0;
}