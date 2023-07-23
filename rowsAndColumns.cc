#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];
	string type;
	int pos;
	while (cin >> type >> pos) {
		if (type == "element") {
			int pos2;
			cin >> pos2;
			cout << "element " << pos << ' ' << pos2 << ": " << v[pos-1][pos2-1] << endl;
		}
		else if (type == "column") {
			cout << "column " << pos << ":";
			for (int i = 0; i < n; ++i) cout << ' ' << v[i][pos-1];
			cout << endl;
		}
		else {
			cout << "row " << pos << ":";
			for (int i = 0; i < m; ++i) cout << ' ' << v[pos-1][i];
			cout << endl;
		}
	}
}