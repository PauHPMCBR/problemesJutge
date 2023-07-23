#include <iostream>
#include <vector>
using namespace std;

const int OFFSET = 1000000000;
const int INTERVAL = 1000;

int main() {
	int n;
	cin >> n;
	vector<int>v(INTERVAL+1);
	for (int i = 0; i < n; ++i) {
		int prov;
		cin >> prov;
		++v[prov-OFFSET];
	}
	for (int i = 0; i <= INTERVAL; ++i) {
		if (v[i] != 0) {
			cout << i+OFFSET << " : " << v[i] << endl;
		}
	}
}