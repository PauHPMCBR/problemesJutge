#include <iostream>
#include <vector>
using namespace std;

vector<double> difference(const vector<double>& v1, const vector<double>& v2) {
	vector<double>v;
	int j = 0;
	int i = 0;
	while (j != v2.size()) {
		while (i < v1.size() and v1[i] < v2[j]) {
			if (v.size() == 0 or v[v.size()-1] != v1[i]) v.push_back(v1[i]);
			++i;
		}
		while (i < v1.size() and v1[i] == v2[j]) ++i;
		++j;
	}
	while (i < v1.size()) {
		if (v.size() == 0 or v[v.size()-1] != v1[i]) v.push_back(v1[i]);
		++i;
	}
	return v;
}

int main() {
	vector<double>v1 = {1, 2, 2, 5, 5, 7};
	vector<double>v2 = {2, 3, 7};
	vector<double>v = difference(v1, v2);
	for (auto i : v) cout << i << ' ';
		cout << endl;
}