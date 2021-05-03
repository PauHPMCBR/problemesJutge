#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b;
	cin >> a >> b;
	if (a == b) {
		cout << 1 << endl << a << endl;
		return 0;
	}
	queue<vector<int>>q;
	q.push({a});
	unordered_set<int>visited;
	bool ans = false;
	while (!q.empty() && !ans) {
		vector<int>curr = q.front();
		q.pop();
		int n = curr[curr.size()-1];
		vector<int>lel = {(n%1000)*10 + n/1000};
		lel.push_back(n/10 + 1000*(n%10));
		if (n%10 > 1) lel.push_back(n-1);
		if (n/1000 < 9) lel.push_back(n+1000);
		for (auto i : lel) {
			if (i == b) {
				cout << curr.size()+1 << endl;
				for (auto j : curr) cout << j << endl;
				cout << i << endl;
				ans = true;
				break;
			}
			if (!visited.count(i)) {
				visited.insert(i);
				curr.push_back(i);
				q.push(curr);
				curr.pop_back();
			}
		}
	}
}