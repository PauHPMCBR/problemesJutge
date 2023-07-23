#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define point pair<ll,ll>
#define x first
#define y second
#define pb push_back
vector<point>v;


bool isClock(point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0;
}

bool isCounter(point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) >= 0;
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
			while (up.size() >= 2 && !isClock(up[up.size()-2], up[up.size()-1], v[i])) up.pop_back();
			up.pb(v[i]);
		}
		if (i == n-1 || isCounter(p1, v[i], p2)) {
			while (down.size() >= 2 && !isCounter(down[down.size()-2], down[down.size()-1], v[i])) down.pop_back();
			down.pb(v[i]);
		}
	}

	ll sol = 0;

	if (up.size() + down.size() - 2 == 2) {
		if (abs(down[0].x - down[1].x) == abs(down[0].y - down[1].y)) {
			cout << abs(down[0].x - down[1].x)*2 + 5 << endl;
			return 0;
		}
	}
	
	for (int i = 0; i < down.size(); ++i) {
		if (i != 0) {
			sol += max(abs(down[i].x - down[i-1].x), abs(down[i].y - down[i-1].y));
		}
	}

	sol += max(abs(up[up.size()-1].x - down[down.size()-1].x), abs(up[up.size()-1].y - down[down.size()-1].y));


	for (int i = up.size()-1; i > 0; --i) {
		sol += max(abs(up[i].x - up[i-1].x), abs(up[i].y - up[i-1].y));
	}

	if (n == 1) cout << 4 << endl;
	else cout << sol+4 << endl;
}
