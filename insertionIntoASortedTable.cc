#include <iostream>
#include <vector>
#include <algorithm> //xd
using namespace std;

void insert(vector<double>& v) {
	int pos = v.size()-1;
	double x = v[pos];
	while (pos != 0 and v[pos-1] > x) {
		v[pos] = v[pos-1];
		--pos;
	}
	v[pos] = x;
}

int main() {
	vector<double> v = {2, 5, 6};
	insert(v);
	for (auto i : v) cout << i << ' ';
		cout << endl;
}