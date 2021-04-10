#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
using namespace std; 
  
typedef long long ll;
ll n, m;
vector<vector<ll>>dist;

void floydWarshall () { 
    for (ll k = 0; k < n; k++) {  
        for (ll i = 0; i < n; i++) {  
            for (ll j = 0; j < n; j++) {  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }
}
  
int main() {
	ll q;
	cin >> n >> m >> q;
	ll a, b, c;
	dist = vector<vector<ll>>(n, vector<ll>(n, 2*1e12));
	for (ll i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		if (dist[a-1][b-1] > c) {
			dist[a-1][b-1] = c;
			dist[b-1][a-1] = c;
		}
	}
	for (ll i = 0; i < n; ++i) {
		dist[i][i] = 0;
	}
    floydWarshall();
    for (ll i = 0; i < q; ++i) {
    	cin >> a >> b;
    	if (dist[a-1][b-1]== 2*1e12) cout << -1 << endl;
    	else cout << dist[a-1][b-1] << endl;
    }
}  
