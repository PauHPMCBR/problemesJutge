#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matrix;
 	
void transpose(Matrix& m) {
	Matrix m2 = m;
	int n = m.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			m2[i][j] = m[j][i];
		}
	}
	m = m2;
}