#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>prov(n);
	for (int i = 0; i < n; ++i) cin >> prov[i];
	vector<int>v(n);
	size_t lel(0);
	generate(begin(v), end(v), [&]{ return lel++; });
	sort(begin(v), end(v), [&](int i1, int i2) {return prov[i1] < prov[i2];});
	
	int maxim = 0;
	int i = 0, j = n-1;
	set<int>used;
	
}