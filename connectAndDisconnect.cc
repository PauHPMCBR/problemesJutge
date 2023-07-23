#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

struct Change {
    int* pos;
    int old;
 
    Change() {}
    Change(int* _pos, int _old) : pos(_pos), old(_old) {}
 
    void undo() {
        *pos = old;
    }
};

Change st[(int)1e6];

struct StackChanges {
    int sz; 

    StackChanges() {
        sz = 0;
    }
 
    void make(int* pos, int val) {
        st[sz] = Change(pos, *pos);// st.push(Change(pos, *pos));
        ++sz;
        *pos = val;
    }
 
    void restore(int checkp) {
        while (sz >= checkp) {
            st[sz].undo();
            --sz;
        }
    }
 
    int checkpoint() {
        return sz+1;
    }
};
 
struct RDSU {
    StackChanges sc;
    vi rank, parent;
    int n, comps;
    int components;
 
    RDSU() {}
    RDSU(int _n) {
        n = _n;
        components = n;
        comps = n;
        rank = vi(n, 1);
        parent = vi(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
 
    int find(int u) { // true O(log n)
        if (parent[u] == u) return u;
        return find(parent[u]);
    }
 
    bool merge(int u, int v) { // true O(log n)
        u = find(u); 
        v = find(v);
        if (u == v) return false; // already merged
        if (rank[u] < rank[v]) swap(u, v); // force rank[u] >= rank[v]
        sc.make(&parent[v], u);
        sc.make(&rank[u], rank[u] + rank[v]);
        sc.make(&comps, comps - 1);
        --components;
        return true;
    }
 
    int checkpoint() {
        return sc.checkpoint();
    }
 
    void restore(int checkpt) {
        sc.restore(checkpt);
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    RDSU dsu(n);

}