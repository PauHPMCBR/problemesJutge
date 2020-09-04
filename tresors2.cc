#include <bits/stdc++.h>
using namespace std;

vector < vector <char> > v;
vector < vector <int> > dist;
int n, m;


/*int dfs(int x, int y) {
    if (v[x][y] == 't') return 0;
    if (v[x][y] == 'X') return 100000;
    int res = 100000;
    v[x][y] = 'X';
    if (x > 0) res = min(dfs(x-1, y), res);
    if (x < n-1) res = min(dfs(x+1, y), res);
    if (y > 0) res = min(dfs(x, y-1), res);
    if (y < m-1) res = min(dfs(x, y+1), res);
    return res+1;
}*/

bool isValid(int x, int y, int d) {
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= m) return false;
    if (v[x][y] == 'X') return false;
    if (dist[x][y] != -1 && dist[x][y] >= d) return false;
    dist[x][y] = d;
    return true;
}

int bfs (int x, int y) {
    int maxDistance = -1;
    queue <pair <int, int> > Q;
    Q.push(make_pair(x, y));
    while(!Q.empty()) {
        pair <int, int> prov = Q.front();
        Q.pop();
        x = prov.first;
        y = prov.second;
        int d = dist[x][y];
        if (v[x][y] == 't') if (dist[x][y] > maxDistance) maxDistance = dist[x][y];
        if (isValid(x-1, y, d+1)) Q.push(make_pair(x-1, y));
        if (isValid(x, y-1, d+1)) Q.push(make_pair(x, y-1));
        if (isValid(x+1, y, d+1)) Q.push(make_pair(x+1, y));
        if (isValid(x, y+1, d+1)) Q.push(make_pair(x, y+1));
    }
    return maxDistance;
}



int main() {
    int x, y;
    cin >> n >> m;
    v = vector < vector <char> >(n);
    dist = vector < vector <int> >(n);
    for (int i = 0; i < n; ++i) {
        v[i] = vector <char>(m);
        dist[i] = vector <int>(m, -1);
        for (int j = 0; j < m; ++j) cin >> v[i][j];
    }
    cin >> x >> y;
    
    dist[x-1][y-1] = 0;
    int res = bfs(x-1, y-1);
    if (res == -1) cout << "no treasure can be reached" << endl;
    else cout << "maximum distance: " << res << endl;
}
