#include<iostream>
using namespace std;

// ������ ���� : ������ �����ε�(Operator Overloading)

// ������ vs �Լ�
// - �����ڴ� �ǿ������� ���� / Ÿ���� �����Ǿ� ����.

// ������ �����ε�?
// �ϴ� [������ �Լ�] �� �����ؾ� ��.
// �Լ��� ����Լ� vs �����Լ��� �����ϴ°�ó��, ������ �Լ��� �ΰ��� ������� ���� �� ����.

// - ��� ������ �Լ� version
// -- a op b ���¿��� �������� �������� �����.(a�� Ŭ�������� ����. a�� '���� �ǿ�����'��� ��)
// -- �Ѱ�) a�� Ŭ������ �ƴϸ� ��� ����.

// - ���� ������ �Լ� version
// -- a op b ���¶�� a, b ��θ� ������ �Լ��� �ǿ����ڷ� ������ش�.


// �׷� � version�� ������? �׷��� ����. ������ �� �� �ϳ��� �����ϴ� ��쵵 �ֱ� ����.
// - ��ǥ������ ���� ������ ( a = b )�� ���� ������ version���δ� �� ����.


class Position
{
public:

	/*
	RET FUNC_NAME(ARG_LIST)
	{

	}
	
	*/
	//  	Position pos3 = pos + pos2; ���⼭ pos�̰� �������� 

	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;

		return pos;
	}

	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;

		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}

	void operator=(int arg)
	{
		_x = arg;
		_y = arg;
	}

public:
	int _x;
	int _y;


};

// �̷��Դ� �ȵ�.!!!
//void operator=(const Position&a,int b)
//{
//	a._x = b;
//	a._y = b;
//}

Position operator+(int a, const Position& b)
{
	Position ret;

	ret._x = b._x + a;
	ret._y = b._y + a;

	return ret;
}


int main()
{

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos + pos2;// ��� 1
	pos3 = pos.operator+(pos2);// ��� 2

	Position pos4 = pos3 + 1;
//	Position pos4 = 1 + pos3;//  �̰� �ȵ�. ���� ������� �ؾ��ϱ� ����
	// �̰� �Ƿ��� ���������� �Լ� �������� ��������.


	bool isSame = (pos3 == pos4);

	Position pos5;
	pos5 = 5;
//	Position pos5 = 5;
	// �̰Ŵ� �������� ���� 5�� �ʱ�ȭ �Ǵ� ����.
	// 5��� ���ڸ� �޴� �����ڸ� ã�Ե�.



	return 0;
}