#include<iostream>
using namespace std;

// ������ ���� : ���м�

// ��ü���� (OOP)
// - ��Ӽ�
// - ���м� = ĸ��ȭ
// - ������

// ���м�(Data Hiding) = ĸ��ȭ(Encapsulation)
// ���� �Ǵ� ���� ����ϰ� ����ڴ�!
// ����� ����?
// 1) ���� �����ϰ� �ǵ帮�� �ȵǴ� ���
// 2) �ٸ� ��η� �����ϱ� ���ϴ� ���

// �ڵ���
// - �ڵ�
// - ���
// - ����
// - ��
// - ���� ���⼱

// �Ϲ� ���Ű� ���忡�� ����ϴ� ��?
// - �ڵ�/���/��
// ���� ��(������ �ǵ帮�� ū�ϳ�)
// - ����, ���� ���⼱


// public(������?)	protected(��ȣ�޴�)	private(������)
// - public : �������׳� ������.
// - protected : ���� �ڼյ����׸� ���
// - private : ���� ����Ҳ�! << class Car ���ο����� ����Ұ�

// ��� ���� ������ : ���� �������� �θ���� ������ ��� ��������?----> ���� public �� ����.!!!
// �θ������ �������� ������ �� ���� �ڼյ����׵� �Ȱ��� ������� ���� ����.
// - public : ������ ���? �θ���� ���� ���� �״��~(public(�θ�) -> public(��) , protected(�θ�) -> protected(��))
// - protected : ��ȣ���� ���? �� �ڼյ����׸� �����ٲ���(public(�θ�) -> protected(��), protected(�θ�) -> protected(��))
// - private: �������� ���? �������� �� ���� �ڼյ����״� �ƿ� �� �����ٲ���~ (public(�θ�) -> private(��), protected(�θ�) -> private(��))

// �ٸ� ������ ��� ���� �����ڰ� ���� ��찡 �ִ�.
// ��������ڿ��� 

class Car
{
public:// ���� ������.
	void MoveHandle(){ }
	void PushPedal(){ }
	void OpenDoor(){ }

	void TurnKey()
	{
		RunEngine();
	}

protected:
	void DisAssembleCar(){ }// ���� ����
	void RunEngine(){ }// ������ ������Ų��.
	void ConnectCircuit(){ }// ���⼱ ����
public:
	// �ڵ�
	// ���
	// ����
	// ��
	// ���� ���⼱

};

//class SuperCar : public Car // ��� ���� ������
//{
//public:
//	void PushRemoteController()
//	{
//		RunEngine();// private�϶� ������. --> protected�� �ٲٸ� ��밡��.
//	}
//};



class SuperCar : private Car // ��� ���� ������
{
public:
	void PushRemoteController()
	{
		RunEngine();// private�϶� ������. --> protected�� �ٲٸ� ��밡��.
	}
};

/*
C++������ ��� ���� �������� default�� private�̰�, Java������ ��� ���� �����ڸ� ���� ������ �� ���� �⺻������ ����� public�Դϴ�.
*/
class TestSuperCar : SuperCar // �̷��� �ϸ� [private SuperCar]�� �ν���.
{
public:
	void Test()
	{
		//DisAssembleCar();// �� �̻� ��� ����.!!1
	}
};


// 'ĸ��ȭ' 
// ������ �����Ϳ� �Լ��� �������� ���������


class Berserker
{
public:

	int GetHp() { return _hp; }

	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}

	// ��� : ü���� 50 ���Ϸ� �������� ����Ŀ ��� �ߵ� (������)
private:
	void SetBerserkerMode()
	{
		cout << "�ſ� ������!" << endl;
	}


private:
	int _hp = 100;
};


int main()
{

	Car car;

	//car.DisAssembleCar();
	//car.RunEngine();

	Berserker b;

	TestSuperCar testCar;
	testCar.Test();

	return 0;
}