#include<iostream>
using namespace std;


// ������
// ���� const�� ����� ���� ����
const int SCISSORS = 1;// const�� �ʱⰪ�� �ݵ�� �־������. ENUM�� �� �־��൵��.
const int ROCK = 2;
const int PAPER = 3;
//�ٵ� ����ΰ� �˰ڴµ�, �ʹ� ���� ���� ��� ����?
// 
// const �� �� �޸𸮿� �ö󰡴°� �ƴϴ�. ��쿡 ���� �ö� ���� �ְ�, �ȿö󰥼��� �ִ�.
// �޸𸮿� �� �ö� ���ٸ�, �׳� SCISSORS�� 1�� ġȯ�ؼ� �۵��� �Ѵ�.
// main �ۿ��ٰ� const�� ����ٸ� �޸𸮿� �ö��� �ʴ´ٴ��� Ȯ����.
// 
// -*************************����*****************************
// ���࿡ �����Ϸ��� ���带 �ϸ鼭 �м��ϴٰ� ���� �� auto���ٰ� �ּҸ� ���� ���� �����(�ּҸ� ��������),
// const ������ �޸𸮿� �ּҸ� �Ҵ��ϰ� �ȴ�.(�� ��쿡�� �׳� �������� �����ؼ� main�Լ��ȿ� auto ������ const ������ �ּҸ� ���� ����̴�.
// �Ʒ� ���� �����ϱ� �����Ұ�.
// 
// �Ǵ� main�ȿ� const ������ ����� �Ǹ�, stack �޸𸮿� �ö󰣴�.
// 
// ��쿡 ���� �����Ϸ��� ����ȭ�� �� �� �ִٸ� �޸𸮿� �ȿø��� �׳� ������ ��ü�ϸ鼭 �����.
//***************************************************************


//

// ���ڸ� ���� ���ϸ� ù ���� 0���� ����
// �� ������ ������ ���� �� + 1
// enum�� ���带 �ϴ� �ܰ�(�������ϴ� �ܰ�)���� �Ϻ��ϰ� �ٲ�ġ���.
// ���� ������� ����� ��ü�� ��.

// �������� �ƹ��� �ø��ٰ� �ϴ���. �޸� �� ������ �κ��� �ƴϴ�.
// �������� ���̱� ���ؼ� 1�̶�� �� ��� �����.
enum ENUM_SRP // enum �̸� ����
{
	ENUM_SCISSORS = 1,// 1
	ENUM_ROCK,//2
	ENUM_PAPER// ��������( , )�� �־��൵ �ǰ� �ȳ־��൵��.// 3
};

//const�� ����ϴ°� ���� enum�� ����ϴ°� �� ����.


// #�� ������ -> ��ó�� ���ù�
// #include<iostream>�̶�� ������ ã�Ƽ� �ش� ������ �׳� ����!
// 
// ��ó����? 
// ctrl + shift + b = ����
// ������ ���� : 1.��ó��(�غ�) 2.������(�뿪, ���) 3.��ũ(���� ��������� ���´�)
#define DEFINE_SCISSORS 1// define�� ��ũ�θ� ����� ��ó����� : DEFINE_SCISSORS ������ �����ϸ� 1�� ��ü
#define DEFINE_SCISSORS2 1+2// 1 + 2 �� �ٲ�ġ�� ��. 3�̶�� �����ϸ� �ȵ�.
#define DEFINE_TEST cout<<"Hello World"<<endl;
// define ���ٴ� enum�� �켱����!
// ������Ҷ� ��ó���ܰ踦 ������ ���� �ȶ��.!!
// enum�� ���ٸ�, ����� �Ҷ� ���� ���.!!
// define�� ��������.



int main()
{

	DEFINE_TEST;

	srand(time(0));// �õ� ���� srand�� rand�� ¦���̴�.
	// �̷� ��� ���� �޸𸮿� const ������ �Ҵ� �ȴ�.
	//const int SCISSORS = 1;// const�� �ʱⰪ�� �ݵ�� �־������. ENUM�� �� �־��൵��.
	//const int ROCK = 2;
	//const int PAPER = 3;
	
//	auto a = &SCISSORS;// �̷��� �ϸ� 
	

		// Rookiss Ǯ��

	// ���� ��ü�� �ڵ�ȿ� ���� �ִ°� �ſ� ������ �����̴�.
	// �� �ڵ�� ���ڸ� �׳� �ȿ� �־��µ�, �� �κ��� �Ʒ��� ���� ��ġ���� ����.
	// 
	// ���ȭ : �̸��� �����༭ ������ ���
	// �̷��� �ϴ°� �ٶ�����!.

	//const int SCISSORS = 1;
	//const int ROCK = 2;
	//const int PAPER = 3;

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

		if (input == ENUM_SCISSORS)
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