#include<iostream>
using namespace std;

// 오늘의 주제 : 타입 변환(포인터)

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

	char _dummy[4096] = {};// 이런 저런 정보들로 인해 비대해진 클래스를 나타냄

};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{

}

int main()
{
	// 복습
	{
		// Stack 메모리에 만들어짐
		// Stack [type(4) dbid(4) dummy(4096)]
		Item item;


		// Stack [ 주소 (4바이트 or 8바이트) ] -> Heap[type(4) dbid(4) dummy(4096)]
		Item* item2 = new Item();

		TestItem(item); // 어마어마하게 큰 놈을 복사해서 넘겨준다.
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

		// 메모리 누수 (Memory Leak) -> 점점 가용 메모리가 줄어들어서 Crash
		delete item2;

	}

	// 배열
	{
		cout << "--------------------------------------------1" << endl;

		// 진짜 아이템이 100개 있는 것( 스택 메모리에 올라와 있는)
		Item item3[100] = {};

		cout << "--------------------------------------------2" << endl;

		// 아이템 100개 있을까요?
		// 아이템을 가리키는 바구니가 100개. 실제 아이템은 1개도 없을 수도 있음.
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