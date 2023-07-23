#include <iostream>
#include <vector>
using namespace std;

struct Point { 
	double x, y;
};

bool barycenter(const vector<Point>& v, Point& b) {
	int n = v.size();
	double x = 0, y = 0;
	for (int i = 0; i < n; ++i) {
		x += v[i].x;
		y += v[i].y;
	}
	b.x = x/n;
	b.y = y/n;
	for (int i = 0; i < n; ++i) if (v[i].x == b.x and v[i].y == b.y) return true;
	return false;
}

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	int n;
	while (cin >> n) {
		vector<Point>v(n);
		bool hasDifferent = false;
		for (int i = 0; i < n; ++i) {
			cin >> v[i].x >> v[i].y;
			if (v[i].x != v[0].x or v[i].y != v[0].y) hasDifferent = true;
		}
		Point b;
		bool hasBaricenter = barycenter(v, b);

		cout << "barycenter: (" << b.x << "," << b.y << ")" << endl;
		if (!hasDifferent) cout << "property 1 does not hold" << endl;
		else if (b.x != b.y) cout << "property 2 does not hold" << endl;
		else if (hasBaricenter) cout << "property 3 does not hold" << endl;
		else cout << "normalized vector" << endl;
	}
}