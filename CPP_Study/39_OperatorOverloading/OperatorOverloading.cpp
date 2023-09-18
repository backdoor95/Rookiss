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


//  ���� ���� ������ *********** �����ϱ� ��ٷο�
//	- ���� �����ڰ� ���� �迡[���� ���� ������]�� ���� �˾ƺ���
//	�� �� �򰥸��� [���� ������] [���� ������] [���� ���� ������]
//	- ���� ���� ������ = ���� ������ ��, �ڱ� �ڽ��� ���� Ÿ���� ���ڷ� �޴� ��


// ��Ÿ
// - ��� �����ڸ� �� �����ε� �� �� �ִ� ���� �ƴϴ�((::) , (.) , (.*)  �̷��� �ȵ�.)
// - ��� �����ڰ� �� 2�� ���� �ִ� �� �ƴ�. ++,  -- �� ��ǥ��(���� ������)
// - ���� ������ ++ --
// -- ������(++a) operator++()
// -- ������(a++) operator++(int)
// (a++)++ : �̰� �ȵ�. -> ��� �ȵ�.
// ++(++a) : �̰� ��. -> ��� ��.


class Position
{
public:

	/*
	RET FUNC_NAME(ARG_LIST)
	{

	}
	
	*/
	//  	Position pos3 = pos + pos2; ���⼭ pos�̰� �������� 


	//Position(const Position& arg) // ���� ������
	//{

	//}


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


	Position& operator=(int arg)// void���� �ڱ� �ڽ��� ���������� ������ ���ִ� ��찡 ����
	{
		_x = arg;
		_y = arg;

		//Position* this = �� �ڽ��� �ּ�;

		return *this;//*************************
	}

	// [���� ������] [���� ���� ������] �� Ư�� ��츦 �޴� ������,
	// �� �״�� ��ü�� '����'�Ǳ� ���ϴ� Ư¡ ����.
	// TODO) �����Ҵ� �ð��� �� �ڼ��� �˾ƺ���
	Position& operator=(const Position& arg)// ���� ���� ������
	{
		_x = arg._x;
		_y = arg._y;

		//Position* this = �� �ڽ��� �ּ�;

		return *this;//*************************
	}


	//void operator++()// ++pos; - ������ 
	//{
	//	_x++;
	//	_y++;
	//}

	Position& operator++()// ++pos; - ������ // ++(++a) : �̰� ��. -> ��� ��. �׷��� void ���ٴ� �������� ��ȯ�ϴ� �������� �������.
	{
		_x++;
		_y++;
		return *this;
	}

	//void operator++(int) // pos++; - ������
	//{
	//	_x++;
	//	_y++;
	//}

	Position operator++(int) // pos++; - ������
	{
		// ���� Position& operator++(int) ���� �ٲٰ� �Ǹ�
		// ���� ���� �޸𸮿� �ִ� ret�� ��ȯ�ϰ� �Ǵµ�.
		// ret�� ��ȿ ������ {...}  �����̹Ƿ� �̰� �����ϰ� �Ǹ� ū�ϳ�.
		Position ret = *this;
		_x++;
		_y++;
		return ret;
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
	int a = 1;
	int c = (a = 3);

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos + pos2;// ��� 1
	Position pos3_1 = (pos.operator+(pos2));// ��� 2 --> �Ƹ��� ���翬������ '='�� ����ϴµ�
	Position pos3_2;
	pos3_2 = pos.operator+(pos2); // �̰� ���� ���� �����ڷ� �ν��� �Ǳ� ������ �ȵǴ� �ſ���.!!!
	pos3_2 = pos + pos2;

	Position pos4 = pos3 + 1;
//	Position pos4 = 1 + pos3;//  �̰� �ȵ�. ���� ������� �ؾ��ϱ� ����
	// �̰� �Ƿ��� ���������� �Լ� �������� ��������.


	bool isSame = (pos3 == pos4);

	Position pos5;
	pos5 = 5;
	pos3 = (pos5 = 5);
//	Position pos5 = 5;
	// �̰Ŵ� �������� ���� 5�� �ʱ�ȭ �Ǵ� ����.
	// 5��� ���ڸ� �޴� �����ڸ� ã�Ե�.

	//(Pos&)��~ : ����       (Pos) ���簪 �ٲ�~ : ������   �׷��� ������ �߻��Ѱ���.
	//(cost Pos&)��~ : ����       (Pos) ���簪 �ٲ�~ : ������  �̰� ������ �߻� ����.
	// �� ��쿡�� Ÿ���� ��ġ���� �ʾƵ� const�� ���̸� ������ �߻����� ����. 
	
	pos5 = pos3++;// 


	++(++pos3);


	return 0;
}