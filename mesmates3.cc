#include <bits/stdc++.h>
using namespace std;
int c = 0;
int despl;
int prevDespl;
int prepre;

int a(int n, int k) {
	int pos = 0;
	int counter = 0;
	vector<bool>v(n, false);
	//v[0] = true;
	while (counter != n) {
		++counter;
		for (int i = 0; i < k; ++i) {
			++pos;
			if (pos >= n) {pos -= n; ++c;}
			while (v[pos]) {++pos;++despl; if (pos >= n) {pos -= n; ++c;}}
		}
		v[pos] = true;
	}
	if (pos == 0) return n;
	return pos;
}

int main(){
	int n = 13, k;
	prevDespl = 0;
	prepre = 0;
	for (k = 0; k <= 200; ++k) {
		int res = n-a(n,k)+1;
		if (res == 0 || res == n) cout << k << endl;
	}
}