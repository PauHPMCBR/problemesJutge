#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cout.setf(ios::fixed);
   	cout.precision(2);

	int n;
	while (cin >> n) {
		vector<ll>v(n);
		double sum = 0;
		for (int i = 0; i < n; ++i) {cin >> v[i]; sum += v[i];}
		sort(v.begin(), v.end());
		ll a = v[n/2-1];
		ll b = v[n/2];
		double sol1 = max(abs((sum-v[n-1])/(n-1) - a), abs((sum-v[n/2])/(n-1) - a));
		double sol2 = max(abs((sum-v[0])/(n-1) - b), abs((sum-v[n/2-1])/(n-1) - b));
		cout << max(sol1, sol2) << endl;
	}
}