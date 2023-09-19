#include<iostream>
using namespace std;

// ������ ���� : Ÿ�� ��ȯ(������)

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
	~Item()
	{
		cout << "~Item()" << endl;
	}

public:
	int _itemType = 0;
	int _timeDbId = 0;

	char _dummy[4096] = {};// �̷� ���� ������� ���� ������� Ŭ������ ��Ÿ��

};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{

}

int main()
{
	// ����
	{
		// Stack �޸𸮿� �������
		// Stack [type(4) dbid(4) dummy(4096)]
		Item item;


		// Stack [ �ּ� (4����Ʈ or 8����Ʈ) ] -> Heap[type(4) dbid(4) dummy(4096)]
		Item* item2 = new Item();

		TestItem(item); // ���ϰ� ū ���� �����ؼ� �Ѱ��ش�.
		TestItem(*item2);
		/*console output
		Item()
		Item()
		Item(const item&)
		~Item()
		Item(const item&)
		~Item()
		*/

		TestItemPtr(&item);
		TestItemPtr(item2);
		/* console output
		~Item()
		~Item()
		*/

		// �޸� ���� (Memory Leak) -> ���� ���� �޸𸮰� �پ�� Crash
		delete item2;

	}

	// �迭
	{
		cout << "--------------------------------------------1" << endl;

		// ��¥ �������� 100�� �ִ� ��( ���� �޸𸮿� �ö�� �ִ�)
		Item item3[100] = {};

		cout << "--------------------------------------------2" << endl;

		// ������ 100�� �������?
		// �������� ����Ű�� �ٱ��ϰ� 100��. ���� �������� 1���� ���� ���� ����.
		Item* item4[100] = {};

		for (int i = 0; i < 100; i++)
		{
			item4[i] = new Item();
		}

		cout << "--------------------------------------------3" << endl;

		for (int i = 0; i < 100; i++)
		{
			delete item4[i];
		}

		cout << "--------------------------------------------4" << endl;
	}



	return 0;
}