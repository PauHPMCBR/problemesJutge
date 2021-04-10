#include <bits/stdc++.h>
using std::endl;
using std::cin;
using std::cout;
using std::make_pair;
using std::vector;
using std::pair;
using std::queue;

vector < vector <char> > v;
vector < vector <int> > dist;
int n, m, distance, secondDistance;


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

void escriu() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << v[i][j];
        }
        cout << endl;
    }
}

bool isValid(int x, int y, int d) {
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= m) return false;
    if (v[x][y] == 'X') return false;
    if (dist[x][y] != -1 && dist[x][y] <= d) return false;
    dist[x][y] = d;
    return true;
}

void bfs (int x, int y) {
    queue <pair <int, int> > Q;
    Q.push(make_pair(x, y));
    while(!Q.empty()) {
        escriu();
        pair <int, int> prov = Q.front();
        Q.pop();
        x = prov.first;
        y = prov.second;
        int d = dist[x][y];
        if (v[x][y] == 't') if (dist[x][y] >= distance) {
            secondDistance = distance;
            distance = dist[x][y];
        }
        if (isValid(x-1, y, d+1)) Q.push(make_pair(x-1, y));
        if (isValid(x, y-1, d+1)) Q.push(make_pair(x, y-1));
        if (isValid(x+1, y, d+1)) Q.push(make_pair(x+1, y));
        if (isValid(x, y+1, d+1)) Q.push(make_pair(x, y+1));
    }
    return;
}



int main() {
    distance = -1;
    secondDistance = -1;
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
    bfs(x-1, y-1);
    if (secondDistance == -1) cout << "no es pot arribar a dos o mes tresors" << endl;
    else cout << "segona distancia maxima: " << secondDistance << endl;
}
