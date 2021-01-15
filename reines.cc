#include <bits/stdc++.h>
using namespace std;

int n;
vector <bool> fil;
vector <bool> col;
vector <bool> dig1;
vector <bool> dig2;

int backtrack(int p) {
	if(p == n) return 1;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (col[i]) continue;
		if (dig1[n-1+i-p]) continue;
		if (dig2[2*n-2-i-p]) continue;
		col[i] = true;
		dig1[n-1+i-p] = true;
		dig2[2*n-2-i-p] = true;
		count += backtrack(p+1);
		col[i] = false;
		dig1[n-1+i-p] = false;
		dig2[2*n-2-i-p] = false;
	}
	return count;
}


int main(){
	cin >> n;
	fil = vector <bool>(n, false);
	col = vector <bool>(n, false);
	dig1 = vector <bool>(n, false);
	dig2 = vector <bool>(n, false);
	cout << backtrack(0) << endl;
}