#include <bits/stdc++.h>
using namespace std;
vector<int>parent;
vector<pair<int,int>>v;

int getParent(int x){
    if (x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

void join(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if (x != y) parent[x] = y;
}

int main() {
    int n;
    cin>>n;
    parent = vector<int>(n);
    set<int>s;
    for (int i = 0; i < n; ++i) parent[i]=i;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        if (getParent(a-1) != getParent(b-1)) {
            join(a-1, b-1);
        }
        else {
            v.push_back({a-1,b-1});
        }
    }
    vector<pair<int,int>>bridge;
    int node =- 1;
    for (int i = 0; i < n; ++i) {
        int lel = getParent(i);
        if (!s.count(lel)) {
            s.insert(lel);
            if (node != -1) bridge.push_back({node, i});
            node = i;
        }
    }
    cout << s.size()-1 << endl;
    for (int i = 0; i < bridge.size(); ++i) {
        cout << v[i].first+1 << ' ' << v[i].second+1 << ' ' << bridge[i].first+1 << ' ' <<
        	bridge[i].second+1 << endl;
    }
} 