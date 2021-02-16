#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> col;	
vector <bool> dig1;
vector <bool> dig2;
bool lel = false;

void escriu() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (col[j] == i) cout << 'Q';
			else cout << '.';
		}
		cout << endl;
	}
	//cout << endl;
	lel = true;
}

void backtrack(int p) {
	if (lel) return;
	if(p == n) return escriu();
	for (int i = 0; i < n; ++i) {
		if (col[i] >= 0) continue;
		if (dig1[n-1+i-p]) continue;
		if (dig2[2*n-2-i-p]) continue;
		col[i] = p;
		dig1[n-1+i-p] = true;
		dig2[2*n-2-i-p] = true;
		backtrack(p+1);
		col[i] = -1;
		dig1[n-1+i-p] = false;
		dig2[2*n-2-i-p] = false;
	}
}


int main(){
	cin >> n;
	col = vector <int>(n, -1);
	dig1 = vector <bool>(n, false);
	dig2 = vector <bool>(n, false);
	backtrack(0);
	if (!lel) cout << "NO SOLUTION" << endl;
}