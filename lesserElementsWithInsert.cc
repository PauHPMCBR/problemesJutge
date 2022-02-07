#include <bits/stdc++.h>
using namespace std;
int block = 300;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int q;
    cin >> q;
    multiset<pair<int, pair<int, int>>>m;
	vector<int>group(q/block+3);
    vector<int>sol(q+1, -1);
    vector<bool>v(q+1, 0);
    for (int i = 0; i < q; ++i) {
        int t, x;
        cin >> t >> x;
        if (t == 1) m.insert({x, {i, t}});
        else m.insert({x, {-i, t}});
    }
    for (auto query : m) {
        int i = abs(query.second.first);
        if (query.second.second == 1) {
        	group[i/block] += 1;
        	v[i] = 1;
        }
        else {
            int blockPos = i/block;
            int ans = 0;
            for (int j = 0; j <= blockPos; ++j) {
                int lb = j * block;
                int rb = min(lb+block-1, q-1);
                if (lb >= 0 && rb < i) ans += group[j];
                else {
                    for (int pos = lb; pos < i; ++pos) {
                        ans += v[pos];
                    }
                }
                sol[i] = ans;
            }
        }
    }
    for (auto i : sol) {
        if (i != -1) cout << i << endl;
    }
}