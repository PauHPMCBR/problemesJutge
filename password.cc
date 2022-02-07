#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod[2] = {1000000007, 998244353};
const int h = 239;
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
    string s;
    cin >> s;
    if (s.size() < 3) {
        cout << "Just a legend" << endl;
        return 0;
    }
    for (int z = 0; z < 2; ++z) {
        power[z][0] = 1;
        for (int i = 1; i <= s.size(); ++i) {
            power[z][i] = mult(power[z][i-1], h, mod[z]);
        }
    }
    prefix_hash = gen_hash(s);
    for (int i = s.size()-2; i > 0; --i) {
        if (comp(1, i, s.size()-i+1, s.size())) {
            for (int j = 1; j+i < s.size(); ++j) {
                if (comp(1, i, j+1, j+i)) {
                    cout << s.substr(0, i) << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Just a legend" << endl;
}