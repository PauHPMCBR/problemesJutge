#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<unordered_map<int>>v(n);
	for (int i = 0; i < m; ++i) {
		int a,b,c;
		cin >> a >> b >> c;
		if (!v[a].count(b)) v[a][b] = c;
		else v[a][b] = min(v[a][b], c);
	}
}