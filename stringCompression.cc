#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int>v(n, 0);
	int l = 0, r = -1;
	for (int i = 1; i < n; ++i) {
		if (i <= r) v[i] = min(v[i-l], r-i+1);
		while (i+v[i] < n && s[i+v[i]] == s[v[i]]) ++v[i];
		if (v[i] > 0 && i+v[i]-1 > r) {
			r = i+v[i]-1;
			l = i;
		}
	}
	for (int i = 1; i <= n/2; ++i) {
		if (n%i == 0) {
			bool possible = true;
			for (int j = i; j < n; j += i) {
				if (v[j] < i) {possible = false; break;}
			}
			if (possible) {
				cout << s.substr(0,i) << endl;
				return 0;
			}
		}
	}
	cout << s << endl;
}