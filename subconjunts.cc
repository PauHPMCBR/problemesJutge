#include <bits/stdc++.h>
using namespace std;

vector <int> p;
vector <string> v;
int m, n;

void escriu() {
    cout << '{' << v[p[0]];
    for (int i = 1; i < m; ++i) cout << ',' << v[p[i]];
    cout << '}' << endl;
}

void setValue(int pos, int startFrom) {
    if (pos == m) return escriu();
    for (int i = startFrom; i < n-(m-pos)+1; ++i) {
        p[pos] = i;
        setValue(pos+1, i+1);
    }
}

int main() {
    cin >> m >> n;
    if (m == 0) {cout << "{}" << endl; return 1;}
    p = vector <int> (m, -1);
    v = vector <string>(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    setValue(0, 0);
}
