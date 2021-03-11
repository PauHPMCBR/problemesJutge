#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	cout << string(2*n-1, ' ') << string(n, '_') << endl;
	for (int i = 1; i < n; ++i) cout << string(2*n-i-1, ' ') << "_|" << endl;
	cout << string(n, '_') << "|" << endl;
}