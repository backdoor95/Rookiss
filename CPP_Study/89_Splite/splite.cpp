#include<bits/stdc++.h>
using namespace std;
vector<string> split(string input, string delimeter)
{
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(delimeter)) != string::npos)
	{
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimeter.length());
	}
	ret.push_back(input);
	return ret;
}

int main()
{
	string s = "�ȳ��ϼ��� ȫ�浿�� ����Դϴ�. �Ի� 2���� �Դϴ�.!", d = " ";// d�� delimeter
	vector<string> a = split(s, d);
	for (string b : a)cout << b << endl;

	cout << "_____________________" << endl;
	int oa = 421;
	int* p = &oa;


	cout << " *p = "<< * p << endl;
	cout << " oa = "<< oa << endl;

	oa = 10000;

	cout << " *p = "<< * p << endl;
	cout << " oa = "<< oa << endl;

	*p = 22222222;
	cout << " *p = " << *p << endl;
	cout << " oa = " << oa << endl;
}