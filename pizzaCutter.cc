#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
 
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w, n, m;
	cin >> h >> w >> n >> m;
	vector<pair<int,int>> pos_x1, pos_x2, pos_y1, pos_y2;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		pos_x1.push_back({x, i});
		pos_x2.push_back({y, i});
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		pos_y1.push_back({x, i});
		pos_y2.push_back({y, i});
	}
	sort(pos_x1.begin(), pos_x1.end());
	sort(pos_x2.begin(), pos_x2.end());
	sort(pos_y1.begin(), pos_y1.end());
	sort(pos_y2.begin(), pos_y2.end());

	vector<pair<int,int>> difx(n), dify(m);
	for (int i = 0; i < n; ++i) {
		difx[pos_x1[i].second].first = i;
		difx[pos_x2[i].second].second = i;
	}
	for (int i = 0; i < m; ++i) {
		dify[pos_y1[i].second].first = i;
		dify[pos_y2[i].second].second = i;
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += abs(difx[i].first-difx[i].second);
	}
	for (int i = 0; i < m; ++i) {
	    ans += abs(dify[i].first-dify[i].second);
	}
	ans /= 2;
	ans += 1ll*(n+1)*(m+1);
	cout << ans << '\n';
 }