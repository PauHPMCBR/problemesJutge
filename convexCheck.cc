#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define point pair<ll,ll>
#define x first
#define y second
#define pb push_back
vector<point>v;


bool isClock(point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool isCounter(point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	v = vector<point>(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].x >> v[i].y;
	}
	sort(v.begin(), v.end());
	point p1 = v[0], p2 = v[n-1];
	vector<point> up, down;
	up.pb(p1);
	down.pb(p1);

	for (int i = 1; i < n; ++i) {
		if (i == n-1 || isClock(p1, v[i], p2)) {
			if (up.size() >= 2 && !isClock(up[up.size()-2], up[up.size()-1], v[i])) {
				cout << "NO" << endl;
				return 0;
			}
			up.pb(v[i]);
		}
		if (i == n-1 || isCounter(p1, v[i], p2)) {
			if (down.size() >= 2 && !isCounter(down[down.size()-2], down[down.size()-1], v[i])) {
				cout << "NO" << endl;
				return 0;
			}
			down.pb(v[i]);
		}
		if (!isClock(p1, v[i], p2) && !isCounter(p1, v[i], p2) && i != n-1) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}