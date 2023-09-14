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
	// 암시적인 복사 생성자(따로 복사 생성자를 안 만들었을때)는 모든 데이터를 복사를 한다. 
	// 

	// [3] 기본 생성자가 아닐때. = 기타 생성자
	// 이 중에서 인자를 1개만 받는 [기타 생성자]를 
	// [타입 변환 생성자]라고 부르기도 함. --> 이건 암시적으로 컴파일러가 해준다. 
	// 명시적으로 해주기 위해서는 explicit 을 붙여줘야함.
	Knight(int hp)// 생성자는 이렇게 오버로딩 할 수 있다.
	{
		cout << "Knight(int) 생성자 호출" << endl;
		_hp = hp;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}
	
	// 명시적으로 해주기 위해서는 explicit 을 붙여줘야함
	//explicit Knight(int hp)// 생성자는 이렇게 오버로딩 할 수 있다.
	//{
	//	cout << "Knight(int) 생성자 호출" << endl;
	//	_hp = hp;
	//	_attack = 10;
	//	_posY = 0;
	//	_posX = 0;
	//}


	Knight(int hp, int attack, int posX, int posY)
	{
		_hp = hp;
		_attack = attack;
		_posX = posX;
		_posY = posY;
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

void HelloKnight(Knight k)
{
	cout << "Hello Knight" << endl;
}


// Instantiate = 객체를 만든다!
int main()
{
	//Knight k1;
	//Knight k1(10);
	//Knight k1(100, 10, 0, 0);

	/*
		Knight k1;
00F86247  lea         ecx,[k1]  
00F8624A  call        Knight::Knight (0F81451h)  // 생성자 호출
00F8624F  mov         dword ptr [ebp-4],0  
	
	*/

	//k1._hp = 100;
	//k1._attack = 10;
	//k1._posY = 0;
	//k1._posX = 0;

	// k1의 sizeof(k1) = 16 --> 멤버변수만 데이터에 잡혀있다. , 멤버함수에 대한 메모리는 잡히지 않는다.


	//Knight k2(k1);//  (1) 이때 복사 생성자가 만들어진다.

	//Knight k3 = k1;// (2)생성과 함과 동시에 복사 --> 복사 생성자로 만들어짐.

	//Knight k4; // (3) 기본생성자로 만들어지고
	//k4 = k1;// 복사, k1를 k4에 복사



	//k1.Move(2, 2);
	//k1.Attack();
	//k1.Die();


	// 암시적 형변환 -> 컴파일러가 알아서 바꿔치기
	int num = 1;

	float f = (float)num;// 명시적 < 우리가 코드로 num을 float 바구니에 넣으라고 주문하고 있음
	double d = num;// 암시적 << 별말 안했는데 컴파일러가 알아서 처리하고 있음.

	// 타입 변환 생성자
	cout << "타입 변환 생성자" << endl;
	Knight k5; // 기본 생성자로 생성
	k5 = 1;// 먼저  암시적으로 hp 파라매터에 '1'이 들어가서 기타 생성자가 호출됨.
	// 1에 대한 Knight(int) 생성자가 호출이되고 k5에 값을 복사한뒤에
	// 1에 대한 Knight(int)의 소멸자가 호출이된다.!!!!!!!!!!!!!!
	// k5 = (Knight)1;// explicit을 붙였으면 명시적으로 자료형을 붙여서 타입변환생성자를 호출할 수 있다.

	cout << "K5 hp = " << k5._hp << endl;
	cout << "K5 attack = " << k5._attack << endl;
	cout << "K5 posY = " << k5._posY << endl;
	cout << "K5 posX = " << k5._posX << endl;
	/*
	* OUTPUT 
K5 hp = 1
K5 attack = 10
K5 posY = 0
K5 posX = 0
	*/

	HelloKnight(5);// 이게 왜 됨? ---> 그냥 컴파일러가 암시적으로 해주기 때문.
	//HelloKnight((Knight)5);//
	// explicit을 붙였으면 명시적으로 자료형을 붙여서 타입변환생성자를 호출할 수 있다.


	return 0;
	/*
	0056628E  mov         dword ptr [ebp-0F0h],0  
00566298  mov         dword ptr [ebp-4],0FFFFFFFFh  
0056629F  lea         ecx,[k1]  
005662A2  call        Knight::~Knight (056144Ch)  // 소멸자 호출
005662A7  mov         eax,dword ptr [ebp-0F0h]  
	*/
}