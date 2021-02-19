#include <bits/stdc++.h>
using namespace std;

set <int> primes;
int n;
vector <int> b;
vector <int> a;
vector <vector <int> >v;
set <int> s;

bool isPrime(int x) {
	if (x < 2) return false;
	if (x == 2) return true;
	if (x%2 == 0) return false;
	for (int i = 3; i*i <= x; i+=2) if (x%i == 0) return false;
}

void getPrimes(int x) {
	for (int i = x/2 + 1; i < x; ++i) {
		if (isPrime(i)) primes.insert(i);
	}
}


bool check(int x) {
	return a[x] == b[x];
}

int lemao = -1;
bool sol(int x, int y, bool f) {
	if (x == n && y == n) return true;
	if (y == n) {lemao = a[x]; return sol(x+1, x, !f);}
	if (x == n) {
		if (!check(y)) return false;
		return sol(y+1, y+1, !f);
	}
	if (x == y) {
		v[x][y] = 1;
		if (f) {
				if (sol(x, y+1, f)) return true;
			}
			else {
				if (sol(x+1, y, f)) return true;
			}
	}
	for (int i = 1; i <= n*n; ++i) {
		if (primes.count(i)) continue;
		if (!f) if (lemao%i != 0) continue;
		if (!s.count(i)) {
			if (!f) lemao /= i;
			s.insert(i);
			v[x][y] = i;
			a[x] *= i;
			b[y] *= i;
			if (f) {
				if (sol(x, y+1, f)) return true;
			}
			else {
				if (sol(x+1, y, f)) return true;
			}
			v[x][y] = -1;
			a[x] /= i;
			b[y] /= i;
			s.erase(i);
			if (!f) lemao *= i;
		}
	}
	return false;
}


int main(){
	cin >> n;
	getPrimes(n*n);
	a = vector<int>(n, 1);
	b = vector<int>(n, 1);
	v = vector<vector<int>>(n, vector<int>(n, -1));
	if (sol(0, 0, true)) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << v[i][j] << ' ';
			}
			cout << endl;
		}
	}
	else cout << "no sol" << endl;

}