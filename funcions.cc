#include <bits/stdc++.h>
using namespace std;

vector<int>v;

void f(int n, int a, int d) {
	v[0] = a;
	for (int i = 1; i < n; ++i) {
		v[i] = v[i-1]+d;
	}
}

int main(){
	int n, a, d;
	cin >> n >> a >> d;
	v = vector<int>(n);
	f(n, a, d);
	for (int i = 0; i < n; ++i) {
		cout << v[i] << ' ';
	}
	cout << endl;
}