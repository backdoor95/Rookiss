#include<iostream>
#include<vector>
using namespace std;

// 오늘의 주제 : 람다(Lamda)

// 함수 객체를 빠르게 만드는 문법

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};
enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item(){ }
	Item(int itemId, Rarity rarity, ItemType type) : _itemId(itemId), _rarity(rarity), _type(type)
	{

	}

public:
	int _itemId = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};


int main()
{
	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	// 람다 = 함수 객체를 손쉅게 만드는 문법
	// 람다 자체로 c++11에 '새로운' 기능이 들어간 것은 아니다.

	{
		struct IsUniqueItem
		{
			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}
		};

		//[](){} : [] -> 익명함수, () -> 인자, {} -> 중괄호(구현부가 들어감)

		auto isUniqueLamda = [](Item& item) {return item._rarity == Rarity::Unique; };// 람다 표현식( lamda expression)
		//auto isUniqueLamda = [](Item& item) -> int {return item._rarity == Rarity::Unique; };// int를 반환함. 근데 대부분 위에 방식으로함.

		auto findIt = find_if(v.begin(), v.end(), isUniqueLamda);

		auto findIt2 = find_if(v.begin(), v.end(),
			[](Item& item) {return item._rarity == Rarity::Unique; });

		if (findIt != v.end())
			cout << "아이템ID: " << findIt->_itemId << endl;


	}

	{
		struct IsUniqueItem
		{
			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}
		};

		//[](){} : [] -> 익명함수, () -> 인자, {} -> 중괄호(구현부가 들어감)

		// 클로저(closure) = 람다에 의해 만들어진 실행시점 객체
		auto isUniqueLamda = [](Item& item)
		{
			return item._rarity == Rarity::Unique; 
		};// 람다 표현식( lamda expression)
		//auto isUniqueLamda = [](Item& item) -> int {return item._rarity == Rarity::Unique; };// int를 반환함. 근데 대부분 위에 방식으로함.

		auto findIt = find_if(v.begin(), v.end(), isUniqueLamda);

		auto findIt2 = find_if(v.begin(), v.end(),
			[](Item& item) {return item._rarity == Rarity::Unique; });

		if (findIt != v.end())
			cout << "아이템ID: " << findIt->_itemId << endl;


	}


	{
		struct FindItemByItemId
		{
			FindItemByItemId(int itemId) : _itemId(itemId)
			{

			}

			bool operator()(Item& item)
			{
				return item._itemId == _itemId;
			}

			int _itemId;
		};

		int itemId = 4;

		// [ ] 캡처(capture) : 함수 객체 내부에 변수를 저장하는 개념과 유사
		// 사진을 찰칵 [캡처]하듯.. 일종의 스냅샷을 찍는다고 이해
		// 기본 캡처 모드 : 1.값(복사) 방식 (=) || 2. 참조 방식 (&)
		// 
		//auto findByItemIdLamda = [](Item& item) { return item._itemId == itemId; }; 이때 itemId 부분에 빨간줄이 나옴. [C++ 바깥쪽 함수의 지역 변수는 캡처 목록에 있지 않는 한 람다 본문에서 참조할 수 없습니다.]
		// 
		//auto findByItemIdLamda = [=](Item& item) { return item._itemId == itemId; };// 복사 방식
		auto findByItemIdLamda = [&](Item& item) { return item._itemId == itemId; };// 참조 방식 ===> 참조 값을 저장한다.

		itemId = 10;

		//auto findIt = find_if(v.begin(), v.end(), FindItemByItemId(itemId));
		auto findIt = find_if(v.begin(), v.end(), findByItemIdLamda);


		if (findIt != v.end())
			cout << "아이템ID: " << findIt->_itemId << endl;


	}


	{
		struct FindItem
		{
			FindItem(int itemId, Rarity rarity, ItemType type) : _itemId(itemId)
			{

			}

			bool operator()(Item& item)
			{
				return item._itemId == _itemId && item._rarity == _rarity && item._type == _type;
			}

			int _itemId;
			Rarity _rarity;
			ItemType _type;

		};


		int itemId = 4;
		Rarity rarity = Rarity:: Unique;
		ItemType type = ItemType::Weapon;

		// [ ] 캡처(capture) : 함수 객체 내부에 변수를 저장하는 개념과 유사
		// 사진을 찰칵 [캡처]하듯.. 일종의 스냅샷을 찍는다고 이해
		// 
		// 기본 캡처 모드 : 값(복사) 방식 (=) || 참조 방식 (&)
		// 변수마다 캡처 모드를 지정해서 사용 가능 : 값 방식(name), 참조 방식(&name)
		// 
		//auto findByItemIdLamda = [=](Item& item) { return item._itemId == itemId; };// 복사 방식
		auto findByItem = [=,&type](Item& item)// 이것도 가능한 이 방법은 지양하라!
		{ 
			return item._itemId == itemId && item._rarity == rarity && item._type == type;
		};// 참조 방식 ===> 참조 값을 저장한다.	

		auto findByItem = [&itemId, &rarity, type](Item& item)// 이것도 가능한 이 방법은 지양하라!
		{ 
			return item._itemId == itemId && item._rarity == rarity && item._type == type;
		};// 참조 방식 ===> 참조 값을 저장한다.

		// 람다 챕쳐는 조심해야한다.

		itemId = 10;

		auto findIt = find_if(v.begin(), v.end(), FindItem(4, Rarity::Unique, ItemType::Weapon));


		if (findIt != v.end())
			cout << "아이템ID: " << findIt->_itemId << endl;

	}

	{

		class Knight
		{
		public:
			auto ResetHpJob()
			{
				auto f = [=]() 
				{
					_hp = 200;// this->_hp
				};
				
				return f;
			}

		public:
			int _hp = 100;
		};

		class Functor
		{
		public:
			Functor(Knight* k) : _knight(k)
			{

			}

			void operator()()
			{
				_knight->_hp = 200;
			}

		public:
			Knight* _knight;
		};

		Knight* k = new Knight();
		auto job = k->ResetHpJob();// job 자체는 함수 객체임.

		delete k;

		job();// 메모리 오염 발생!! 

		//c++에서 람다를 사용할 때 => 모든 애들을 다 값 복사 방식으로 하거나 모든 애들을 다 참조 방식으로 하겠다라는 것을 지양하라고함.



		// 결론 기본 캡처 모드를 활용하기보다는 변수마다 캡처 모델을 지정해서 사용하는거를 조금 더 추천함.
		// ex) auto findByItem = [&itemId, &rarity, type](Item& item) 

		//  [캡처] (인자값) { 구현부 }

	}




	return 0;
}