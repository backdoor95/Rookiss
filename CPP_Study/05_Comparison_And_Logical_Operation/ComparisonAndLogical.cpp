#include<iostream>
using namespace std;
// ������ ���� : ������ ����
// �����͸� �����ϴ� ����� ���ؼ� �˾ƺ���

// a[1]
// a��� �̸��� �ٱ��ϸ� �Ҵ��ϰ� �ȿ� 1�� �ִ´�.
int a = 1;

// b[2]
// b��� �̸��� �ٱ��ϸ� �Ҵ��ϰ� �ȿ� 2�� �ִ´�.
int b = 2;

/***********************************************/

//������ ���� break point�� �صΰ�, 
// ctrl + alt + d => ����� �ڵ带 � �� �ִ�.

/***********************************************/

bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;
bool test;

int hp = 100;
bool isInvincible = true;


int main() {

#pragma region �񱳿���

	// ���� �ʿ��Ѱ�?
	// ex) ü���� 0�̵Ǹ� ���
	// ex) ü���� 30% �����̸� �ñر⸦ �ߵ�
	// ex) ����ġ�� 100�̻��̸� ������

	// a==b:a�� b�� ���� ������?
	// ������ 1, �ٸ��� 0
	isSame = (a == b);

	// a!=b : a�� b�� ���� �ٸ���?'
	// �ٸ��� 1, ������ 0
	isDifferent = (a != b);

	// a>b : a�� b���� ū��?
	// a>=b : a�� b���� ũ�ų� ������?
	// 1 �ƴϸ� 0
	isGreater = (a > b);

	// a<b: a�� b���� ������?
	// a<=b: a�� b���� �۰ų� ������?
	// 1 �ƴϸ� 0 
	isSmaller = (a < b);

#pragma endregion

#pragma region ������
	//���� �ʿ��Ѱ�? ���ǿ� ���� ���� ��� �ʿ��� ��
	// ex) �α����� �� ���̵� ���� AND ��й�ȣ�� ���ƾ��Ѵ�.
	// ex) ��� �������̰ų� OR ��� �����̸� ��� �ػ갡��

	// !not
	// 0�̸� 1, �׿� 0
	test = !isSame;// ��ǻ� isDifferent�� �ǹ�

	//&& : AND
	// a && b -> �Ѵ� 1�̸�, �׿� 0
	test = (hp <= 0 && isInvincible == false); //����


	// || or
	// a || b -> �� �� �ϳ��� 1�̸� 1( �Ѵ� 0�̸� 0)
	test = (hp > 0 || isInvincible == true);// ����� == [!(hp <= 0 && isInvincible == false)]

	// test�� and ������ �ϴ� ����� ��ɾ��̴�.
#pragma endregion
}