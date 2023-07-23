#include <bits/stdc++.h>
using namespace std;

double norm(double a) {
	return max(0.0, min(a, 100.0));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(2);
	int p;
	cin >> p;
	int total = 0;
	vector<double>v(p);
	vector<string>names(p);
	for (int i = 0; i < p; ++i) {
		cin >> names[i] >> v[i];
		total += v[i];
	}
	double minDiff = 100 - total - 0.49 * (double(p-1));
	double maxDiff = 100 - total + 0.5  * (double(p-1));
	if (minDiff < -0.5) minDiff = -0.5;
	if (maxDiff > 0.49) maxDiff = 0.49;
	bool possible = true;
	if (minDiff > 0.49) possible = false;
	if (maxDiff < -0.5) possible = false;
	if (minDiff > maxDiff) possible = false;

	if (!possible) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		for (int i = 0; i < p; ++i) {
			cout << names[i] << ' ' << norm(v[i] + minDiff) << ' ' << norm(v[i] + maxDiff) << endl;
		}
	}
}