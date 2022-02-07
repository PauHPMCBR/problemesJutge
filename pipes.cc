#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		bool possible = true;
		vector<string>v(2);
		cin >> v[0] >> v[1];
		int x = 0, y = 0;
		bool prevHorizontal = true;
		while (true) {
			if (x == n && y == 1) break;
			if (prevHorizontal) {
				if (v[y][x] < '3') {
					++x;
				}
				else {
					y = !y;
					prevHorizontal = false;
				}
			}
			else {
				if (v[y][x] < '3') {
					possible = false; //?
					break;
				}
				else {
					++x;
					prevHorizontal = true;
				}
			}
		}
		if (prevHorizontal && v[y][x] >= '3') possible = false;
		if (!prevHorizontal && v[y][x] < '3') possible = false;
		cout << (possible ? "YES" : "NO") << endl;
	}
}