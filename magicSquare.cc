#include <iostream>
#include <vector>
using namespace std;

bool magic_square(const vector< vector<int> >& t) {
	int n = t.size();
	
	vector<int>nums(n*n+1);

	vector<int>rows(n);
	vector<int>cols(n);
	int diag1 = 0;
	int diag2 = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x = t[i][j];
			if (x > n*n or x < 1) return false;
			++nums[x];
			if (nums[x] != 1) return false;

			rows[i] += x;
			cols[j] += x;

			if (i == j) diag1 += x;
			if (i == n-j-1) diag2 += x;
		}
	}

	if (diag1 != diag2) return false;
	for (int i = 0; i < n; ++i) {
		if (rows[i] != diag1) return false;
		if (cols[i] != diag1) return false;
	}

	return true;
}