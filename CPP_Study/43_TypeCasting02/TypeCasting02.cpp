#include<iostream>
using namespace std;

// ������ ���� : Ÿ�� ��ȯ(������)

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

	char _dummy[4096] = {};// �̷� ���� ������� ���� ������� Ŭ������ ��Ÿ��

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

	//// ����
	//{
	//	// Stack �޸𸮿� �������
	//	// Stack [type(4) dbid(4) dummy(4096)]
	//	Item item;


	//	// Stack [ �ּ� (4����Ʈ or 8����Ʈ) ] -> Heap[type(4) dbid(4) dummy(4096)]
	//	Item* item2 = new Item();

	//	TestItem(item); // ���ϰ� ū ���� �����ؼ� �Ѱ��ش�.
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

	//	// �޸� ���� (Memory Leak) -> ���� ���� �޸𸮰� �پ�� Crash
	//	delete item2;

	//}

	//// �迭
	//{
	//	cout << "--------------------------------------------1" << endl;

	//	// ��¥ �������� 100�� �ִ� ��( ���� �޸𸮿� �ö�� �ִ�)
	//	Item item3[100] = {};

	//	cout << "--------------------------------------------2" << endl;

	//	// ������ 100�� �������?
	//	// �������� ����Ű�� �ٱ��ϰ� 100��. ���� �������� 1���� ���� ���� ����.
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



	// �������� ���� Ŭ���� ������ ������ ��ȯ �׽�Ʈ
	{
		// Stack [ �ּ� ] -> Heap [ _hp(4) ]
		Knight* knight = new Knight();

		// �Ͻ������δ� NO
		// ��������δ� OK

		//Stack [ �ּ� ] 

		/*
		Item* item = (Item*)knight;
		item->_itemType = 2;
		item->_timeDbId = 1;
		*/

		// �޸𸮸� �������Ѽ� ������ ������ ������ ã�°� �ſ� ��ƴ�.
		// �����Ϸ��� ã���ټ��� �ְ�, �ƴҼ��� �ִ�.
		/*
		0x0166291C  fdfdfdfd  ???? --> �Ϲ������� �̷� ���� ������ ����� ��忡�� �����Ϸ��� �˾Ƽ� �߰����� -
		0x01662920  00000000  ....
		0x01662924  fdfdfdfd  ???? --> ���࿡ �� ������ �ǵ帮�� �ȴٸ� ��Ʈ���� �ɰ��̴�.
		--> ��쿡 ���� �������� �ְ�, ���������� �ִ�.
		*/

		delete knight;

	}


	// �θ� -> �ڽ� ��ȯ �׽�Ʈ
		// �Ͻ������δ� NO
		// ��������δ� OK
	{
		Item* item = new Item();

		// [ [ Item ] ]
		// [	_damage	]
		//Weapon* weapon = (Weapon*)item;
		//weapon->_damage = 10;// crash �߻�!!

		delete item;
	}

	// �ڽ� -> �θ� ��ȯ �׽�Ʈ
	{
		// [ [ Item ] ]
		// [	_damage	]
		Weapon* weapon = new Weapon();

		// �Ͻ������ε� �ȴ�!
		Item* item = weapon;

		delete weapon;
	}


	// ��������� Ÿ�� ��ȯ�� ���� �׻� �׻� �����ؾ� �Ѵ�!
	// �Ͻ������� �� ���� �����ϴ�?
	// -> ��� ��������� Ÿ�� ��ȯ(ĳ����)�� �� �ϸ� �Ǵ°� �ƴѰ�?


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