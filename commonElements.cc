#include <iostream>
#include <vector>
using namespace std;

int common_elements(const vector<int>& X, const vector<int>& Y) {
	int ans = 0;
	int x = 0;
	int y = 0;
	while (x < X.size() and y < Y.size()) {
		if (X[x] == Y[y]) ++ans;
		if (X[x] > Y[y]) ++y;
		else ++x;
	}
	return ans;
}