#include <bits/stdc++.h>
using namespace std;

/*vector<vector<vector<int>>>v(10, vector<vector<int>>(10, vector<int>(10, -1)));

int f(int i, int j, int k) {
	if (i < 0 or j < 0 or k < 0) return 0;
	if (v[i][j][k] != -1) return v[i][j][k];
	if (f(i-1,j-1,k+1)) return v[i][j][k] = 1;
	if (f(i-1,j+1,k-1)) return v[i][j][k] = 1;
	if (f(i+1,j-1,k-1)) return v[i][j][k] = 1;
	return v[i][j][k] = 0;
}*/

int main(){
	long long a,b,c;
	while (cin >> a >> b >> c) {
		if (a%2 == b%2 and a%2 == c%2) cout << "NO" << endl;
		else {
			if (((a == 0 and b == 0) or (b == 0 and c == 0) or (a == 0 and c == 0)) and a+b+c != 1) cout << "NO" << endl;
			else cout << "YES" <<  endl;
		}
	}
	/*v[1][0][0] = 1;
	v[0][1][0] = 1;
	v[0][0][1] = 1;
	v[0][0][0] = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				f(i,j,k);
				if(!v[i][j][k]) cout << i << ' ' << j << ' ' << k << endl;
			}
		}
	}*/
}