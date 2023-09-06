#include<iostream>
using namespace std;

int main()
{
	srand(time(0));// �õ� ���� srand�� rand�� ¦���̴�.

	// �츮�� ��� ������ 1, 2, 3
	//int value = (rand() % 3) + 1;// 0~ 32767

	int Percentage = 0;// ���� �·����� ����, ��/�� �� ����
	int win = 0;
	int lose = 0;
	int input;
	int computer;
	int result;
	string m;
	string c;

	// �� Ǯ�� 
	while (true)
	{
		cout << "����(1) ����(2) ��(3) ����ּ���!" << endl;
		
		if (win==0&&lose==0)
		{
			cout << "���� �·� : ����" << endl;
		}
		else
		{
			cout << "���� �·� : " << (win*100) / (win + lose) << endl;
		}

		cout << ">";
		cin >> input;


		// 1. Ż�� ����
		if (input < 1 || input>3)
		{
			cout << "������ �����մϴ�." << endl;
			break;
		}

		computer = (rand() % 3) + 1;

		// 
		result = input - computer;


		// 2. ����
		if (input == 1)
		{
			m = "����(��)";
		}
		else if (input == 2)
		{
			m = "����(��)";
		}
		else if(input == 3)
		{
			m = "��(��)";
		}


		if (computer == 1)
		{
			c = "����(��ǻ��)";
		}
		else if (computer == 2)
		{
			c = "����(��ǻ��)";
		}
		else if (computer == 3)
		{
			c = "��(��ǻ��)";
		}

		
		// Ǯ�� 1. [�ϵ��ڵ�]
		//if (input == 1)
		//{

		//}
		//else if (input == 2)
		//{

		//}
		//else if (input == 3)
		//{

		//}


		// Ǯ�� 2. [������]
		// ���� 1, ���� 2, �� 3
		// result = input - computer
		switch (result)
		{
		case 2:// �� = ��(3) , �� = ����(1) [��ǻ�� �¸�]
			cout << m << " vs " << c << " �����ϴ�!" << endl<<endl;
			lose++;
			break;// break, continue ���߿� �� �������... �� �� ���� ����� ����. ���߿� �򰥸��� �Ʒ��� break, continue�ּ��� ����
		case 1:// ���� �̱� ���
			cout << m << " vs " << c << " �̰���ϴ�!" << endl<<endl;
			win++;
			break;
		case 0:// ��� ���
			cout << m << " vs " << c << " �����ϴ�!" << endl<<endl;
			break;
		case -1:// ��ǻ�Ͱ� �̱� ���
			cout << m << " vs " << c << " �����ϴ�!" << endl<<endl;
			lose++;
			break;
		case -2:// �� = ����(1) , �� = ��(3) [�� �¸�]
			cout << m << " vs " << c << " �̰���ϴ�!" << endl<<endl;
			win++;
			break;

		}

	}

	// Rookiss Ǯ��

	// ���� ��ü�� �ڵ�ȿ� ���� �ִ°� �ſ� ������ �����̴�.
	// �� �ڵ�� ���ڸ� �׳� �ȿ� �־��µ�, �� �κ��� �Ʒ��� ���� ��ġ���� ����.
	// 
	// ���ȭ : �̸��� �����༭ ������ ���
	// �̷��� �ϴ°� �ٶ�����!.

	const int SCISSORS = 1;
	const int ROCK = 2;
	const int PAPER = 3;

	int wins = 0;
	int total = 0;

	// switch - case ���� break�� �ɷ�������, switch - case�� �����°��̴�.
	// �ƴϸ� for��, while�� �����°��̴�.

	// ������ ã�°� ��ƴٸ� break point�� �����ؼ� F5�����ؼ� ���������!!
	// ����Ŀ��� wins/total �̷������� �˻��� �����ϴ�.

	// ������ ������ ������ �����̴�.

	while (true)// ���������� main�ȿ� ���� ������ �ִ�.
	{
		cout << "����(1) ����(2) ��(3) ����ּ���!" << endl;
		cout << "> ";

		if (total == 0)
		{
			cout << "���� �·� : ����" << endl;
		}
		else
		{
			//int winPercentage = wins / total * 100;// �·� -> �̷��� �ϸ� ��� 0�� ��. �������� ��������� �߿��ϴ�.
			int winPercentage = (wins * 100) / total;// �·�
			cout << "���� �·� : " << winPercentage << endl;
		}

		//��ǻ��
		int computerValue = 1 + (rand() % 3);

		// �����
		int input;
		cin >> input;

		if (input == SCISSORS)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				break;
			case ROCK:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				total++;
				break;
			case PAPER:
				cout << "����(��) vs ��(��ǻ��) �̰���ϴ�!" << endl;
				wins++;
				total++;
				break;

			}

		}
		else if (input == ROCK)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "����(��) vs ����(��ǻ��) �̰���ϴ�!" << endl;
				wins++;
				total++;
				break;
			case ROCK:
				cout << "����(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				break;
			case PAPER:
				cout << "����(��) vs ��(��ǻ��) �����ϴ�!" << endl;
				total++;
				break;

			}
		}
		else if (input == PAPER)
		{
			switch (computerValue)
			{
			case SCISSORS:
				cout << "��(��) vs ����(��ǻ��) �����ϴ�!" << endl;
				total++;
				break;
			case ROCK:
				cout << "��(��) vs ����(��ǻ��) �̰���ϴ�!" << endl;
				wins++;
				total++;
				break;
			case PAPER:
				cout << "��(��) vs ��(��ǻ��) �����ϴ�!" << endl;
				break;

			}
		}
		else
		{
			break;
		}


	}




}