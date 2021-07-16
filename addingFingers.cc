#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<vector<int>>>>v(5, vector<vector<vector<int>>>(5, vector<vector<int>>(5, vector<int>(5, -1))));
int cnt = 0;
int f(int a, int b, int c, int d) {
    ++cnt;
    cout << "ENTER " << cnt << endl;
    if (v[a][b][c][d] != -1) {
        cout << a << ' ' << b << ' ' << c << ' ' << d << "  " << v[a][b][c][d] << endl;
        cout << "LEAVE " << cnt << endl;
        return v[a][b][c][d];
    }
    
    bool win = false, draw = false;
    v[a][b][c][d] = 0;
    
    if (a != 0 && c != 0) if (f((c+a)%5, d, a, b) == 2) win = true;
    if (a != 0 && d != 0) if (f(c, (d+a)%5, a, b) == 2) win = true;
    if (b != 0 && c != 0) if (f((c+b)%5, d, a, b) == 2) win = true;
    if (b != 0 && d != 0) if (f(c, (d+b)%5, a, b) == 2) win = true;
    if (a != 0 && b != 0) {
        if (f(c, d, (a+b)%5, 0) == 2) win = true;
        if (f(c, d, 0, (a+b)%5) == 2) win = true;
    }
    
    
    if (b == 0) for (int i = 1; i < a; ++i) {
        if (f(c, d, i, a-i) == 2) win = true;
    }
    if (a == 0) for (int i = 1; i < b; ++i) {
        if (f(c, d, i, b-i) == 2) win = true;
    }
    
    if (a != 0 && c != 0) if (f((c+a)%5, d, a, b) == 0) draw = true;
    if (a != 0 && d != 0) if (f(c, (d+a)%5, a, b) == 0) draw = true;
    if (b != 0 && c != 0) if (f((c+b)%5, d, a, b) == 0) draw = true;
    if (b != 0 && d != 0) if (f(c, (d+b)%5, a, b) == 0) draw = true;
    if (a != 0 && b != 0) {
        if (f(c, d, (a+b)%5, 0) == 0) draw = true;
        if (f(c, d, 0, (a+b)%5) == 0) draw = true;
    }
    
    if (b == 0) for (int i = 1; i < a; ++i) {
        if (f(c, d, i, a-i) == 0) draw = true;
    }
    if (a == 0) for (int i = 1; i < b; ++i) {
        if (f(c, d, i, b-i) == 0) draw = true;
    }
    
    if (win) v[a][b][c][d] = 1;
    else if (draw) v[a][b][c][d] = 0;
    else v[a][b][c][d] = 2;
    cout << a << ' ' << b << ' ' << c << ' ' << d << "  " << v[a][b][c][d] << endl;
    cout << "LEAVE " << cnt << endl;
    return v[a][b][c][d];
}

int main() {
    int a,b,c,d;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i == 0 && j == 0){
                v[0][0][0][0] = 2;
                continue;
            }
            v[0][0][i][j] = 2;
            v[i][j][0][0] = 1;
        }
    }
    while (cin >> a >> b >> c >> d) {
        int res = f(a,b,c,d);
        if (res == 0) cout << "DRAW" << endl;
        else if (res == 1) cout << "WIN" << endl;
        else cout << "LOSE" << endl;
    }
}
