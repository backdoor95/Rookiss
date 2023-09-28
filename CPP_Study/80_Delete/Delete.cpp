#include<iostream>
#include<vector>
#include<list>
using namespace std;

// ������ ���� : delete(������ �Լ�)

class Knight
{
public:

	void operator=(const Knight& k) = delete;// �̷��� �������! ��, public ���� �ϴ°� ����
	// �츮�� �� �Լ��� �������� �ʰڴٶ�� ������� �޽����� �����ټ� �ִ�.

private:
	// ���ǵ��� ���� ����� �Լ�
	//void operator=(const Knight& k); // ������ ������ �����.


	// ��� ���� �մ� â vs ���� ����
	friend class Admin;// Admin ���״� �ޱ��� ������. private�� �����Ҽ� �ְ� ��.

private:
	int _hp = 100;
};

class Admin
{
public:
	void CopyKnight(const Knight& k)
	{
		Knight k1;
		// ���� ����
		k1 = k;
	}
};

int main()
{
	Knight k1;

	Knight k2;

	// ���� ������
	//k1 = k2;


	return 0;
}