#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>v;
bool valid(int x, int y) {
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= n) return false;
    return v[x][y] == 0;
}

int main() {
    while (cin >> n) {
        v = vector<vector<int>>(n, vector<int>(n));
        int x,y,x2,y2;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j) {
                if (s[j] == 'C') {x2=i;y2=j;}
                else if (s[j] == 'P') {x=i;y=j;}
                else if (s[j] == 'B') v[i][j] = -1;
            }
        }
        
        queue<pair<int,int>>q;
        q.push({x,y});
        v[x][y] = 1;
        int dist = -1, d;
        while (!q.empty() && dist == -1) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            d = v[x][y];
            if (x == x2 && y == y2) {dist = d; break;}
            if (valid(x+1,y)) {q.push({x+1,y}); v[x+1][y] = d+1;}
            if (valid(x-1,y)) {q.push({x-1,y}); v[x-1][y] = d+1;}
            if (valid(x,y+1)) {q.push({x,y+1}); v[x][y+1] = d+1;}
            if (valid(x,y-1)) {q.push({x,y-1}); v[x][y-1] = d+1;}
        }
        cout << dist-1 << endl;
    }
}
