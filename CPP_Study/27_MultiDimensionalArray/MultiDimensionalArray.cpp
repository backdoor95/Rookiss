#include<iostream>
using namespace std;

// ������ ���� : ������ �迭

int main()
{

	int a[10] = { 1,2,3 };


	int first[5] = { 4,2,3,4,1 };
	int second[5] = { 1,1,5,2,2 };

	
	int apartment2D[2][5] = { { 4,2,3,4,1 },{ 1,1,5,2,2 } };// 2���� �迭 �ʱ�ȭ

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			// apartment2D + (floor*20) + 4*room�� �� �ּ�
			int num = apartment2D[floor][room];
			cout << num << " ";
		}
		cout << endl;
	}
	/*
				int num = apartment2D[floor][room];
00396288  imul        eax,dword ptr [ebp-0A4h],14h  
0039628F  lea         ecx,apartment2D[eax]  
00396296  mov         edx,dword ptr [ebp-0B0h]  
0039629C  mov         eax,dword ptr [ecx+edx*4]  
0039629F  mov         dword ptr [ebp-0BCh],eax  
	
	*/





	// �޸𸮿� data�� ���̾ ���ִ�.
	// 2�����̶�� �ص� �޸� ��ü�� 1�������� �� �ִ�.********************

	int apartment1D[10] = { 4,2,3,4,1,1,1,5,2,2 };

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int index = (floor * 5) + room;
			int num = apartment1D[index];
			cout << num << " ";
		}
		cout << endl;
	}
	/*
		    int index = (floor * 5) + room;
002C63A0  imul        eax,dword ptr [ebp-0F8h],5  
002C63A7  add         eax,dword ptr [ebp-104h]  
002C63AD  mov         dword ptr [ebp-110h],eax  
			int num = apartment1D[index];
002C63B3  mov         eax,dword ptr [ebp-110h]  
002C63B9  mov         ecx,dword ptr apartment1D[eax*4]  
002C63C0  mov         dword ptr [ebp-11Ch],ecx  
	*/

	// � ��쿡 2���� �迭?
	// ��ǥ������ 2D �α׶���ũ ��
	int map[5][5] =
	{
		{1,1,1,1,1},
		{1,0,0,1,1},
		{0,0,0,0,1},
		{1,0,0,0,0},
		{1,1,1,1,1}
	};


	return 0;
}