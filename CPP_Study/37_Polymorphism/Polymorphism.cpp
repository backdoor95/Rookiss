#include<iostream>
using namespace std;

// ������ ���� : ������

// ��ü���� (OOP)
// - ��Ӽ�
// - ���м� = ĸ��ȭ
// - ������

// ������ (Polymorphism = Poly + morph) : ���°� �پ��ϰ� �ִ°�. ���� �Ȱ�����, ����� �ٸ��� �����Ѵ�.

// - �����ε�(Overloading) = �Լ� �ߺ� ���� = �Լ� �̸��� ����

// - �������̵�(Overriding) = ������ = �θ� Ŭ������ �Լ��� �ڽ� Ŭ�������� ������

// ���ε�(Binding) = ���´�.
// - ���� ���ε�(Static Binding) : ������ ������ ����
// - ���� ���ε�(Dynamic Binding) : ���� ������ ����  ---> ���� �ܰ� ����

// �Ϲ� �Լ��� ���� ���ε��� ���
// ���� ���ε��� ���Ѵٸ�? -> ���� �Լ�(virtual function)

// �׷��� ���� ��ü�� � Ÿ������ ��� �˰� �˾Ƽ� �����Լ��� ȣ�����ذɱ�?
// - ���� �Լ� ���̺�(vftable)
// .vftable [] 4����Ʈ(32) 8����Ʈ(64) --> ������ �ּ� ���̺��̴�.
// �� �ּҸ� Ÿ�� ���� �� �Լ��� ȣ���ؾ��� �Լ� �ּҰ� �����ִ�.

// [VMove] [VDie]

// ���� ���� �Լ� : ������ ���� '�������̽�'�� �����ϴ� �뵵�� ����ϰ� ���� ���

class Player
{
public:

	Player()
	{
		_hp = 100;
	}

	void Move() { cout << "Move Player !" << endl; }
	//void Move(int a){ cout << "Move Player (int) !" << endl; }
	virtual void VMove(){ cout << "VMove Player !" << endl; }// ���� �Լ��� ����� ���ؼ��� virtual�� �ٿ������. ��쿡 ���� �빮�� V�� �Լ��̸� �տ� �ٿ��ش�.
	virtual void VDie(){ cout << "VDie Player !" << endl; }

	// ���� ���� �Լ�
	virtual void VAttack() = 0;// ���� ���� �Լ�
	// ��� c++���� ���� ���� �Լ��� ��Ÿ������ [virtual void VAttack() abstract; ] �̷��� ǥ����.
	// ���⼭ �����ΰ� �� �����ʰ�, �ݵ�� player�� ����ϴ� �ְ� ���������� VAttack�� �����ؾ���.(���� ����)
	// �߻� Ŭ���� : ���� ���� �Լ��� 1�� �̻� ���ԵǸ� �ٷ� �߻� Ŭ������ ����
	// - ���������� ��ü�� ���� �� ���� ��.
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
00741F9D  call        Player::Player (07411CCh) --> virtual function �� table �ּ�
1) ó������ player�����ڿ� ���� vftable �� ��.
2) knight �����ڰ� ������ �Ǹ鼭 Knight�� vftable�� �������.!!!!
00741FA2  mov         eax,dword ptr [this]  
00741FA5  mov         dword ptr [eax],offset Knight::`vftable' (0749B60h)  --> Knight�� ������ ��ó�� �������� �ڱ� �ڽ��� vftable�� �ȿ��ٰ� ä����.

			
		*/
	{
		_stamina = 100;
	}

	void Move() { cout << "Move Knight !" << endl; }

	// ���� �Լ��� �����Ǹ� �ϴ��� ���� �Լ���!  ���⼭ virtual�� ���ֵ� �����Լ��̴�.
	// ���� �Լ��� �߰��Ǵ� ���� �޸𸮿� ��ȭ�� �Ͼ��.
	virtual void VMove() { cout << "VMove Knight !" << endl; }// ���� �Լ��� ����� ���ؼ��� virtual�� �ٿ������. ��쿡 ���� �빮�� V�� �Լ��̸� �տ� �ٿ��ش�.
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
	//player->Move(); // ������ player, knight ���� ���� ����. �׷��� player�� �Լ��� ȣ����.
	/*
	0x008FFB00  00409b60 --> virtual function �� table �ּ� 1) ó������ player�����ڿ� ���� vftable �� ��. 2) knight �����ڰ� ������ �Ǹ鼭 Knight�� vftable�� �������.!!!!
	0x008FFB04  00000064 // _hp
	0x008FFB08  00000064 // _stamina
	
	*/
	
	player->VMove(); // ���� ���ε�
	player->VDie();

	/*
		player->VMove(); // ���� ���ε�
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
	//Player p; // Player�� ���� ���� �Լ��� �־ ���������� ��ü�� ����� ����.
	// 
	//p.Move();
	//MovePlayer(&p);// �÷��̾�� �÷��̾�� ? YES
	//MoveKnight(&p); // �÷��̾�� ����? NO

	Knight k;
	//k.Move();
	//MoveKnight(&k);// ���� ���� ? YES
	MovePlayer(&k);// ���� �÷��̾��? YES   --> player�� move �Լ� ȣ��


	return 0;
}