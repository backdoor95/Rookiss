#include<iostream>
using namespace std;

// ������ ���� : �ݺ���
// �����͸� �޸𸮿� �Ҵ�,�����ϰ� ����� ���� �˾ƺ�
// ������ �����͸� �̿��ؼ� �����ΰ��� �ϰ� �ʹٸ�?

int main() {

	//while : ~���ȿ�
	// if-else :������ ����
	// ������ �� ���� �����ϴ°� �ƴ϶�, Ư�� ���Ǳ��� ��� �ݺ��ؾ� �ϴ� ��Ȳ
	//ex) ������ �������� ��� ������ �����ض�
	//ex) �������� �����Ҷ����� ~ ��� �̵��϶�

	/*
	while (���ǽ�)
	{
		��ɹ�
	}
	*/


	//int count = 0;

	// �ش� ���� �ּ�ó�� = CTRL + K + C
	// 
	// �ش� ���� �ּ����� = CTRL + K + U
	// 
	//while (count < 5) 
	//{
	//	cout << "hello world" << endl;
	//	count++;
	//}


	//do
	//{
	//	cout << "hello world" << endl;
	//} while (false);// do - while�� ���� ������� ����.. 
	// �̰Ŵ� ��� �ѹ��� �����.


	// break : �ݺ������� ����������

	// continue : �ش� ������ �����ϸ� �� �κ��� ��ŵ


	for (int count = 0; count < 5; count++)// �ʱ��:���ǽ�:�����
	{
		cout << "Hello World" << endl;

		//
		
		// 
		
		//

	}


	// break, continue

	// �������� �帧���� break, continue

	int round = 1;
	int hp = 100;
	int damage = 10;

	// ���� ���� : ���� ����
	while (true) 
	{
		hp -= damage;
		if (hp < 0)
			hp = 0;// ���� ü���� 0���� ����

		// �ý��� �޽���
		cout << "Round " << round << " ���� ü�� " << hp << endl;

		if (hp == 0)
		{
			cout << "���� óġ!" << endl;
			break;
		}

		if (round == 5)
		{
			cout << "���� ���� ����" << endl;
			break;
		}

		round++;
	}



	// 1 ~ 10 ������ Ȧ���� ����ϱ�

	for (int count = 1;count<=10;count++)
	{
		bool isEven = ((count % 2) == 0);// �̷� ��� ����ϰ� ���ƺ���!

		if (isEven)
			continue;

		if (isEven == false)
		{
			cout << count << endl;
		}
	}








}