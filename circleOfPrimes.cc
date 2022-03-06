#include <bits/stdc++.h>
using namespace std;

vector<bool>primes(1e5+1, 1);
set<int>primList;
int lastPos = 1;
void getPrimes() {
	for (int i = 2; i < 1e5; ++i) {
		if (primes[i]) {
			//cout << i << endl;
			primList.insert(i);
			for (int j = 2*i; j < 1e5; j += i) primes[j] = 0;
		}
	}
}

int main(){
	int n;
	cin >> n;
	getPrimes();
	primList.insert(1);
	while (n--) {
		int x;
		cin >> x;
		vector<bool>v(x, 0);
		v[0] = 1;
		int changed = 1;
		for (auto i : primList) {
			if (v[i%x] == 0) {
				v[i%x] = 1;
				++changed;
			}
		}
		if (changed == x) cout << "The circle can be completed." << endl;
		else {
			cout << "The circle cannot be completed. Container/s ";
			for (int i = 0; i < x; ++i) {
				if (!v[i]) {
					cout << i << ", ";
				}
			}
			cout << "won't be prepared." << endl;
		}
	}
}