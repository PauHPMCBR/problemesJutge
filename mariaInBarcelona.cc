#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, m;
	cin >> n >> m;
	if (n%m == 0) cout << n/m << endl;
	else cout << n/m+1 << endl;
}