#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#define VI vector<int>
#define VVI vector<VI>

int n;
VI available;
VI b;
VI a;
VVI v;
VVI possibleVectors;
int sols = 0;
int initialPut;

void print(VVI& v) {
	for (auto i : v) {
		for (int j : i) {
			cout << j;
		}
		cout << endl;
	}
	cout << endl;
}

void sol(int x, int y, bool f, int toPut) {
	if (x == n && y == n) {
		//print(v);
		++sols;
		return;
	}
	if (y == n) {
		if (a[x] != 0) return;
		return sol(x+1, x, !f, toPut);
	}
	if (x == n) {
		if (b[y] != 0) return;
		return sol(y+1, y+1, !f, toPut);
	}
	for (int i = 0; i <= toPut; ++i) {
		if (i >= available.size()) break;
		if (!available[i]) continue;
		v[x][y] = i;
		a[x] -= i;
		b[y] -= i;
		--available[i];
		if (f && a[x] >= 0 && b[x] >= 0) sol(x, y+1, f, toPut-i);
		else if (a[x] >= 0 && b[x] >= 0) sol(x+1, y, f, toPut-i);
		a[x] += i;
		b[y] += i;
		++available[i];
	}
}

void generateAvailable(int p) {
	initialPut = 0;
	for (int i = 1; i <= n*n; ++i) {
		int factor = 0, copy = i;
		while (copy%p == 0) {++factor; copy/=p;}
		if (factor == available.size()) available.push_back(1);
		else ++available[factor];
		initialPut += factor;
	}
}

vector<int>prov;
void generateVectors(int pos, int rem) {
	if (pos == n) {
		if (rem == 0) {
			possibleVectors.push_back(prov);
		}
		return;
	}
	for (int i = 0; i <= rem; ++i) {
		prov[pos] = i;
		generateVectors(pos+1, rem-i);
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	v = vector<vector<int>>(n, vector<int>(n, -1));
	generateAvailable(2);
	prov = vector<int>(n);
	generateVectors(0, initialPut);
	cout << "available: " << endl;
	for (auto i : available) cout << i << ' ';
		cout << endl;
	for (auto v1 : possibleVectors) {
		cout << "using vector ";
		for (int i = 0; i < n; ++i) cout << v1[i] << ' ';
		cout << endl;
		a = v1;
		b = v1;
		sol(0,0,true,initialPut);
	}
	cout << sols << endl;
}
