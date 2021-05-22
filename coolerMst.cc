#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first
typedef long long ll;
ll MOD = 1e9+7;
vector<pair<ll, pair<ll, ll>>>v;
vector<ll>parent;

ll find(ll x){
  if (x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}

void join(ll a, ll b){
  a = find(a);
  b = find(b);
  if (a != b) {
    parent[a] = b;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n, m;
  cin >> n >> m;
  parent = vector<ll>(n);
  for (ll i=0; i<n; ++i) parent[i]=i;
  while (m--) {
    ll a,b,c;
    cin >> a >> b >> c;
    v.push_back({c, {a-1, b-1}});
  }
  sort(v.begin(), v.end());
  ll sol = 1;
  for (ll i = 0; i < v.size(); ++i) {
    if (find(v[i].s.f) != find(v[i].s.s)) {
      join(v[i].s.f, v[i].s.s);
      sol *= v[i].f;
      sol %= MOD;
    }
  }
  cout << sol << endl;
} 