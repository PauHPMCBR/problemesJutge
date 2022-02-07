#include <bits/stdc++.h>
using namespace std;
int n, sum;
vector<int>v;
int b(int pos, int val) {
	if (pos == n) return (abs(sum-2*val));
	return min(b(pos+1, val), b(pos+1, val+v[pos]));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (cin >> n) {
		v = vector<int>(n);
		sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			sum += v[i];
		}
		cout << b(0,0) << endl;
	}
}