#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>>v(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
        }
    }
    int sources = 0, sinks = 0;
    for (int i = 0; i < n; ++i) {
        bool hasSources = false;
        for (int j = 0; j < n && !hasSources; ++j)
            if (v[j][i] != 0)
                hasSources = true;
        if (!hasSources) cout << i+1 << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        bool hasSinks = false;
        for (int j = 0; j < n && !hasSinks; ++j)
            if (v[i][j] != 0)
                hasSinks = true;
        if (!hasSinks) cout << i+1 << ' ';
    }
    cout << endl;
}