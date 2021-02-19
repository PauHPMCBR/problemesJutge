#include <bits/stdc++.h>
using namespace std;

int factor_mes_gran(int n) {
	for(int i = 2; i*i <= n; ++i) {
		while(n%i == 0) n/=i;
		if (n == 1) return i;
	}
	return n;
}

int main(){
	int n;
	cin >> n;
	cout << factor_mes_gran(n) << endl;
}