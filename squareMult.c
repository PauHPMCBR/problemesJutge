#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int>primes;
int n;
vector<int>b;
vector<int>a;
vector<vector<int>>v;
unordered_set<int>s;

vector<bool>provPrime;
void getPrimes(int x) {
	provPrime = vector<bool>(x, true);
	for (int i = 2; i < x; ++i) {
		if (provPrime[i]) {
			if (i >= x/2) primes.insert(i);
			for (int j = i*2; j < x; j += i) provPrime[j] = false;
		}
	}
}


bool check(int x) {
	return a[x] == b[x];
}

int maxim = 0;
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
		if (!check(y)) return;
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
	for (int i = 1; i <= n*n; ++i) {
		if (primes.count(i)) continue;
		if (!f) if (provMul%i != 0) continue;
		if (!s.count(i)) {
			if (!f) provMul /= i;
			s.insert(i);
			v[x][y] = i;
			a[x] *= i;
			b[y] *= i;
			if (f) {
				sol(x, y+1, f);
			}
			else {
				sol(x+1, y, f);
			}
			v[x][y] = -1;
			a[x] /= i;
			b[y] /= i;
			s.erase(i);
			if (!f) provMul *= i;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin >> n;
	getPrimes(n*n);
	a = vector<int>(n, 1);
	b = vector<int>(n, 1);
	v = vector<vector<int>>(n, vector<int>(n, -1));
	sol(0,0,true);
	cout << sols << endl;
}
