#include<iostream>
using namespace std;

// 오늘의 주제 : 은닉성

// 객체지향 (OOP)
// - 상속성
// - 은닉성 = 캡슐화
// - 다형성

// 은닉성(Data Hiding) = 캡슐화(Encapsulation)
// 몰라도 되는 것은 깔끔하게 숨기겠다!
// 숨기는 이유?
// 1) 정말 위험하고 건드리면 안되는 경우
// 2) 다른 경로로 접근하길 원하는 경우

// 자동차
// - 핸들
// - 페달
// - 엔진
// - 문
// - 각종 전기선

// 일반 구매가 입장에서 사용하는 것?
// - 핸들/페달/문
// 몰라도 됨(오히려 건드리면 큰일남)
// - 엔진, 각종 전기선


// public(공개적?)	protected(보호받는)	private(개인의)
// - public : 누구한테나 공개함.
// - protected : 나의 자손들한테만 허락
// - private : 나만 사용할꺼! << class Car 내부에서만 사용할것

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줄지?----> 거의 public 만 사용됨.!!!
// 부모님한테 물려받은 유산을 꼭 나의 자손들한테도 똑같이 물려줘야 하진 않음.
// - public : 공개적 상속? 부모님의 유산 설계 그대로~(public(부모) -> public(나) , protected(부모) -> protected(나))
// - protected : 보호받은 상속? 내 자손들한테만 물려줄꺼야(public(부모) -> protected(나), protected(부모) -> protected(나))
// - private: 개인적인 상속? 나까지만 잘 쓰고 자손들한테는 아에 안 물려줄꺼야~ (public(부모) -> private(나), protected(부모) -> private(나))

// 다른 언어에서는 상속 접근 지정자가 없는 경우가 있다.
// 상속지정자에서 

class Car
{
public:// 접근 지정자.
	void MoveHandle(){ }
	void PushPedal(){ }
	void OpenDoor(){ }

	void TurnKey()
	{
		RunEngine();
	}

protected:
	void DisAssembleCar(){ }// 차를 분해
	void RunEngine(){ }// 엔진을 구동시킨다.
	void ConnectCircuit(){ }// 전기선 연결
public:
	// 핸들
	// 페달
	// 엔진
	// 문
	// 각종 전기선

};

//class SuperCar : public Car // 상속 접근 지정자
//{
//public:
//	void PushRemoteController()
//	{
//		RunEngine();// private일때 사용못함. --> protected로 바꾸면 사용가능.
//	}
//};



class SuperCar : private Car // 상속 접근 지정자
{
public:
	void PushRemoteController()
	{
		RunEngine();// private일때 사용못함. --> protected로 바꾸면 사용가능.
	}
};

/*
C++에서는 상속 접근 지정자의 default가 private이고, Java에서는 상속 접근 지정자를 따로 설정할 수 없어 기본적으로 상속은 public입니다.
*/
class TestSuperCar : SuperCar // 이렇게 하면 [private SuperCar]로 인식함.
{
public:
	void Test()
	{
		//DisAssembleCar();// 더 이상 사용 못함.!!1
	}
};


// '캡슐화' 
// 연관된 데이터와 함수를 논리적으로 묶어놓은것


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

	// 사양 : 체력이 50 이하로 떨어지면 버서커 모드 발동 (강해짐)
private:
	void SetBerserkerMode()
	{
		cout << "매우 강해짐!" << endl;
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