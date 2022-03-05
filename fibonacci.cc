#include <bits/stdc++.h>
using namespace std;

vector<int>v(1e6, -1);
int fib(int n) {
	if (n < 1) return 1;
	if (v[n] != -1) return v[n];
	return v[n] = fib(n-1)+fib(n-2);
}


int main(){
	fib(1e6-1);
	for (int i = 0; i < 4; ++i) {
		int n;
		cin >> n;
		cout << fib(n-2) << " ";
	}
	cout << endl;
}