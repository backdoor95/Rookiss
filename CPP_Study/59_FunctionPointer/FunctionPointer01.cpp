#include<iostream>
using namespace std;

// ������ ���� : �Լ� ������

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{
public:
	Item(): _itemId(0), _rarity(0), _ownerId(0)
	{

	}

public:
	int _itemId;// �������� �����ϱ� ���� ID
	int _rarity;// ��͵�
	int _ownerId;// ������ ID
};

/// �̷��� ����� �Լ�(�ݺ����� �ڵ�)�� ������ ���������, �Լ� �����Ͱ� �����ϴ�.
// ����� �Լ�(�ݺ����� �ڵ�)�� ������ ���������, ���� ������ �������� ���� �߻� Ȯ�� ����!!


Item* FindItemByRarity(Item items[], int itemCount, int rarity)
{
	// ���� üũ

	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		//TODO
		if (item->_rarity == rarity)
			return item;

	}

	return nullptr;
}

Item* FindItemByItemId(Item items[], int itemCount, int itemId)
{
	// ���� üũ

	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		//TODO
		if (item->_itemId == itemId)
			return item;

	}

	return nullptr;
}


//Item* FindItem(Item items[], int itemCount, bool (*selector)(Item* item))// ��� 1.
//{
//	// ���� üũ
//	
//	for (int i = 0; i < itemCount; i++)
//	{
//		Item* item = &items[i];
//		//TODO
//
//	}
//
//	return nullptr;
//}

//[ Ver 2.1 ]
//typedef bool(ITEM_SELECTOR)(Item* item); 
//
//Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector)// ��� 2.
//{
//	// ���� üũ
//
//	for (int i = 0; i < itemCount; i++)
//	{
//		Item* item = &items[i];
//		if (selector(item))
//			return item;
//		//TODO
//
//	}
//
//	return nullptr;
//}

// [Ver 2.2]
typedef bool(ITEM_SELECTOR)(Item*, int);

Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value)// ��� 2.
{
	// ���� üũ

	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		if (selector(item, value))
			return item;
		//TODO

	}

	return nullptr;
}

bool IsRareItem(Item* item, int value)
{
	return item->_rarity >= value;
}

bool IsOwnerItem(Item* item, int ownerId)
{
	return item->_ownerId==ownerId;
}

int main()
{
	int a = 10;

	// �ٱ���
	// pointer : �ּҸ� Ÿ�� ���� int�� �����Ŵ� ��� �ǹ�

	typedef int DATA;// DATA�� int�� ����� �� �ִ�.

	// 1) ������		*
	// 2) ���� �̸�		pointer
	// 3) ������ Ÿ��	int
	
	//int* pointer = &a;
	DATA* pointer = &a;

	

	// �Լ�
	typedef int(FUNC_TYPE2)(int);

	typedef int(FUNC_TYPE)(int a, int b);// ���⼭ a, b�� �����. (int, int) ---> ok
	//using FUNC_TYPE = int(int a, int b);// ��� c++ ���

	// 1) ������		*
	// 2) ���� �̸�		fn
	// 3) ������ Ÿ��	�Լ� (���ڴ� int, int ��ȯ�� int)

	FUNC_TYPE* fn;
	fn = Add; // �̰� �ٷ� �Լ� ������!!!!

	fn = Sub;// ���� �Լ��� �߿��� �ϳ��� ������� �̷��� ȣ���ϰԲ� ���� ��, Ȱ���� �� �ִ�.!!!


	// �Լ��� �̸��� �Լ��� ���� �ּ� (�迭�� ����)
	int result = Add(1, 2);

	int result2 = fn(1, 2);// �⺻ ����

	int result3 = (*fn)(1, 2);// �Լ� �����ʹ� *(���� ������) �پ �Լ� �ּ�!! --> ��������� fn(1,2)�� ������.!!




	/*
	int result = Add(1, 2);
0079196C  push        2
0079196E  push        1
00791970  call        Add (07911CCh) --> call �� �ϸ� Add�� �ּҷ� �̵�
00791975  add         esp,8
00791978  mov         dword ptr [result],eax
	
	*/
	cout << result << endl;

	cout << result2 << endl;


	Item items[10] = {};
	items[3]._rarity = 2;// RARE
	//Item* rareItem = FindItem(items, 10, IsRareItem);// ��ȭ�� ���� IsRareItem�� �������� --> Ver 2.1
	Item* rareItem2 = FindItem(items, 10, IsOwnerItem, 100);// ��ȭ�� ���� IsRareItem�� �������� --> Ver 2.2
	Item* rareItem3 = FindItem(items, 10, IsRareItem, 2);// ��ȭ�� ���� IsRareItem�� �������� --> Ver 2.2










	return 0;
}