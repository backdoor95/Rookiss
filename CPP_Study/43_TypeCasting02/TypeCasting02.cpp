#include<iostream>
using namespace std;

// 오늘의 주제 : 타입 변환(포인터)

class Knight
{
public:
	int _hp = 0;
};


class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const item&)" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int itemType)" << endl;
	}

	~Item()
	{
		cout << "~Item()" << endl;
	}

public:
	int _itemType = 0;
	int _timeDbId = 0;

	char _dummy[4096] = {};// 이런 저런 정보들로 인해 비대해진 클래스를 나타냄

};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
	}

	~Weapon()
	{
		cout << "~Weapon()" << endl;
	}
public:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}

	~Armor()
	{
		cout << "~Armor()" << endl;
	}

public:
	int _defence = 0;
	
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{

}

int main()
{

	//// 복습
	//{
	//	// Stack 메모리에 만들어짐
	//	// Stack [type(4) dbid(4) dummy(4096)]
	//	Item item;


	//	// Stack [ 주소 (4바이트 or 8바이트) ] -> Heap[type(4) dbid(4) dummy(4096)]
	//	Item* item2 = new Item();

	//	TestItem(item); // 어마어마하게 큰 놈을 복사해서 넘겨준다.
	//	TestItem(*item2);
	//	/*console output
	//	Item()
	//	Item()
	//	Item(const item&)
	//	~Item()
	//	Item(const item&)
	//	~Item()
	//	*/

	//	TestItemPtr(&item);
	//	TestItemPtr(item2);
	//	/* console output
	//	~Item()
	//	~Item()
	//	*/

	//	// 메모리 누수 (Memory Leak) -> 점점 가용 메모리가 줄어들어서 Crash
	//	delete item2;

	//}

	//// 배열
	//{
	//	cout << "--------------------------------------------1" << endl;

	//	// 진짜 아이템이 100개 있는 것( 스택 메모리에 올라와 있는)
	//	Item item3[100] = {};

	//	cout << "--------------------------------------------2" << endl;

	//	// 아이템 100개 있을까요?
	//	// 아이템을 가리키는 바구니가 100개. 실제 아이템은 1개도 없을 수도 있음.
	//	Item* item4[100] = {};

	//	for (int i = 0; i < 100; i++)
	//	{
	//		item4[i] = new Item();
	//	}

	//	cout << "--------------------------------------------3" << endl;

	//	for (int i = 0; i < 100; i++)
	//	{
	//		delete item4[i];
	//	}

	//	cout << "--------------------------------------------4" << endl;
	//}



	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{
		// Stack [ 주소 ] -> Heap [ _hp(4) ]
		Knight* knight = new Knight();

		// 암시적으로는 NO
		// 명시적으로는 OK

		//Stack [ 주소 ] 

		/*
		Item* item = (Item*)knight;
		item->_itemType = 2;
		item->_timeDbId = 1;
		*/

		// 메모리를 오염시켜서 엉뚱한 곳에서 터지면 찾는게 매우 어렵다.
		// 컴파일러가 찾아줄수도 있고, 아닐수도 있다.
		/*
		0x0166291C  fdfdfdfd  ???? --> 일반적으로 이런 묘한 값들은 디버그 모드에서 컴파일러가 알아서 추가해줌 -
		0x01662920  00000000  ....
		0x01662924  fdfdfdfd  ???? --> 만약에 이 영역을 건드리게 된다면 터트리게 될것이다.
		--> 경우에 따라서 터질수도 있고, 안터질수도 있다.
		*/

		delete knight;

	}


	// 부모 -> 자식 변환 테스트
		// 암시적으로는 NO
		// 명시적으로는 OK
	{
		Item* item = new Item();

		// [ [ Item ] ]
		// [	_damage	]
		//Weapon* weapon = (Weapon*)item;
		//weapon->_damage = 10;// crash 발생!!

		delete item;
	}

	// 자식 -> 부모 변환 테스트
	{
		// [ [ Item ] ]
		// [	_damage	]
		Weapon* weapon = new Weapon();

		// 암시적으로도 된다!
		Item* item = weapon;

		delete weapon;
	}


	// 명시적으로 타입 변환할 때는 항상 항상 조심해야 한다!
	// 암시적으로 될 때는 안전하다?
	// -> 평생 명시적으로 타입 변환(캐스팅)은 안 하면 되는거 아닌가?


	Item* inventory[20] = {};

	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2;
		switch (randValue)
		{
		case 0:
			inventory[i] = new Weapon();
			break;
		case 1:
			inventory[i] = new Armor();
			break;
		}
	}






	return 0;
}