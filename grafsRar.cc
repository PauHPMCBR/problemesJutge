#include <bits/stdc++.h>
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;

int main() {
    int n, m;
    while (cin >> n >> m) {
    bool space = true;
    VVI G(n);
    VI veins(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        ++veins[y];
    }
    priority_queue <int, vector<int>, greater<int> > Q;
    for (int i = 0; i < n; ++i) if (veins[i] == 0) Q.push(i);
    while(!Q.empty()) {
        int lel = Q.top(); Q.pop();
        if (space) space = false;
        else cout << ' ';
        cout << lel;
        for (int ics : G[lel]) {
            if (--veins[ics] == 0) Q.push(ics);
        }
    }
    cout << endl;
}
}
