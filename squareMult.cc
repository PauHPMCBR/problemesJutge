#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<bool>primes;
int n;
vector<int>b;
vector<int>a;
vector<vector<int>>v;
vector<bool>used;

vector<bool>provPrime;
void getPrimes(int x) {
	provPrime = vector<bool>(x, true);
	for (int i = 2; i < x; ++i) {
		if (provPrime[i]) {
			if (i >= x/2) primes[i] = true;
			for (int j = i*2; j < x; j += i) provPrime[j] = false;
		}
	}
}

int maxim = -10;
int provMul = -1;
int sols = 0;
void sol(int x, int y, bool f) {
	if (sols > maxim+10) {
		maxim = sols;
		cout << maxim << endl;
	}
	if (x == n && y == n) {
		++sols;
		return;
	}
	if (y == n) {provMul = a[x]; return sol(x+1, x, !f);}
	if (x == n) {
		if (a[y] != b[y]) return;
		return sol(y+1, y+1, !f);
	}
	if (x == y) {
		v[x][y] = 1;
		if (f) {
			return sol(x, y+1, f);
		}
		else {
			return sol(x+1, y, f);
		}
	}
	if (f) {
		for (int i = 1; i <= n*n; ++i) {
			if (primes[i]) continue;
			if (!used[i]) {
				used[i] = true;
				v[x][y] = i;
				a[x] *= i;
				b[y] *= i;
				sol(x, y+1, f);
				a[x] /= i;
				b[y] /= i;
				used[i] = false;
			}
		}
	}
	else {
		for (int i = 1; i <= n*n; ++i) {
			if (primes[i]) continue;
			if (provMul%i != 0) continue;
			if (!used[i]) {
				provMul /= i;
				used[i] = true;
				v[x][y] = i;
				a[x] *= i;
				b[y] *= i;
				sol(x+1, y, f);
				a[x] /= i;
				b[y] /= i;
				used[i] = false;
				provMul *= i;
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a = vector<int>(n, 1);
	b = vector<int>(n, 1);
	used = vector<bool>(n*n+1, 0);
	primes = vector<bool>(n*n+1, 0);
	getPrimes(n*n);
	v = vector<vector<int>>(n, vector<int>(n, -1));
	sol(0,0,true);
	cout << sols << endl;
}
