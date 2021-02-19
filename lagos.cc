#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

ll n;
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

int main(){
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		dist = vector<vector<ll>>(n, vector<ll>(n, 2*1e12));
		ll c;
		for (ll i = 0; i < n; ++i) {
			cin >> c;
			dist[i][(i+1)%n] = min(dist[i][(i+1)%n], c);
			dist[(i+1)%n][i] = min(dist[(i+1)%n][i], c);
		}
		for (ll i = 0; i < n; ++i) {
			dist[i][i] = 0;
		}
		floydWarshall();
		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				//cout << dist[i][j] << ' ';
				res += dist[i][j];
			}
			//cout << endl;
		}
		cout << res << endl;
	}
}
