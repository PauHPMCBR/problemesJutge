#include <bits/stdc++.h>
using namespace std;

int main(){
	string s, s2;
	cin >> s2;
	vector<int>v(26);
	int siz = s2.size();
	for (auto i : s2) ++v[i-'a'];
	bool first = true;
	while (cin >> s) {
		if (s == s2) continue;
		vector<int>v2 = v;
		bool possible = (siz == s.size());
		for (auto i : s) {
			--v2[i-'a'];
			if (v2[i-'a'] < 0) possible = false;
		}
		if (possible) {
			if (first) first = false;
			else cout << ' ';
			cout << s;
		}
	}
	cout << endl;
}