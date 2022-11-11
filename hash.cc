const int mod[2] = {1000000007, 998244353};
const int h = 239;
vector<vector<int>>prefix_hash;
vector<vector<int>>rev_prefix_hash;
int power[2][1111111];

vector<vector<int>> gen_hash(string s) {
    vector<vector<int>>pre_hash(s.size()+1, vector<int>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= s.size(); ++j) {
            pre_hash[j][i] = (pre_hash[j-1][i] + ((s[j-1]-'a'+1) * power[i][j-1] % mod[i])) % mod[i];
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
        int hash1 = (prefix_hash[r1][m] - prefix_hash[l1-1][m] + mod[m]) % mod[m];
        int hash2 = (prefix_hash[r2][m] - prefix_hash[l2-1][m] + mod[m]) % mod[m];
        if (mult(hash1, power[m][l2-l1], mod[m]) != hash2) {
            return false;
        }
    }
    return true;
}