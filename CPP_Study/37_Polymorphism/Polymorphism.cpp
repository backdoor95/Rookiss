#include<iostream>
using namespace std;

// 오늘의 주제 : 다형성

// 객체지향 (OOP)
// - 상속성
// - 은닉성 = 캡슐화
// - 다형성

// 다형성 (Polymorphism = Poly + morph) : 형태가 다양하게 있는것. 겉은 똑같은데, 기능이 다르게 동작한다.

// - 오버로딩(Overloading) = 함수 중복 정의 = 함수 이름의 재사용

// - 오버라이딩(Overriding) = 재정의 = 부모 클래스의 함수를 자식 클래스에서 재정의

// 바인딩(Binding) = 묶는다.
// - 정적 바인딩(Static Binding) : 컴파일 시점에 결정
// - 동적 바인딩(Dynamic Binding) : 실행 시점에 결정  ---> 면접 단골 질문

// 일반 함수는 정적 바인딩을 사용
// 동적 바인딩을 원한다면? -> 가상 함수(virtual function)

// 그런데 실제 객체가 어떤 타입인지 어떻게 알고 알아서 가상함수를 호출해준걸까?
// - 가상 함수 테이블(vftable)
// .vftable [] 4바이트(32) 8바이트(64) --> 일종의 주소 테이블이다.
// 그 주소를 타고 가면 그 함수가 호출해야할 함수 주소가 적혀있다.

// [VMove] [VDie]

// 순수 가상 함수 : 구현은 없고 '인터페이스'만 전달하는 용도로 사용하고 싶을 경우

class Player
{
public:

	Player()
	{
		_hp = 100;
	}

	void Move() { cout << "Move Player !" << endl; }
	//void Move(int a){ cout << "Move Player (int) !" << endl; }
	virtual void VMove(){ cout << "VMove Player !" << endl; }// 가상 함수를 만들기 위해서는 virtual를 붙여줘야함. 경우에 따라서 대문자 V를 함수이름 앞에 붙여준다.
	virtual void VDie(){ cout << "VDie Player !" << endl; }

	// 순수 가상 함수
	virtual void VAttack() = 0;// 순수 가상 함수
	// 모던 c++에서 순수 가상 함수를 나타낼때는 [virtual void VAttack() abstract; ] 이렇게 표현함.
	// 여기서 구현부가 들어가 있지않고, 반드시 player를 상속하는 애가 직접적으로 VAttack을 구현해야함.(강제 사항)
	// 추상 클래스 : 순수 가상 함수가 1개 이상 포함되면 바로 추상 클래스로 간주
	// - 직접적으로 객체를 만들 수 없게 됨.
public:
	int _hp;
};

class Knight : public Player
{
public:

	Knight()
		/*
		* 	Knight()
00741F70  push        ebp  
00741F71  mov         ebp,esp  
00741F73  sub         esp,0CCh  
00741F79  push        ebx  
00741F7A  push        esi  
00741F7B  push        edi  
00741F7C  push        ecx  
00741F7D  lea         edi,[ebp-0Ch]  
00741F80  mov         ecx,3  
00741F85  mov         eax,0CCCCCCCCh  
00741F8A  rep stos    dword ptr es:[edi]  
00741F8C  pop         ecx  
00741F8D  mov         dword ptr [this],ecx  
00741F90  mov         ecx,offset _61741671_Polymorphism@cpp (074F067h)  
00741F95  call        @__CheckForDebuggerJustMyCode@4 (07413B6h)  
00741F9A  mov         ecx,dword ptr [this]  
00741F9D  call        Player::Player (07411CCh) --> virtual function 의 table 주소
1) 처음에는 player생성자에 의해 vftable 이 들어감.
2) knight 생성자가 실행이 되면서 Knight의 vftable이 덮어씌어짐.!!!!
00741FA2  mov         eax,dword ptr [this]  
00741FA5  mov         dword ptr [eax],offset Knight::`vftable' (0749B60h)  --> Knight의 생성자 선처리 영역에서 자기 자신의 vftable을 안에다가 채워줌.

			
		*/
	{
		_stamina = 100;
	}

	void Move() { cout << "Move Knight !" << endl; }

	// 가상 함수는 재정의를 하더라도 가상 함수다!  여기서 virtual를 없애도 가상함수이다.
	// 가상 함수가 추가되는 순간 메모리에 변화가 일어난다.
	virtual void VMove() { cout << "VMove Knight !" << endl; }// 가상 함수를 만들기 위해서는 virtual를 붙여줘야함. 경우에 따라서 대문자 V를 함수이름 앞에 붙여준다.
	virtual void VDie() { cout << "VDie Knight !" << endl; }
	virtual void VAttack() { cout << "VAttack Knight" << endl; }
public:
	int _stamina;
};
class Mage : public Player
{
public:
	int _mp;
};



//[	[ Player ] ]
//[	  Knight   ]
void MovePlayer(Player* player)
{
	//player->Move(); // 원본이 player, knight 인지 구분 못함. 그래서 player의 함수를 호출함.
	/*
	0x008FFB00  00409b60 --> virtual function 의 table 주소 1) 처음에는 player생성자에 의해 vftable 이 들어감. 2) knight 생성자가 실행이 되면서 Knight의 vftable이 덮어씌어짐.!!!!
	0x008FFB04  00000064 // _hp
	0x008FFB08  00000064 // _stamina
	
	*/
	
	player->VMove(); // 동적 바인딩
	player->VDie();

	/*
		player->VMove(); // 동적 바인딩
00402561  mov         eax,dword ptr [player]  
00402564  mov         edx,dword ptr [eax]  
00402566  mov         esi,esp  
00402568  mov         ecx,dword ptr [player]  
0040256B  mov         eax,dword ptr [edx]  
0040256D  call        eax  
0040256F  cmp         esi,esp  
00402571  call        __RTC_CheckEsp (04012B7h)  
	player->VDie();
00402576  mov         eax,dword ptr [player]  
00402579  mov         edx,dword ptr [eax]  
0040257B  mov         esi,esp  
0040257D  mov         ecx,dword ptr [player]  
00402580  mov         eax,dword ptr [edx+4]  
00402583  call        eax  
00402585  cmp         esi,esp  
00402587  call        __RTC_CheckEsp (04012B7h)  
	
	*/
}

void MoveKnight(Knight* knight)
{
	knight->Move();
}

//class Animal
//{
//	 
//};
//
//class Cat : public Animal
//{
//
//};
//
//class Dog : public Animal
//{
//
//};

int main()
{
	//Player p; // Player에 순수 가상 함수가 있어서 독단적으로 객체를 만들수 없다.
	// 
	//p.Move();
	//MovePlayer(&p);// 플레이어는 플레이어다 ? YES
	//MoveKnight(&p); // 플레이어는 기사다? NO

	Knight k;
	//k.Move();
	//MoveKnight(&k);// 기사는 기사다 ? YES
	MovePlayer(&k);// 기사는 플레이어다? YES   --> player의 move 함수 호출


	return 0;
}