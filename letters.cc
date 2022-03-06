#include <bits/stdc++.h>
using namespace std;
string s1, s2, s;
set<int>letters;
vector<char>v;
map<char,int>m;
set<char>cantBeZero;
bool sol;

int getVal(string ss) {
	int res = 0;
	for (auto i : ss) {
		res *= 10;
		res += m[i];
	}
	return res;
}

void b(int pos) {
	if (sol) return;
	if(pos == v.size()) {
		if (getVal(s1) + getVal(s2) == getVal(s)) {
			sol = true;
			cout << getVal(s1) << '+' << getVal(s2) << '=' << getVal(s) << endl;
		}
		return;
	}
	for (int i = 0; i < 10; ++i) {
		if (i == 0 && cantBeZero.count(v[pos])) continue;
		m[v[pos]] = i;
		b(pos+1);
	}
}

int main(){	
	cin >> s1 >> s2 >> s;
	for (auto i : s1) letters.insert(i);
	for (auto i : s2) letters.insert(i);
	for (auto i : s) letters.insert(i);
	for (auto i : letters) v.push_back(i);
	cantBeZero.insert(s1[0]);
	cantBeZero.insert(s2[0]);
	cantBeZero.insert(s[0]);
	b(0);
	if (!sol) cout << "NO SOLUTION" << endl;
}