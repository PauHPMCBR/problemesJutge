#include <bits/stdc++.h>
using namespace std;

int lastCalc = 0;
vector<vector<int>>v0(2e4+2, vector<int>(1e4+2)); //ends with "(("
vector<vector<int>>v1(2e4+2, vector<int>(1e4+2)); //ends with ")"
vector<vector<int>>v2(2e4+2, vector<int>(1e4+2)); //ends with ")("

int main() {
	v0[1][1] = 1;
	for (int i = 2; i <= 2e4+1; ++i) {
		v1[i][0] = v0[i-1][1] + v1[i-1][1] + v2[i-1][1];
		for (int j = 1; j < 1e4+1; ++j) {
			v0[i][j] = v0[i-1][j-1] + v2[i-1][j-1];
			v1[i][j] = v0[i-1][j+1] + v1[i-1][j+1] + v2[i-1][j+1];
			v2[i][j] = v1[i-1][j-1];
		}
	}
	cout << "done" << endl;
	int n;
	while (cin >> n) {
		cout << v1[n*2][0] << endl;
	}
}