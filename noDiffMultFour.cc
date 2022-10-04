#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	vector<int>v = {8,5,2,3,8,5,2,3};
	while (cin >> n >> m) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int prov;
				cin >> prov;
				if (i%2) {
					if (j%2) cout << prov + v[3-(prov%4)];
					else cout << prov + v[4-(prov%4)];
				}
				else {
					if (j%2) cout << prov + v[5-(prov%4)];
					else cout << prov + v[6-(prov%4)];
				}
				if (j != m-1) cout << ' ';
			}
			cout << endl;
		}
		cout << "--------------------" << endl;
	}
}