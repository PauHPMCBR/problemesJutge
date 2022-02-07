#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>v(n);
	vector<int> dp(n, 1);
	vector<int> parent(n, -1);
	for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[j] < v[i] && dp[i] < dp[j]+1) {
                dp[i] = dp[j]+1;
                parent[i] = j;
            }
        }
    }

    int ans = dp[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            pos = i;
        }
    }
    cout << ans << endl;
    vector<int> sol;
    while (pos != -1) {
        sol.push_back(pos);
        pos = parent[pos];
    }
    for (int i = 0; i < ans; ++i) cout << sol[ans-i-1]+1 << ' ';
    cout << endl;
}