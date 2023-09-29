#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<map>
#include<set>
#include<algorithm>

// ������ ���� : ����Ʈ ������ (smart pointer)
class Knight
{
public:
	Knight() { cout << "Knight ����" << endl; }
	~Knight() { cout << "Knight �Ҹ�" << endl; }


	void Attack()
	{
		if (_target.expired() == false)
		{
			shared_ptr<Knight> sptr = _target.lock();
			//�� ������ �긦 �ٽ� Ȱ���ϰ� ������ ���� ���� Lock�̶�� ����� �ִµ� Lock�� ���

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
	int _refCount = 1;// ��ü�� ����ϰ� �ִ� ī��Ʈ 0 �̵Ǹ� �ƹ��� �� ��ü�� ����ϰ� ���������� �ǹ�
	// 0�� �ƴϸ� ����� �����ϸ� �ȵ�.
	int _weakCount = 1;
};

template<typename T>
class SharedPtr // Shared_ptr �����ϴ� Ŭ���� �̰� �Ϻ������� ������ ������.
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

	// ���� ������
	SharedPtr(const SharedPtr& sptr) : _ptr(sptr._ptr), _block(sptr._block)
	{
		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	// ������Կ�����
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

	// ���� ��������c++������ �׳� �����͸� �����Ѵ�.
	// �ݵ�� ����Ʈ �����ͷ� ���������� ����Ѵ�.!!
	// �𸮾� ������ ����Ʈ ������ �̿� ---> ������ �߽�


	// ����Ʈ �����Ͷ�?
	// �����͸� �˸´� ��å�� ���� �����ϴ� ��ü (�����͸� �����ؼ� ���)
	// shared_ptr( ����Ʈ �������� ������), weak_ptr, unique_ptr

	//SharedPtr<Knight> k2;
	//{
	//	SharedPtr<Knight> k1(new Knight());
	//	k2 = k1; /// ���� ���� ������
	//}

	shared_ptr<Knight> k1 = make_shared<Knight>();// make_shared�� ���°� ������ ����.
	// ����Ʈ�� ����� �� �ſ� �Բ� �޸� ����� ���� �޸𸮿��ٰ� �־�����.

	{
		shared_ptr<Knight> k2 = make_shared<Knight>();
		k1->_target = k2;
	}
	// �ƹ��� ����ϰ� ���� �������� ����� �ִ�.

	// shared, weak�� �Ѵ� ��Ʈ��� �����.
	// shared_ptr�� ����Ŭ ������ ���� �ذ��� �� �� ����!
	// ex) k1�� k2�� �ֽ�
	//		k2�� k1�� �ֽ�
	// ��ȯ ������ ����� �޸𸮰� ����� � ���������� ������ ���� ���� ���� �߻�

	// �׷��� ��ȯ ������ ���������.
	{
		shared_ptr<Knight> k1 = make_shared<Knight>();
		shared_ptr<Knight> k2 = make_shared<Knight>();
		k1->_target = k2;
		k2->_target = k1;

		k1->Attack();
		// ��ȯ ���� ����
		k1->_target = nullptr;
		k2->_target = nullptr;
	}

	{
		// weak , shared �����Ͱ� ���� �����ϰ� �־��µ� ���� ��ũ ī���Ͷ�°� �ϳ��� �� �߰���!


	}
	//����ũ�ؾ� �ȴ� �� �� ���󿡼� ���� �� �����͸� ����Ű�� �־�� �ȴٰ� �� �� �� ����ũ PTR Ȱ��

	unique_ptr<Knight> uptr = make_unique<Knight>();
	unique_ptr<Knight> uptr2 = uptr;// �����߻�
	unique_ptr<Knight> uptr2 = move(uptr);// �������̸� �����߻� ���� ����

	return 0;
}