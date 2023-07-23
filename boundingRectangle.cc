#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Row;
typedef vector<Row> Rectangle;

void minimal_dimensions(char c, const Rectangle& r, int& rows, int& cols) {
	int n = r.size();
	int m = r[0].size();
	int minR = n;
	int maxR = -1;
	int minC = m;
	int maxC = -1;
	bool found = false;
	for (int i = 0; i < n and !found; ++i) {
		for (int j = 0; j < m and !found; ++j) {
			if (r[i][j] == c) {
				minR = i;
				found = true;
			}
		}
	}
	found = false;
	for (int j = 0; j < m and !found; ++j) {
		for (int i = 0; i < n and !found; ++i) {
			if (r[i][j] == c) {
				minC = j;
				found = true;
			}
		}
	}
	found = false;
	for (int i = n-1; i >= 0 and !found; --i) {
		for (int j = 0; j < m and !found; ++j) {
			if (r[i][j] == c) {
				maxR = i;
				found = true;
			}
		}
	}
	found = false;
	for (int j = m-1; j >= 0 and !found; --j) {
		for (int i = 0; i < n and !found; ++i) {
			if (r[i][j] == c) {
				maxC = j;
				found = true;
			}
		}
	}
	rows = maxR - minR +1;
	cols = maxC - minC +1;
}

int main() {
	int n = 5;
	Rectangle v(5, Row(5));
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> v[i][j];
		char c = 'c';
	int rows, cols;
	minimal_dimensions(c, v, rows, cols);
	cout << rows << ' ' << cols << endl;
}