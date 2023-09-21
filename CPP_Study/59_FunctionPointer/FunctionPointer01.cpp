#include<iostream>
using namespace std;

// 오늘의 주제 : 함수 포인터

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
	int _itemId;// 아이템을 구분하기 위한 ID
	int _rarity;// 희귀도
	int _ownerId;// 소지자 ID
};

/// 이렇게 비슷한 함수(반복적인 코드)가 여러개 만들어질때, 함수 포인터가 가능하다.
// 비슷한 함수(반복적인 코드)가 여러개 만들어질때, 유지 보수성 떨어지고 버그 발생 확률 증가!!


Item* FindItemByRarity(Item items[], int itemCount, int rarity)
{
	// 안전 체크

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
	// 안전 체크

	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		//TODO
		if (item->_itemId == itemId)
			return item;

	}

	return nullptr;
}


//Item* FindItem(Item items[], int itemCount, bool (*selector)(Item* item))// 방법 1.
//{
//	// 안전 체크
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
//Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector)// 방법 2.
//{
//	// 안전 체크
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

Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value)// 방법 2.
{
	// 안전 체크

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

	// 바구니
	// pointer : 주소를 타고 들어가면 int가 있을거다 라는 의미

	typedef int DATA;// DATA를 int로 사용할 수 있다.

	// 1) 포인터		*
	// 2) 변수 이름		pointer
	// 3) 데이터 타입	int
	
	//int* pointer = &a;
	DATA* pointer = &a;

	

	// 함수
	typedef int(FUNC_TYPE2)(int);

	typedef int(FUNC_TYPE)(int a, int b);// 여기서 a, b는 없어도됨. (int, int) ---> ok
	//using FUNC_TYPE = int(int a, int b);// 모던 c++ 방식

	// 1) 포인터		*
	// 2) 변수 이름		fn
	// 3) 데이터 타입	함수 (인자는 int, int 반환은 int)

	FUNC_TYPE* fn;
	fn = Add; // 이게 바로 함수 포인터!!!!

	fn = Sub;// 여러 함수들 중에서 하나를 골라가지고 이렇게 호출하게끔 만들 때, 활용할 수 있다.!!!


	// 함수의 이름은 함수의 시작 주소 (배열과 유사)
	int result = Add(1, 2);

	int result2 = fn(1, 2);// 기본 문법

	int result3 = (*fn)(1, 2);// 함수 포인터는 *(접근 연산자) 붙어도 함수 주소!! --> 어셈블리보면 fn(1,2)와 동일함.!!




	/*
	int result = Add(1, 2);
0079196C  push        2
0079196E  push        1
00791970  call        Add (07911CCh) --> call 를 하면 Add의 주소로 이동
00791975  add         esp,8
00791978  mov         dword ptr [result],eax
	
	*/
	cout << result << endl;

	cout << result2 << endl;


	Item items[10] = {};
	items[3]._rarity = 2;// RARE
	//Item* rareItem = FindItem(items, 10, IsRareItem);// 위화감 없이 IsRareItem을 전달해줌 --> Ver 2.1
	Item* rareItem2 = FindItem(items, 10, IsOwnerItem, 100);// 위화감 없이 IsRareItem을 전달해줌 --> Ver 2.2
	Item* rareItem3 = FindItem(items, 10, IsRareItem, 2);// 위화감 없이 IsRareItem을 전달해줌 --> Ver 2.2










	return 0;
}