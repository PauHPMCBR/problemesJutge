#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod[2] = {1000000007, 998244353};
const int h = 239;
int n;
vector<vector<int>>prefix_hash;
vector<vector<int>>rev_prefix_hash;
int power[2][20005];

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
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    for (int m = 0; m < 2; ++m) {
        int hash1 = subs(prefix_hash[r1][m], prefix_hash[l1-1][m], mod[m]);
        int hash2 = subs(prefix_hash[r2][m], prefix_hash[l2-1][m], mod[m]);
        if (mult(hash1, power[m][l2-l1], mod[m]) != hash2) {
            return false;
        }
    }
    return true;
}
 
int main() {
    cin >> n;
    for (int z = 0; z < 2; ++z) {
        power[z][0] = 1;
        for (int i = 1; i < 20005; ++i) {
            power[z][i] = mult(power[z][i-1], h, mod[z]);
        }
    }
    string s;
    cin >> s;
    prefix_hash = gen_hash(s);
    unordered_set<pair<int,pair<int,int>>>used, prov;
    for (int i = 0; i < prefix_hash.size(); ++i) {
        for (int j = i; j < prefix_hash.size(); ++j) {
            int hash1 = subs(prefix_hash[j][0], prefix_hash[i-1][0], mod[0]);
            int hash2 = subs(prefix_hash[j][1], prefix_hash[i-1][1], mod[1]);
            hash1 = mult(hash1, power[0][20004-i], mod[0]);
            hash2 = mult(hash2, power[1][20004-i], mod[1]);
            used.insert({j-i, {hash1, hash2}});
        }
    }
    while (--n) {
        cin >> s;
        prefix_hash = gen_hash(s);
        prov.clear();
        for (int i = 1; i < prefix_hash.size(); ++i) {
            for (int j = i; j < prefix_hash.size(); ++j) {
                int hash1 = subs(prefix_hash[j][0], prefix_hash[i-1][0], mod[0]);
                int hash2 = subs(prefix_hash[j][1], prefix_hash[i-1][1], mod[1]);
                hash1 = mult(hash1, power[0][20004-i], mod[0]);
                hash2 = mult(hash2, power[1][20004-i], mod[1]);
                //cout << "hashes from " << i << " to " << j << ": " << hash1 << ' ' << hash2 << endl;
                if (used.count({j-i, {hash1, hash2}})) {
                    prov.insert({j-i, {hash1, hash2}});
                }
            }
        }
        used = prov;
    }
    if (used.empty()) cout << 0 << endl;
    else {
        int maxLen = 0;
        for (auto i : used) maxLen = max(maxLen, i.first);
        cout << maxLen+1 << endl;
    }
}