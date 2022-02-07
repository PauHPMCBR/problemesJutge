#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod[2] = {1000000007, 998244353};
const int h = 239;
int n;
vector<vector<int>>prefix_hash;
vector<vector<int>>rev_prefix_hash;
int power[2][1111111];

int sum(int a, int b, int mod) {
    int res = a + b;
    if (res >= mod) res -= mod;
    return res;
}
 
int subs(int a, int b, int mod) {
    int res = a -  b;
    if (res < 0) res += mod;
    return res;
}
 
int mult(int a, int b, int mod) {
    return (1LL * a * b) % mod;
}

vector<vector<int>> gen_hash(string s) {
    vector<vector<int>>pre_hash(s.size()+1, vector<int>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= s.size(); ++j) {
            pre_hash[j][i] = sum(pre_hash[j-1][i], mult((s[j-1]-'a'+1), power[i][j-1], mod[i]), mod[i]);
        }
    }
    return pre_hash;
}

bool comp(int l1, int r1, int l2, int r2) {
    for (int m = 0; m < 2; ++m) {
        int hash1 = subs(prefix_hash[r1+1][m], prefix_hash[l1][m], mod[m]);
        int hash2 = subs(rev_prefix_hash[r2+1][m], rev_prefix_hash[l2][m], mod[m]);
        if (l1 <= l2) {
            if (mult(hash1, power[m][l2-l1], mod[m]) != hash2) {
                return false;
            }
        }
        else {
            if (hash1 != mult(hash2, power[m][l1-l2], mod[m])) {
                return false;
            }
        }
    }
    return true;
}
 
int main() {
    cin >> n;
    string s, rev_s;
    cin >> s;
    rev_s = s;
    for (int z = 0; z < 2; ++z) {
        power[z][0] = 1;
        for (int i = 1; i <= n; ++i) {
            power[z][i] = mult(power[z][i-1], h, mod[z]);
        }
    }
    reverse(rev_s.begin(),rev_s.end());
    prefix_hash = gen_hash(s);
    rev_prefix_hash = gen_hash(rev_s);
 
    ll sol = 0;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = n-1;
        int ans = 0;
        while (l <= r) {
            int mid = (l+r)/2;
            int l1 = i-mid, r1 = i+mid;
            int l2 = n-r1 -1, r2 = n-l1-1;
            if (0 <= l1 && r1 < n && comp(l1, r1, l2, r2)){
                l = mid+1;
                ans = mid+1;
            }
            else r = mid-1;
        }
        sol += ans;
    }
    cout << sol << endl;
}