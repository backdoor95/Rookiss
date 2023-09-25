#include<iostream>
using namespace std;
#include<vector>

// 오늘의 주제 : vector 직접 만들어보기

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

	Iterator& operator++()// 전위형은 참조값을 리턴
	{
		_ptr++;
		return *this;
	}

	Iterator operator++(int)// 후위형은 복사값을 리턴
	{
		Iterator temp = *this;// 원본을 복사한 값
		_ptr++;
		return temp;// 변하기 이전값을 반환
	}

	Iterator& operator--()// 전위형은 참조값을 리턴
	{
		_ptr--;
		return *this;
	}

	Iterator operator--(int)// 후위형은 복사값을 리턴
	{
		Iterator temp = *this;// 원본을 복사한 값
		_ptr--;
		return temp;// 변하기 이전값을 반환
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
	//	return !(*this == right);// 이거는 bool operator==(const Iterator& right) 이거를 호출해서 리턴하는 값을 [!]해서 반환
	//}

	T& operator*()// data의 참조값을 리턴
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
		if (_data)// 0이 아닌지 체크 if(_data != nullptr) 랑 같은의미
			delete[] _data;

	}

	void push_back(const T& val)// 조금의 성능 향상을 위해서 reference로 받음
	{
		if (_size == _capacity)
		{
			// 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		_data[_size] = val;// 데이터 저장
		_size++;// 개수 증가

	}

	void reserve(int capacity)// 증설작업
	{
		_capacity = capacity;

		T* newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}

		// 기존에 있던 데이터 날린다.
		if (_data)
			delete[] _data;

		// 교체 완료
		_data = newData;
	}

	T& operator[](const int pos)// reference로 리턴해야함.
	{
		return _data[pos];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

public:
	typedef Iterator<T> iterator;
	void clear() { _size = 0; }
	iterator begin() { return iterator(&_data[0]); }// ************ 이 부분이 이해가 안감. 
	iterator end() { return begin() + _size; }



private:
	T* _data;
	int _size;
	int _capacity;

};


int main()
{


	//int a = 1;
	//++(++a);// 전위형은 가능
	//(a++)++;// 이거는 안됨! 후위형은 중첩 안됨.



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

	v.clear();// data를 날리되 실질적으로 Capacity는 그대로 냅둔 상태로 둔다.

	return 0;
}