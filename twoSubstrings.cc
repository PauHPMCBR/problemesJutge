#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod[2] = {1000000007, 998244353};
const int h = 239;
int n, m;
vector<vector<int>>prefix_hash;
vector<vector<int>>prefix_hash2;
int power[2][10000000];

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
    for (int i = 0; i < 2; ++i) {
        int hash1 = subs(prefix_hash2[r1][i], prefix_hash2[l1-1][i], mod[i]);
        int hash2 = subs(prefix_hash[r2][i], prefix_hash[l2-1][i], mod[i]);
        if (l2 >= l1) {
            if (mult(hash1, power[i][l2-l1], mod[i]) != hash2) {
                return false;
            }
        }
        else {
            if (mult(hash2, power[i][l1-l2], mod[i]) != hash1) {
                return false;
            }
        }
    }
    return true;
}
 
int main() {
    cin >> n >> m;
    string s, s2;
    cin >> s >> s2;
    if (s == s2) {
        cout << s << endl;
        return 0;
    }
    if (m > n) {
        swap(n, m);
        swap(s, s2);
    }
    for (int z = 0; z < 2; ++z) {
        power[z][0] = 1;
        for (int i = 1; i <= n+m+1; ++i) {
            power[z][i] = mult(power[z][i-1], h, mod[z]);
        }
    }
    prefix_hash = gen_hash(s);
    prefix_hash2 = gen_hash(s2);
    int shortest = 1e7;
    bool second = false;
    for (int i = 0; i < m; ++i) {
        if (comp(m-i, m, 1, min(n, i+1))) shortest = n+m-i;
    }
    //cout << shortest << endl;
    for (int i = 0; i < n; ++i) {
        //cout << 1 << ' ' << min(n-i, m) << ' ' <<  i+1 << ' ' << min(n, m+i) << endl;
        //cout << s2.substr(0, min(n-i, m)) << ' ' << s.substr(i, min(n, m+i)-i) << endl;
        if (comp(1, min(n-i, m), i+1, min(n, m+i))) {
            //cout << "yes" << ' ' << max(n, m+i+1) << endl;
            if (max(n, m+i+1) < shortest) {
                second = true;
                shortest = max(n, m+i+1);
            }
        }
    }
    //cout << s << ' ' << s2 << endl;
    //cout << shortest << ' ' << second << endl;
    if (shortest == 1e7) {
        cout << s << s2 << endl;
        return 0;
    }
    if (second) {
        cout << s;
        if (shortest > n) cout << s2.substr(2*n-shortest-1);
        cout << endl;
    }
    else cout << s2 << s.substr(n-(shortest-m-1)) << endl;
}