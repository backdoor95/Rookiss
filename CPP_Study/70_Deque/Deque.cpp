#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<deque>

// ������ ���� : deque

// deque : double ended queue  (vector�� list�� �߰� ����) «�͵� �����ε� �����ʿ� ������.
// �� : ��������� ťó�� ���
// deque�� �迭����, �뷮�� ��á����, �ٸ������� ������. �ٵ� ������ �ִ��� �����ϰ� �����ϴ°� �ƴϴ�. �߰��ϱ����� ������ ����
// ���� �ϳ� ���� �̾���δٰ� �����ϸ��. 
// [		]
// [		]
// [		]
// [		]
// vector�� ������ ������ ������.

int main()
{
	// ������ �����̳� 
	// �����Ͱ� ���� ������� �����Ǵ� ����
	// vector / list / deque

	deque<int> dq;

	dq.push_back(1);
	dq.push_front(2);
	cout << dq[0] << endl;

	// vector�� ���������� �迭 ������� ����
	// �ٸ� �޸� �Ҵ� ��å�� �ٸ���.

	// vector
	// ������ �ϰ� ������ ����
	vector<int>v(3, 1);// ũ�� 3, 1�� �ʱ�ȭ
	// [1 1 1]

	//deque : �յڷ� ���� �ø��� �ִ�.
	// [    3 3]
	// [1 1 1 2]
	// [2      ]
	deque<int> dq(3, 1);

	v.push_back(2);
	v.push_back(2);

	dq.push_back(2);
	dq.push_back(2);

	dq.push_front(3);
	dq.push_front(3);

	// - deque�� ���� ����
	// - �߰� ����/���� [BAD / BAD] vector�� ���������� ��ĭ�� ���ܿ;���.
	// - ó��/�� ����/���� [GOOD/GOOD]
	// - ���� ���� (GOOD)
	// �ʿ������� �߰� ����/������ ���������� ���������� ������ �����ϱ� ���� ����!!

	dq[3] = 10;
	cout << dq[3] << endl;

	deque<int>::iterator it;

	/*
	    _Size_type _Block = _Mycont->_Getblock(_Myoff);//� ��Ͽ� �Ҽ��� �Ǿ��ִ��� 
        _Size_type _Off   = _Myoff % _Block_size;// offset�� ���� ����.
        return _Mycont->_Map[_Block][_Off];// ex) �� �� , �� ȣ ---> ��������!
	
	*/
	// list�� ���� ������ �Ұ�!

	// ��ũ�� ��������� ����ϴ� ť��. 
	// ���ʹ� �տ��ٰ� �о�ִ°� �ſ� ����
	// ��ũ�� �տ� �о�ִ°� ����. ---> ��������� ������ �����ϴ°� ��������.

	return 0;
}