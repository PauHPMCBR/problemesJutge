#include <bits/stdc++.h>
using namespace std;
int n;

void b(int pos, vector<int>&v, set<int>&s) {
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
			if (s.count(i)) continue;
			s.insert(i);
			v[pos] = i;
			b(pos+1, v, s);
			s.erase(i);
		}
		return;
	}

	int maxim = min(2*v[pos-1] - v[pos-2], n);
	int minim = max((v[pos-1]+1)/2, 1);
	if (pos == n-1) minim = 1;
	for (int i = minim; i <= maxim; ++i) {
		if (s.count(i)) continue;
		s.insert(i);
		v[pos] = i;
		b(pos+1, v, s);
		s.erase(i);
	}
}

int main(){
	while (cin >> n){
		set<int>s;
		vector<int>v(n);
		b(0, v, s);
		cout << "----------" << endl;
	}
}