#include <bits/stdc++.h>
using namespace std;
int n, x, sum=0, price=0;
vector<int>v;
vector<int>p;
vector<vector<int>>s;

int b(int pos, int money) {
	if (money < 0) return -1;
	if (money == 0) return 0;
	if (pos < 0) return 0;
	if (s[pos][money] != -1) return s[pos][money];
	if (money-v[pos] < 0) return s[pos][money] = b(pos-1, money);
	int a = b(pos-1, money-v[pos]);
	return s[pos][money] = max(a+p[pos], b(pos-1, money));
}

int main(){
	cin >> n >> x;
	p = vector<int>(n);
	v = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		price += v[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		sum += p[i];
	}
	if (price <= x) cout << sum << endl;
	else {
		s = vector<vector<int>>(n, vector<int>(sum+1, -1));
	}
	int money=x;
	int pags = 0;
	int maxPags = 0;
	for(int i = n-1; i >= 0; ++i) {

		if (pags > maxPags) maxPags = pags;
		pags = 0;
	}



	cout << b(n-1,x) << endl;
}