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

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

	// virtual를 붙이면 가상함수가 됨.
	// 객체 자체에 가상함수 테이블이 만들어진다.
	// 실행되어야할  함수가 어떤건지 따로 관리하게됨.
	virtual void Test()
	{
		cout << "Test Item" << endl;
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
		_damage = rand() % 100;
	}

	virtual ~Weapon()
	{
		cout << "~Weapon()" << endl;
	}

	virtual void Test()
	{
		cout << "Test Weapon" << endl;
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

	virtual ~Armor()
	{
		cout << "~Armor()" << endl;
	}

public:
	int _defence = 0;
	
};

void TestItem(Item item)// 복사 생성자를 호출한다. 그래서 이 함수가 끝날때 소멸자도 호출됨.
{

}

void TestItemPtr(Item* item)// 포인터로 할때는 복사 생성자가 호출이 안됨!
{
	item->Test();
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

		TestItemPtr(item);
		// 가상함수를 이용하면 원본타입의 함수를 호출할 수 있다.

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


	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}

	// *********************************** 매우 매우 매우 중요 ****************************************
	

	//for (int i = 0; i < 20; i++)
	//{
	//	Item* item = inventory[i];
	//	if (item == nullptr)
	//		continue;

	//	//delete item; // 원본을 지워야함.! 이것만 하면 item의 소멸자만 호출됨.!1

	//	if (item->_itemType == IT_WEAPON)
	//	{
	//		Weapon* weapon = (Weapon*)item;
	//		delete weapon;
	//	}
	//	else
	//	{
	//		Armor* armor = (Armor*)item;
	//		delete armor;
	//	}
	//}

	cout << "**************************************매우 매우 매우 중요*******************************************" << endl;

	// 생성자&소멸자는 함수!!!****************
	// 가상함수 적용이 가능!!!
	// 소멸자에도 똑같은 룰 적용!!
	// 어떤 상속 관계가 있을때, 무조건! 최상위 부모의 소멸자에 virtual 를 붙이자!!!
	// 나머지 자식도 virtual를 붙이게 되는 셈이다.
	// 소멸자 자체도 가상함수로 인식이 됨.
	// 위에 처럼 캐스팅을 안해도됨!!

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];
		if (item == nullptr)
			continue;

		delete item; // 가상함수를 적용하면 이렇게 해도됨.!!
	}

	// [결론]
	// - 포인터 vs 일반 타입 : 차이를 이해하자
	// - 포인터 사이의 타입 변환(캐스팅)을 할 때는 매우 매우 조심해야 한다!!
	// - 부모-자식 관계에서 부모 클래스의 소멸자에는 까먹지 말고 virtual을 붙이자!!!
	// 무조건 소멸자에는 virtual를 붙인다고 외우지 말자!! 이해를 하자
	// 상속관계에 의해 함수를 재정의 해봤자
	// 어떤 타입에 따라서 어떤 한 애만 골라서 실행이되기 때문에 
	// virtual를 붙여주게 되면, 가상함수 테이블이 만들어지면서 실제 객체가 어떤 놈으로 만들졌냐에 따라서 함수를 찾아서 호출하게 된다.
	// 면접 단골 질문이다!!!!

	return 0;
}