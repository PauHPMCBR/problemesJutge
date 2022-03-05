#include <bits/stdc++.h>
using namespace std;

string s1, s2, s;
vector<vector<int>>v;
bool b(int p1, int p2, int p) {
	if (p == s.size()) return true;
	if (v[p1][p2] != -1) return v[p1][p2];
	if (p1 < s1.size()) if (s1[p1] == s[p]) if (b(p1+1, p2, p+1)) return v[p1][p2] = true;
	if (p2 < s2.size()) if (s2[p2] == s[p]) if (b(p1, p2+1, p+1)) return v[p1][p2] = true;
	return v[p1][p2] = false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> s1 >> s2 >> s) {
		v = vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1, -1));
		cout << (b(0,0,0) ? "yes" : "no") << endl;
	}
}