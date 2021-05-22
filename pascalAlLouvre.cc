#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>p2(31);
vector<ll>p3(31);

void calculatePowers() {
	p2[0] = 1;
	p3[0] = 1;
	for (int i = 1; i < 31; ++i) {
		p2[i] = p2[i-1]*2;
		p3[i] = p3[i-1]*3;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, k;
	calculatePowers();
	while (cin >> k >> n) {
		if (k%2 == 0 || n == 0) {
			cout << 0 << endl;
		}
		else {
		    ll sum = 0;
            int pos = -1;
            for (int i = 31; i >= 0; --i) {
                if ((n>>i) & 1) {
                    ++pos;
                    sum += p3[i] * p2[pos];
                }
            }
            cout << sum << endl;
		}
	}
}