#pragma once
//#include"Player.h"// �츮�� include�� �������� �߰��ϰ� �Ǹ� [��ȯ��������]�� �߻��� �� �ִ�.
// ��ȯ ���� ������ �߻��ϸ� ���尡 �����Ѵ�.

// ���漱�� - Player Ŭ������ ���߿� ���� �Ұ����� �˷���. include ��ſ� ���漱���� �ϸ� �������� �ȶ��.
class Player;

// is - a : game�� player ��?  (x)
// 
// has - a : game�� player�� ������ �ֳ�?(o)-> ���԰���
class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:

	//Player _player;// �̷��� ������ ���°� �ƴ� ���Ŭ������ ��� �ִ°� ������ ������.
	// ���� �� ����� Knight�� �ް� �ȴٸ� Knight�� �޸� ũ�Ⱑ player���� ũ�� ������
	// �κ������� ©���� �ȴ�.!!

	// [ 4~8 ] ����Ʈ �ٱ���(�ּ�) ---> [					]
	Player* _player;// �����ͷ� Ŭ������ ����ִ°� ����.


};

