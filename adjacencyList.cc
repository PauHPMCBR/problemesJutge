#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<set<int>>v(n);
    while (m--) {
    	int a,b;
    	cin >> a >> b;
    	v[a-1].insert(b);
    }
    for (int i = 0; i < n; ++i) {
    	for (auto a : v[i]) cout << a << ' ';
    	cout << endl;
    }
}