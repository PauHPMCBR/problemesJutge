#include <bits/stdc++.h>
using namespace std;

int main(){
	cout.precision(1);
	string a;
	int n;
	cin >> a >> n;
	vector<pair<double,double>>v(n);
	for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
	cin >> a >> n;
	double mobe = -1;
	double d, e;
	pair<double,double>coords;
	for (int i = 0; i < n; ++i) {
		cin >> d >> e;
		for (int i = 0; i < v.size(); ++i) {
			double dist = (d-v[i].first)*(d-v[i].first) + (e-v[i].second)*(e-v[i].second);
			if (mobe == -1 || dist < mobe) {
				mobe = dist;
				coords = {(d+v[i].first)/2, (e+v[i].second)/2};
			}
		}
	}
	cout << fixed << coords.first << ' ' << fixed << coords.second << endl;
}