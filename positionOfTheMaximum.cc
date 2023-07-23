#include <iostream>
#include <vector>
using namespace std;

int position_maximum(const vector<double>& v, int m) {
	int pos = 0;
	for (int i = 1; i <= m; ++i) {
		if (v[i] > v[pos]) pos = i;
	}
	return pos;
}