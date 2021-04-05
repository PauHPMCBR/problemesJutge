#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	vector<int>v(1);
	v[0] = 0;
	map<char,int>m;
	int j = 1;
	while(cin >> s) {
		if (s[0] <= '9' && s[0] >= '0') continue;
		for (auto c : s) {
			if (c == '-') continue;
			if (m[c] != 0) ++v[m[c]];
			else {
				m[c] = j;
				v.push_back(1);
				++j;
			}
		}
	}
	int total = 0;
	for (auto i : v) {
		total += (i/100)+1;
		if (i%100 == 0) --total;
	}
	cout << "- " << total << " skeins of yarn -" << endl;
	for (auto i : m) {
		int mobe = (v[i.second]/100)+1;
		if ((v[i.second]%100) == 0) --mobe;
		cout << "- " << mobe << " skeins of yarn " << i.first << endl;
	}
}