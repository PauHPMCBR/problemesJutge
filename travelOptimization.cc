#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(4);
	cout.setf(ios_base::fixed);
	double ax,ay,bx,by,cx,cy,dx,dy,w,t,u;
	while (cin >> ax >> ay >> bx >> by>> cx >> cy >> dx >> dy >> w >> t >> u) {
		double ac = ((ax-cx)*(ax-cx) + (ay-cy)*(ay-cy));
		double ad = ((ax-dx)*(ax-dx) + (ay-dy)*(ay-dy));
		double bc = ((bx-cx)*(bx-cx) + (by-cy)*(by-cy));
		double bd = ((bx-dx)*(bx-dx) + (by-dy)*(by-dy));
		double ab = ((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
		double cd = ((cx-dx)*(cx-dx) + (cy-dy)*(cy-dy));
		int closestA = 0;
		if (ac < ad) closestA = -1;
		if (ac > ad) closestA = 1;
		int closestB = 0;
		if (bc < bd) closestB = -1;
		if (bc > bd) closestB = 1;

		double ansx = sqrt(ab) / w;
		double ansy = sqrt(ab) / w;
		double ans1 = ansx;
		double ans2 = ansy;

		if (closestA == closestB or closestA == 0 or closestB == 0) ans1 = ans2 = sqrt(ab) / w; //caminar
		else {
			double tas = sqrt(min(ac, ad)) / w;
			double tt = sqrt(cd) / t + sqrt(min(bc, bd)) / w;
			double tw = sqrt(max(bc, bd)) / w;
			double threshold = tw - tt;
			if (threshold <= 0) ans1 = sqrt(ab) / w;
			else if (threshold >= u) ans1 = tas + tt + u/2;
			else ans1 = tas + (tt+threshold/2)*(threshold/u) + tw*(u-threshold)/u;

			double tbs = sqrt(min(bc, bd)) / w;
			tt = sqrt(cd) / t + sqrt(min(ac, ad)) / w;
			tw = sqrt(max(ac, ad)) / w;
			threshold = tw - tt;
			if (threshold <= 0) ans2 = sqrt(ab) / w;
			else if (threshold >= u) ans2 = tbs + tt + u/2;
			else ans2 = tbs + (tt+threshold/2)*(threshold/u) + tw*(u-threshold)/u;
		}
		cout << min(ans1, ansx) << ' ' << min(ans2, ansy) << endl;
	}
}