#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid;

int num (int i, int j, int x, int y) {
	return grid[i+x][j+y]+grid[i][j]-grid[i+x][j]-grid[i][j+y];
}
bool is_a (int i, int j, int x, int y) {
	if (num(i, j, 2*x+y, 3*x+2*y)!=2*x*(3*x+2*y) + 2*x*y)
		return false;
	if (num (i, j, 3*x+2*y, x) != (3*x+2*y)*x)
		return false;
	if (num (i, j+x+y, 3*x+2*y, x) != (3*x+2*y)*x)
		return false;
	if (num (i+x+y, j+x, x, y) != x*y)
		return false; 
	return true;
}
bool is_b (int i, int j, int x, int y) {
	if (num(i, j, 2*x+y, 3*x+2*y)!=2*x*(3*x+2*y) + 3*x*y)
		return false;
	if (num (i, j, 3*x+2*y, x) != (3*x+2*y)*x)
		return false;
	if (num (i, j+x+y, 3*x+2*y, x) != (3*x+2*y)*x)
		return false;
	if (num (i+x+y, j+x, x, y) != x*y)
		return false; 
	if (num (i+2*x+2*y, j+x, x, y) != x*y)
		return false;
	return true;
}
bool is_c (int i, int j, int x, int y) {
	if (num(i, j, 2*x+y, 3*x+2*y)!=x*(2*x+y) + x*(2*y+x))
		return false;
	if (num (i, j, 3*x+2*y, x) != (3*x+2*y)*x)
		return false;
	if (num (i+2*x+2*y, j, x, 2*x+y) != x*(2*x+y))
		return false;
	return true;
}


void fill (int i, int j, int x, int y, vector<vector<bool>>& seen) {
	for (int i2 = 0; i2 < 2*x+y+2; ++i2) {
		for (int j2 = 0; j < 3*x+2*y+2; ++j2)
			seen[i+i2][j+j2] = true;
	}
}

int main() {
	int w, h;
	cin >> w >> h;
	grid = vector<vector<int>>(h+1, vector<int>(w+1));

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			char c;
			cin >> c;
			grid[i+1][j+1] = grid[i+1][j]+grid[i][j+1]-grid[i][j];
			if (c == '#') ++grid[i+1][j+1];
		}
	}
	vector<vector<bool>> seen(h, vector<bool> (w, false));
	int a, b, c;
	a = b = c = 0;
	for (int i = 1; i < h-1; ++i) {
		for (int j = 1; j < w-1; ++j) {
			int l = 3, r = w-j-1, ans = 0;
			while (l <= r) {
				int mid = (r+l)/2;
				if (num(i, j, mid, 1) == mid) {
					ans = mid;
					l = mid+1;
				}
				else r = mid-1;
			}
			int x = 0;
			l = 1, r = h-i-1;
			while (l <= r) {
				int mid = (r+l)/2;
				if (num(i, j, ans, mid) == mid*ans) {
					x = mid;
					l = mid+1;
				}
				else r = mid-1;
			}
			// Buscamos marco
			int y = ans - 2*x;
			if (i+3*x+2*y+1 > h) continue;
			if (x < 1 or y < 1 or ans < 3 or (num(i-1, j-1, 2*x+y+2, 2+3*x+2*y) != num(i, j, 2*x+y, 3*x+2*y)))  
				continue;
			if (is_a(i, j, x, y)) ++a;
			if (is_b(i, j, x, y)) ++b;
			if (is_c(i, j, x, y)) ++c;
		}
	}
	cout << a << ' ' << b << ' ' << c << '\n';
}