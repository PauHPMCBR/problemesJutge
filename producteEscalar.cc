#include <bits/stdc++.h>
using namespace std;

double producte_escalar(const vector<double>& u, const vector<double>& v) {
	double res = 0;
	for (int i = 0; i < u.size(); ++i) {
		res += u[i]*v[i];
	}
	return res;
}

int main() {

}