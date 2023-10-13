#include<iostream>
#include<vector>
using namespace std;

// ������ ���� : ����(Lamda)

// �Լ� ��ü�� ������ ����� ����

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

	// ���� = �Լ� ��ü�� �՚Z�� ����� ����
	// ���� ��ü�� c++11�� '���ο�' ����� �� ���� �ƴϴ�.

	{
		struct IsUniqueItem
		{
			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}
		};

		//[](){} : [] -> �͸��Լ�, () -> ����, {} -> �߰�ȣ(�����ΰ� ��)

		auto isUniqueLamda = [](Item& item) {return item._rarity == Rarity::Unique; };// ���� ǥ����( lamda expression)
		//auto isUniqueLamda = [](Item& item) -> int {return item._rarity == Rarity::Unique; };// int�� ��ȯ��. �ٵ� ��κ� ���� ���������.

		auto findIt = find_if(v.begin(), v.end(), isUniqueLamda);

		auto findIt2 = find_if(v.begin(), v.end(),
			[](Item& item) {return item._rarity == Rarity::Unique; });

		if (findIt != v.end())
			cout << "������ID: " << findIt->_itemId << endl;


	}

	{
		struct IsUniqueItem
		{
			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}
		};

		//[](){} : [] -> �͸��Լ�, () -> ����, {} -> �߰�ȣ(�����ΰ� ��)

		// Ŭ����(closure) = ���ٿ� ���� ������� ������� ��ü
		auto isUniqueLamda = [](Item& item)
		{
			return item._rarity == Rarity::Unique; 
		};// ���� ǥ����( lamda expression)
		//auto isUniqueLamda = [](Item& item) -> int {return item._rarity == Rarity::Unique; };// int�� ��ȯ��. �ٵ� ��κ� ���� ���������.

		auto findIt = find_if(v.begin(), v.end(), isUniqueLamda);

		auto findIt2 = find_if(v.begin(), v.end(),
			[](Item& item) {return item._rarity == Rarity::Unique; });

		if (findIt != v.end())
			cout << "������ID: " << findIt->_itemId << endl;


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

		// [ ] ĸó(capture) : �Լ� ��ü ���ο� ������ �����ϴ� ����� ����
		// ������ ��Ĭ [ĸó]�ϵ�.. ������ �������� ��´ٰ� ����
		// �⺻ ĸó ��� : 1.��(����) ��� (=) || 2. ���� ��� (&)
		// 
		//auto findByItemIdLamda = [](Item& item) { return item._itemId == itemId; }; �̶� itemId �κп� �������� ����. [C++ �ٱ��� �Լ��� ���� ������ ĸó ��Ͽ� ���� �ʴ� �� ���� �������� ������ �� �����ϴ�.]
		// 
		//auto findByItemIdLamda = [=](Item& item) { return item._itemId == itemId; };// ���� ���
		auto findByItemIdLamda = [&](Item& item) { return item._itemId == itemId; };// ���� ��� ===> ���� ���� �����Ѵ�.

		itemId = 10;

		//auto findIt = find_if(v.begin(), v.end(), FindItemByItemId(itemId));
		auto findIt = find_if(v.begin(), v.end(), findByItemIdLamda);


		if (findIt != v.end())
			cout << "������ID: " << findIt->_itemId << endl;


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

		// [ ] ĸó(capture) : �Լ� ��ü ���ο� ������ �����ϴ� ����� ����
		// ������ ��Ĭ [ĸó]�ϵ�.. ������ �������� ��´ٰ� ����
		// 
		// �⺻ ĸó ��� : ��(����) ��� (=) || ���� ��� (&)
		// �������� ĸó ��带 �����ؼ� ��� ���� : �� ���(name), ���� ���(&name)
		// 
		//auto findByItemIdLamda = [=](Item& item) { return item._itemId == itemId; };// ���� ���
		auto findByItem = [=,&type](Item& item)// �̰͵� ������ �� ����� �����϶�!
		{ 
			return item._itemId == itemId && item._rarity == rarity && item._type == type;
		};// ���� ��� ===> ���� ���� �����Ѵ�.	

		auto findByItem = [&itemId, &rarity, type](Item& item)// �̰͵� ������ �� ����� �����϶�!
		{ 
			return item._itemId == itemId && item._rarity == rarity && item._type == type;
		};// ���� ��� ===> ���� ���� �����Ѵ�.

		// ���� é�Ĵ� �����ؾ��Ѵ�.

		itemId = 10;

		auto findIt = find_if(v.begin(), v.end(), FindItem(4, Rarity::Unique, ItemType::Weapon));


		if (findIt != v.end())
			cout << "������ID: " << findIt->_itemId << endl;

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
		auto job = k->ResetHpJob();// job ��ü�� �Լ� ��ü��.

		delete k;

		job();// �޸� ���� �߻�!! 

		//c++���� ���ٸ� ����� �� => ��� �ֵ��� �� �� ���� ������� �ϰų� ��� �ֵ��� �� ���� ������� �ϰڴٶ�� ���� �����϶����.



		// ��� �⺻ ĸó ��带 Ȱ���ϱ⺸�ٴ� �������� ĸó ���� �����ؼ� ����ϴ°Ÿ� ���� �� ��õ��.
		// ex) auto findByItem = [&itemId, &rarity, type](Item& item) 

		//  [ĸó] (���ڰ�) { ������ }

	}




	return 0;
}