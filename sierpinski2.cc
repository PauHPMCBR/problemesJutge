#include <bits/stdc++.h>
using namespace std;

vector<vector<bool> >v;

void s(int n, int x, int y, int maxx, int maxy){
    if(n==0) return;
    if(n==1) {
        v[x][y] = true;
        v[x][y+1] = true;
        v[x+1][y] = true;
    }
    else {
        s(n-1, x, y, maxx-(maxx-x)/2, maxy-(maxy-y)/2);
        s(n-1, maxx-(maxx-x)/2, y, maxx, maxy-(maxy-y)/2);
        s(n-1, x, maxy-(maxy-y)/2, maxx-(maxx-x)/2, maxy);
    }
}

int main(){
    int n;
    cin>>n;
    int m = (1<<n);
    v=vector<vector<bool> >((1<<n),vector<bool>((1<<n),false));
    s(n, 0, 0, m-1, m-1);
    for (int i = 0; i < m; ++i) {
        for (int j = m-1; j >= 0; --j) {
        if (v[i][j]) cout << '#';
        else cout << ' ';
    }
        cout << endl;
    }
}

