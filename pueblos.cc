#include <bits/stdc++.h>
using namespace std;

int t, n, m, c, w;
vector<bool>visited;
vector<int>v;
vector<vector<pair<int,int>>>nodes;
void dfs(int x) {
    visited[x] = true;
    ++c;
    for (auto a : nodes[x]) {
        if (a.second > w) continue;
        if (!visited[a.first]) dfs(a.first);
    }
}

int main(){
    cin >> t;
    while (t--) {
        cin >> n >> m;
        nodes = vector<vector<pair<int,int>>>(n);
        v = vector<int>(m);
        int a, b, h;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> h;
            nodes[a].push_back({b, h});
            nodes[b].push_back({a, h});
            v[i] = h;
        }
        sort(v.begin(), v.end());
        int esq = 0, dre = m-1;
        int mig = 0;
        
        c = 0;
        while (esq != dre || c != n) {
            
            mig = (esq+dre)/2;
            w = v[mig];
            visited = vector<bool>(n, false);
            c = 0;
            dfs(0);
            if (c == n) dre = mig;
            else esq = mig+1;
        }
        cout << v[mig] << endl;
    }
}