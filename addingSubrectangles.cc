#include <bits/stdc++.h>
using namespace std;

vector <int> values(26);

int main() {
    values[0] = 1;
    for (int i = 1; i < 26; ++i) values[i] = values[i-1]+i+1;
    string s;
    cin >> s;
    int n = s.size();
    int m = 1;
    vector < vector <int> > v(1);
    v[0] = vector <int> (n);
    v[0][0] = values[int(s[0] - 'A')];
    for (int i = 1; i < n; ++i) {
        v[0][i] = values[int(s[i] - 'A')] + v[0][i-1];
    }
    char prov;
    int res;
    while (cin >> s) {
        
        vector <int> w(n);
        //w[m] = vector <int> (n);
        for (int j = 0; j < n; ++j) {
            prov = s[j];
            res = values[int(prov - 'A')];
            if (j == 0) w[0] = v[m-1][0] + res;
            else {
                w[j] = res + v[m-1][j] + w[j-1] - v[m-1][j-1];
            }
        }
        v.push_back(w);
        ++m;
    }
    
    for (int i = 0; i < m; ++i) {
        bool firstSpace = true;
        for (int j = 0; j < n; ++j) {
            if (firstSpace) firstSpace = false;
            else cout << ' ';
            cout << v[i][j];
        }
        cout << endl;
    }
}
