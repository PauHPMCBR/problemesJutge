#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>v;
int amount = 0;
void say(int pos) {
	if (pos == 0) {
		cout << amount << endl;
		return;
	}
	amount += (v[pos] == 1);
	say(pos-1);
	if (v[pos] == 1) cout << pos << ' ';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	v = vector<int>(n+1, 0);
	for (int i = 1; i < n; ++ i) {
		int a,b;
		cin >> a >> b;
		++v[a];
		++v[b];
	}
	say(n);
	cout << endl;
}