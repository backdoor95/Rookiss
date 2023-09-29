#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<map>
#include<set>
#include<algorithm>

// 오늘의 주제 : 스마트 포인터 (smart pointer)
class Knight
{
public:
	Knight() { cout << "Knight 생성" << endl; }
	~Knight() { cout << "Knight 소멸" << endl; }


	void Attack()
	{
		if (_target.expired() == false)
		{
			shared_ptr<Knight> sptr = _target.lock();
			//그 다음에 얘를 다시 활용하고 싶으면 점을 찍어보면 Lock이라는 기능이 있는데 Lock을 사용

			sptr->_hp -= _damage;
			cout << "HP: " << sptr->_hp << endl;
		}
	}

public:
	int _hp = 100;
	int _damage = 10;
	weak_ptr<Knight> _target;
};

class RefCountBlock
{
public:
	int _refCount = 1;// 객체를 기억하고 있는 카운트 0 이되면 아무도 그 객체를 기억하고 있지않음을 의미
	// 0이 아니면 절대로 삭제하면 안됨.
	int _weakCount = 1;
};

template<typename T>
class SharedPtr // Shared_ptr 구현하는 클래스 이건 완벽하지는 않지만 예시임.
{
public:
	SharedPtr(){ }
	SharedPtr(T* ptr): _ptr(ptr)
	{
		if (_ptr != nullptr)
		{
			_block = new RefCountBlock();
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	// 복사 생성자
	SharedPtr(const SharedPtr& sptr) : _ptr(sptr._ptr), _block(sptr._block)
	{
		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	// 복사대입연산자
	void operator=(const SharedPtr& sptr)
	{
		_ptr = sptr._ptr;
		_block = sptr._block;

		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}


	~SharedPtr()
	{
		if (_ptr != nullptr)
		{
			_block->_refCount--;
			cout << "RefCount : " << _block->_refCount << endl;
			if (_block->_refCount == 0)
			{
				delete _ptr;
				delete _block;
				cout << "Delete Data" << endl;
			}
		}
	}


public:
	T* _ptr = nullptr;
	RefCountBlock* _block = nullptr;
};



int main()
{

	//Knight* k1 = new Knight();
	//Knight* k2 = new Knight();

	//k1->_target = k2;

	//delete k2;

	//k1->Attack();

	// 요즘 현대적인c++에서는 그냥 포인터를 사용안한다.
	// 반드시 스마트 포인터로 간접적으로 사용한다.!!
	// 언리얼 엔진도 스마트 포인터 이용 ---> 안정성 중시


	// 스마트 포인터란?
	// 포인터를 알맞는 정책에 따라 관리하는 객체 (포인터를 래핑해서 사용)
	// shared_ptr( 스마트 포인터의 맏형급), weak_ptr, unique_ptr

	//SharedPtr<Knight> k2;
	//{
	//	SharedPtr<Knight> k1(new Knight());
	//	k2 = k1; /// 복사 대입 연산자
	//}

	shared_ptr<Knight> k1 = make_shared<Knight>();// make_shared를 쓰는게 성능이 좋다.
	// 나이트를 만들어 준 거와 함께 메모리 블록을 같은 메모리에다가 넣어진다.

	{
		shared_ptr<Knight> k2 = make_shared<Knight>();
		k1->_target = k2;
	}
	// 아무도 기억하고 있지 않을때만 지울수 있다.

	// shared, weak는 둘다 세트라고 보면됨.
	// shared_ptr은 사이클 문제에 대한 해결이 될 수 없다!
	// ex) k1이 k2를 주시
	//		k2가 k1을 주시
	// 순환 문제가 생기면 메모리가 절대로 어떤 이유에서든 삭제가 되지 않은 문제 발생

	// 그래서 순환 구조를 끊어줘야함.
	{
		shared_ptr<Knight> k1 = make_shared<Knight>();
		shared_ptr<Knight> k2 = make_shared<Knight>();
		k1->_target = k2;
		k2->_target = k1;

		k1->Attack();
		// 순환 구조 끊기
		k1->_target = nullptr;
		k2->_target = nullptr;
	}

	{
		// weak , shared 포인터가 같이 관리하고 있었는데 이제 위크 카운터라는게 하나가 더 추가됨!


	}
	//유니크해야 된다 이 전 세상에서 나만 이 포인터를 가리키고 있어야 된다고 할 때 이 유니크 PTR 활용

	unique_ptr<Knight> uptr = make_unique<Knight>();
	unique_ptr<Knight> uptr2 = uptr;// 오류발생
	unique_ptr<Knight> uptr2 = move(uptr);// 오른값이면 오류발생 하지 않음

	return 0;
}