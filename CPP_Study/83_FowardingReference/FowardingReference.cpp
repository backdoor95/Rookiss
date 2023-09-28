#include<iostream>

// ������ ���� : ���� ���� (forwarding reference)

using namespace std;

class Knight
{
public:
	Knight() { cout << "�⺻ ������" << endl; }
	Knight(const Knight&) { cout << "���� ������" << endl; }
	Knight(Knight&&) noexcept { cout << "�̵� ������" << endl; }

};

void Test_RValueRef(Knight&& k)// ������ ���� --> �̵���� << �̶�� ��Ʈ
{

}

void Test_Copy(Knight k)
{

}

// �Լ��� �ѹ��� ó���� �� �ְ� �Ǿ��� 
template<typename T>
void Test_ForwardingRef(T&& param)// ���� ����
{
	//[T&&] �̷������� �ؾ� ���� ������. 
	// const T&& �̷��� �ϳ��� �� �ٿ��ִ� ���� ���� ������ �������� ����.
	// const T&& << ������ ������ ������.

	//TODO
	Test_Copy(param);// 

	Test_Copy(move(param));// �̷��� �ؾ� �̵������ڰ� ȣ���.

	// �츮�� �Ѱ��� ���� 
	// �ް� ������� �����ϴ� ���·� - 1
	TestCopy(param);

	// ������ ������� �̵��ϴ� ���·� - 2
	TestCopy(move(param));

	// 1, 2�� �˾Ƽ� ���ִ� �� ---> �ѹ��� ó������!
	Test_Copy(forward<T>(param));

	


}

int main()
{
	// ���� ���� (universal reference) or ����������� �θ� 
	// ���� ���� (forwarding reference) C++17

	// &&  &�� �� �� -> ������ ����


	Knight k1;

	//Test_RValueRef(k1);// k1�� �ް��̱⶧���� �����߻�
	Test_RValueRef(move(k1));// rvalue_cast

	// ��쿡 ���󼭴� �ް� ����, ������ ���� �� ���Ҽ� �ִ�.
	Test_ForwardingRef(move(k1));// ������ �־�Z���� ������ ����
	Test_ForwardingRef(k1);// ���ʰ� �־������� �ް� ����

	// ī�᷹�� ������
	auto&& k2 = k1;// ���� ������ ��ȯ
	auto&& k3 = move(k1);// ������ ������ ��ȯ

	// ���� :  ���� ������ ���÷��̳� auto�� ���� �������� �����ؼ� ����Ҷ��� �����Ѵ�.

	// ������ : ���� ����( type deduction)�� �Ͼ ��

	// ���� ������ �����ϴ� ���
	// ------------------------------------------------------------------------------------

	Knight& k4 = k1;// �ް� ����
	Knight&& k5 = move(k1);// ������ ���� o , k5 ��ü�� �ް��̴�.

	// ������ : �ް��� �ƴϴ� = ���ϽĿ��� ����� ���x
	// ������ ���� : �������� ������ �� �ִ� ���� Ÿ��

	//Test_RValueRef(k5);// �����߻� ������ ���� o , k5 ��ü�� �ް��̴�
	Test_RValueRef(move(k5));// �����߻�

	
	Test_ForwardingRef(k1);
	Test_ForwardingRef(move(k1));

	// ������ : ���� ������ ������ forward�� �������!!

	return 0;
}
