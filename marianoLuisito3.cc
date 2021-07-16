#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1;
    vector<int>v1(n);
    vector<int>v2(n);
    for (int i = 0; i < n; ++i) {
        if (s1[i] == 'M') v1[i] = 0;
        else v1[i] = -1;
    }
    bool vect1 = 1;
    for (int k = 1; k < m; ++k) {
        cin >> s2;
        for (int i = 0; i < n; ++i) {
            if (s2[i] == '*') v2[i] = -1;
            else {
                int a = (s2[i] == 'T')*3;
                int minim = -1;
                if (i > 0) if (v1[i-1] != -1 && (v1[i-1]+1+a < minim || minim == -1)) minim = v1[i-1]+1+a;
                if (v1[i] != -1 && (v1[i]+a < minim || minim == -1)) minim = v1[i]+a;
                if (i < n-1) if (v1[i+1] != -1 && (v1[i+1]+1+a < minim || minim == -1)) minim = v1[i+1]+1+a;
                v2[i] = minim;
            }
        }
        v1 = v2;
        s1 = s2;
    }
    int minVal = -1;
    for (int i = 0; i < n; ++i) {
        if (v1[i] != -1 && (v1[i] < minVal || minVal == -1)) minVal = v1[i];
    }
    if (minVal == -1) cout << "IMPOSSIBLE" << endl;
    else cout << minVal << endl;
}
