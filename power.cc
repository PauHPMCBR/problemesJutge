#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	while (cin >> n >> m) {
		int res = 1;
		for(int i = 0; i < m; ++i){
			res *= n;
		}
		cout << res << endl;
	}
}