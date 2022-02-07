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
			while (up.size() >= 2 && !isClock(up[up.size()-2], up[up.size()-1], v[i])) up.pop_back();
			up.pb(v[i]);
		}
		if (i == n-1 || isCounter(p1, v[i], p2)) {
			while (down.size() >= 2 && !isCounter(down[down.size()-2], down[down.size()-1], v[i])) down.pop_back();
			down.pb(v[i]);
		}
	}
	cout << up.size()+down.size()-2 << endl;
	for (int i = 0; i < down.size(); ++i) cout << down[i].x << ' ' << down[i].y << endl;
	for (int i = up.size()-2; i > 0; --i) cout << up[i].x << ' ' << up[i].y << endl;
	
}