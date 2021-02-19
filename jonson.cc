#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>>cost;
vector<vector<ll>>adj;
int main() {
   ll n, i, j, k, c, t;
   cin >> t;
   while (t--) {
   cin >> n;
   cost = vector<vector<ll>>(n, vector<ll>(n, 2*1e10));
   adj = vector<vector<ll>>(n, vector<ll>(n, 2*1e10));
   for (i = 0; i < n; i++) {
      cin >> c;
      adj[i][(i+1)%n] = cost[i][(i+1)%n] = min(adj[i][(i+1)%n], c);
      adj[(i+1)%n][i] = cost[(i+1)%n][i] = min(adj[(i+1)%n][i], c);
   }
   for (i = 0; i < n; i++) adj[i][i] = 0;
   for (k = 0; k < n; k++)
      for (i = 0; i < n; i++)
         for (j = 0; j < n; j++)
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
   int res = 0;
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
            res += adj[i][j];

      }
      cout << endl;
   }
         cout << res << endl;

}
}