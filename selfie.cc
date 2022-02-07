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
	v.clear();
	for (int i = 0; i < up.size(); ++i) v.pb(up[i]);
    for (int i = down.size()-2; i > 0; --i) v.pb(down[i]);
    if (v.size() < 3) {
    	cout << "0.000000000" << endl;
    	return 0;
    }
    v.pb(v[0]);
	v.pb(v[1]);

    double res = 10;
    for (int i = 0; i < v.size()-2; ++i) {
    	point P1 = v[i+1], P2 = v[i], P3 = v[i+2];
    	double P12 = (P1.x - P2.x)*(P1.x - P2.x) + (P1.y - P2.y)*(P1.y - P2.y);
    	double P13 = (P1.x - P3.x)*(P1.x - P3.x) + (P1.y - P3.y)*(P1.y - P3.y);
    	double P23 = (P2.x - P3.x)*(P2.x - P3.x) + (P2.y - P3.y)*(P2.y - P3.y);
    	res = min(res, acos((P12 + P13 - P23) / (2 * sqrt(P12) * sqrt(P13))));
    }

    cout << setprecision(9) << fixed << res << endl;
}