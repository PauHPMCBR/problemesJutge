#include <bits/stdc++.h>
using namespace std;

int f(int a) {
	if (a == 1) return 1;
	return f(a-1)*a;
}

int main(){
	int a;
	cin >> a;
	cout << f(a) << endl; // a! = a*(a-1)(a-2)(a-3)...
}