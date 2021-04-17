#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	int pos = 0;
	for (int i = 0; i < m; ++i) {
		int pers; 
		cin >> pers;
		while (pos < n && pers >= v[pos]) {
			pers -= v[pos];
			++pos;
		}
	}
	cout << pos << endl;
}