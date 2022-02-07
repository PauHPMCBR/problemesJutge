#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int pos = -1, maxSize = 0;
int lcs(int p1, int p2) {
	if (p1 == s1.size() || p2 == s2.size()) return 0;
	if (s1[p1] == s2[p2]) return lcs(p1+1, p2+1)+1;
	int prov = max(lcs(p1+1, p2), lcs(p1, p2+1));
	if (prov > maxSize) {
		maxSize = prov;
		pos = p1;
	}
	return prov;
}


int main(){
	int n, m;
	cin >> n >> m;
	cin >> s1 >> s2;
	lcs(0, 0);
	cout << maxSize << endl;
	if (maxSize == 0) return 0;
	cout << s1.substr(pos+1, maxSize) << endl;
}