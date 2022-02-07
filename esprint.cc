#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>dp(1e6, -1);
int b(int pos) {
	if (dp[pos] != -1) return dp[pos];
	if (pos < 100) return dp[pos] = b(b(pos+6));
	else return dp[pos] = pos-3;
}

int main(){
	/*int cnt = 0;
	for (int i = 1; i < 7; ++i) {
		for (int j = 1; j < 7; ++j) {
			for (int k = 1; k < 7; ++k) {
				if (i+j == 6 || i+k == 6 || j+k == 6) {
					++cnt;
				}
			}
		}
	}
	cout << cnt << endl;*/
	cout << b(1) << endl;
}