#include<iostream>
using namespace std;
#include<vector>

// ������ ���� : vector ���� ������

template<typename T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr)
	{

	}

	Iterator(T* ptr) : _ptr(ptr)
	{

	}

	Iterator& operator++()// �������� �������� ����
	{
		_ptr++;
		return *this;
	}

	Iterator operator++(int)// �������� ���簪�� ����
	{
		Iterator temp = *this;// ������ ������ ��
		_ptr++;
		return temp;// ���ϱ� �������� ��ȯ
	}

	Iterator& operator--()// �������� �������� ����
	{
		_ptr--;
		return *this;
	}

	Iterator operator--(int)// �������� ���簪�� ����
	{
		Iterator temp = *this;// ������ ������ ��
		_ptr--;
		return temp;// ���ϱ� �������� ��ȯ
	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	Iterator operator-(const int count)
	{
		Iterator temp = *this;
		temp._ptr -= count;
		return temp;
	}

	bool operator==(const Iterator& right)
	{
		return _ptr == right._ptr;
	}

	bool operator!=(const Iterator& right)// ver 1.0
	{
		return _ptr != right._ptr;
	}

	//bool operator!=(const Iterator& right)// ver 2.0 
	//{
	//	return !(*this == right);// �̰Ŵ� bool operator==(const Iterator& right) �̰Ÿ� ȣ���ؼ� �����ϴ� ���� [!]�ؼ� ��ȯ
	//}

	T& operator*()// data�� �������� ����
	{
		return *_ptr;
	}


public:
	T* _ptr;

};

template<typename T>
class Vector
{
public:

	Vector() : _data(nullptr), _size(0), _capacity(0)
	{

	}

	~Vector()
	{
		if (_data)// 0�� �ƴ��� üũ if(_data != nullptr) �� �����ǹ�
			delete[] _data;

	}

	void push_back(const T& val)// ������ ���� ����� ���ؼ� reference�� ����
	{
		if (_size == _capacity)
		{
			// ���� �۾�
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		_data[_size] = val;// ������ ����
		_size++;// ���� ����

	}

	void reserve(int capacity)// �����۾�
	{
		_capacity = capacity;

		T* newData = new T[_capacity];

		// ������ ����
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		// ������ �ִ� ������ ������.
		if (_data)
			delete[] _data;

		// ��ü �Ϸ�
		_data = newData;
	}

	T& operator[](const int pos)// reference�� �����ؾ���.
	{
		return _data[pos];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

public:
	typedef Iterator<T> iterator;
	void clear() { _size = 0; }
	iterator begin() { return iterator(&_data[0]); }// ************ �� �κ��� ���ذ� �Ȱ�. 
	iterator end() { return begin() + _size; }



private:
	T* _data;
	int _size;
	int _capacity;

};


int main()
{


	//int a = 1;
	//++(++a);// �������� ����
	//(a++)++;// �̰Ŵ� �ȵ�! �������� ��ø �ȵ�.



	Vector<int> v;

	v.reserve(100);

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << "------------------------" << endl;

	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << endl;
	}

	v.clear();// data�� ������ ���������� Capacity�� �״�� ���� ���·� �д�.

	return 0;
}