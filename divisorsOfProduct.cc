#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9+7;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int>v(1e6+1, 1);
	vector<int>primes;
	for (int i = 2; i < 1e6+1; ++i) {
		if (v[i] == 1) {
			primes.push_back(i);
			v[i] = i;
		}
		for (int j = 0; j < primes.size() && i*primes[j] < 1e6+1; ++j) {
			v[i*primes[j]] = primes[j];
			if (i % primes[j] == 0) break;
		}
	}

	int n, x;
	cin >> n;
	vector<int>sol(1e6+1, 0);
	while (n--) {
		cin >> x;
		int count = 0, currVal = -1;
		while (x != 1) {
			if (v[x] != currVal) {
				if (currVal != -1) {
					sol[currVal] += count;
				}
				currVal = v[x];
				count = 1;
			}
			else ++count;
			x /= v[x];
		}
		sol[currVal] += count;
	}
	long long ans = 1;
	for (int i = 0; i < 1e6+1; ++i) {
		ans = (ans*(sol[i]+1))%MOD;
	}
	cout << ans << endl;
}