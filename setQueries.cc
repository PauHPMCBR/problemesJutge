#include <bits/stdc++.h>
using namespace std;

vector<int>st(1e6*4, 0);

void add(int p, int tl, int tr, int i, int v) {
    if (tl == tr) {
        if (v == -1 && st[p] == 0) return;
        st[p] += v;
        return;
    }
    int m = (tl+tr)/2;
    if (i <= m) add(2*p, tl, m, i, v);
    else add(2*p+1, m+1, tr, i, v);
    st[p] = st[2*p] + st[2*p+1];
}

int get(int p, int tl, int tr, int l, int r) {
    if (r < l) return 0;
    if (tl == l && tr == r) return st[p];
    int m = (tl+tr)/2;
    return get(2*p, tl, m, l, min(m,r)) + get(2*p+1, m+1, tr, max(m+1, l), r);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        char c;
        cin >> c;
        if (c == '?') {
            int a,b;
            cin >> a >> b;
            cout << get(1, 0, 1e6, a, b) << endl;
        }
        else {
            int a;
            cin >> a;
            int v = 1;
            if (c == '-') v = -1;
            add(1, 0, 1e6, a, v);
        }
    }
}
