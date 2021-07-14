#include <bits/stdc++.h>
using namespace std;
int n;

vector<int>v;
vector<bool>s;

void b(int pos) {
	if (pos == n) {
		cout << '(' << v[0];
		for (int i = 1; i < n; ++i) {
			cout << ',' << v[i];
		}
		cout << ')' << endl;
		return;
	}
	if (pos < 2) {
		for (int i = 1; i <= n; ++i) {
			if (s[i]) continue;
			s[i] = true;
			v[pos] = i;
			b(pos+1);
			s[i] = false;
		}
		return;
	}

	int maxim = min(2*v[pos-1] - v[pos-2], n);
	int minim = max((v[pos-1]+1)/2, 1);
	if (pos == n-1) minim = 1;
	for (int i = minim; i <= maxim; ++i) {
		if (s[i]) continue;
		s[i] = true;
		v[pos] = i;
		b(pos+1);
		s[i] = false;
	}
}

int main(){
	while (cin >> n){
		s = vector<bool>(n, false);
		v = vector<int>(n);
		b(0);
		cout << "----------" << endl;
	}
}
