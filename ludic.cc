#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin >> n;
	vector<bool>ludic(n+1, true);
	if (n == 0) return 0;
	cout << 1;
	for (int i = 2; i <= n; ++i) {
		if (ludic[i]) {
			cout << ' ' << i;
			int counter = 0;
			for (int j = i+1; j <= n; ++j) {
				if (ludic[j]) ++counter;
				if (counter%i == 0) {
					counter = 0;
					ludic[j] = false;
				}
			}
		}
	}
	cout << endl;
}