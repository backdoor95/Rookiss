#include<iostream>
using namespace std;

// ctrl + shift + b = 빌드하는법
// 
// 오늘의 주제 : 생성자와 소멸자

// [생성자(Constructor)와 소멸자(Destructor)]
// 클래스에 '소속'된 함수들을 멤버 함수라고 함
// 이 중에서 굉장히 특별한 함수 2종이 있는데, 바로 [시작]과 [끝]을 알리는 함수들
// - 시작 (탄생) -> 생성자(여러개 존재 가능)
// - 끝( 소멸) -> 소멸자 (오직 1개만)

// [암시적(Implicit) 생성자]
// 생성자를 명시적으로 만들지 않으면,
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어짐.
//  -> 그러나 우리가 명시적(Explicit)으로 아무 생성자 하나 만들면,
// 자동으로 만들어지던 [기본 생성자]는 더 이상 만들어지지 않음!

class Knight// 붕어빵 틀
{
public:
	//[1] 기본 생성자(인자가 없음)
	Knight()
	{
		cout << "Knight() 기본 생성자 호출" << endl;

		_hp = 100;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}



	// [2] 복사 생성자(자기 자신의 클래스 참조 타입을 인자로 받음)
	// (일반적으로 '똑같은' 데이터를 지닌 객체가 생성되길 기대한다.
	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_attack = knight._attack;
		_posX = knight._posX;
		_posY = knight._posY;
	}

	// [3] 기본 생성자가 아닐때. = 기타 생성자
	Knight(int hp)// 생성자는 이렇게 오버로딩 할 수 있다.
	{
		cout << "Knight(int) 생성자 호출" << endl;
		_hp = hp;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}

	// 소멸자 : 소멸자는 오직 1개만 존재
	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;
	}




	// 멤버 함수 선언
	// 같은 클래스에 있는 멤버 함수는 멤버변수에 접근이 가능하다.
	void Move(int y, int x);
	void Attack();
	void Die() //정의를 class 안에서도 해도됨
	{
		// this는 객체가 있는 번지수를 의미.
		_hp = 0;// this->_hp=0;
		cout << "Die" << endl;
	}

public:
	// 멤버 변수를 표기하는법
	int _hp;// m_hp, mHp, _hp 이렇게 3가지가 대표적
	int _attack;
	int _posY;
	int _posX;



};

void Move(Knight* knight, int y, int x)
{
	knight->_posY = y;
	knight->_posX = x;
}

void Knight::Move(int y, int x)// 정의를 이렇게 밖에서 해도됨. 대신 어느 클래스 소속인지를 알려주기 위해서 ' :: '을 사용한다.
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}


// Instantiate = 객체를 만든다!
int main()
{
	Knight k1;

	/*
		Knight k1;
00F86247  lea         ecx,[k1]  
00F8624A  call        Knight::Knight (0F81451h)  // 생성자 호출
00F8624F  mov         dword ptr [ebp-4],0  
	
	*/

	k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	// k1의 sizeof(k1) = 16 --> 멤버변수만 데이터에 잡혀있다. , 멤버함수에 대한 메모리는 잡히지 않는다.


	Knight k2(k1);// 이때 복사 생성자가 만들어진다.





	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;
	/*
	0056628E  mov         dword ptr [ebp-0F0h],0  
00566298  mov         dword ptr [ebp-4],0FFFFFFFFh  
0056629F  lea         ecx,[k1]  
005662A2  call        Knight::~Knight (056144Ch)  // 소멸자 호출
005662A7  mov         eax,dword ptr [ebp-0F0h]  
	*/
}