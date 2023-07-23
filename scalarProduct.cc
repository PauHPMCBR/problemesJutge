#include <iostream>
#include <vector>
using namespace std;

double scalar_product(const vector<double>& u, const vector<double>& v) {
	int n = u.size();
	double ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += u[i] * v[i];
	}
	return ans;
}