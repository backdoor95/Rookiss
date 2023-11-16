#include<bits/stdc++.h>	
using namespace std;
map<int, int> mp;
vector<int> v2{ 1,1,2,2,3,3,5,6,7,8,9 };
int main() {

	vector<int> v{ 1,1,2,2,3,3 };
	for (int i : v) {
		if (mp[i]) {
			continue;
		}
		else {
			mp[i] = 1;
		}
	}
	vector<int> ret;
	
	for (auto it : mp) {
		ret.push_back(it.first);
	}


	for (int i : ret)cout << i << endl;

	cout << "========================" << endl;
	sort(v2.begin(), v2.end());
	//auto it = unique(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());
	for (int i : v2)cout << i << " ";
	cout << endl;
	
	//cout << it - v2.begin() << endl;



	return 0;
}