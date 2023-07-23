#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

void min_max(const Matrix& mat, int& minimum, int& maximum) {
	minimum = mat[0][0];
	maximum = mat[0][0];
	for (int i = 0; i < mat.size(); ++i) {
		for (int j = 0; j < mat[0].size(); ++j) {
			if (mat[i][j] < minimum) minimum = mat[i][j];
			if (mat[i][j] > maximum) maximum = mat[i][j];
		}
	}
}

int main() {
	int n, m, cnt = 0;
	int maxDif = 0, pos = 0;
	while (cin >> n >> m) {
		++cnt;
		Matrix mat(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> mat[i][j];
		int minimum, maximum;
		min_max(mat, minimum, maximum);
		if (maxDif < maximum - minimum) {
			maxDif = maximum - minimum;
			pos = cnt;
		}
	}
	if (pos == 0) pos = 1;
	cout << "la diferencia maxima es " << maxDif << endl;
	cout << "la primera matriu amb aquesta diferencia es la " << pos << endl;
}