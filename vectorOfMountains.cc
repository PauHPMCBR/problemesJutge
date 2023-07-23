#include <iostream>
#include <vector>
using namespace std;

// PRE: |v| ≥ 3
// POST: returns a vector containing the height of all the peaks in v (in the same order)
vector<int> obtain_peaks(const vector<int>& v) {
	vector<int>w;
	for (int i = 1; i < v.size()-1; ++i) {
		if (v[i] > v[i-1] and v[i] > v[i+1]) w.push_back(v[i]);
	}
	return w;
}

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	vector<int>w = obtain_peaks(v);
	int lastPeak = 0;
	if (w.size() != 0) lastPeak = w[w.size()-1];
	cout << w.size() << ":";
	for (int i = 0; i < w.size(); ++i) cout << ' ' << w[i];
	cout << endl;
	bool found = false;
	if (w.size() != 0) {
		for (int i = 0; i < w.size()-1; ++i) {
			if (w[i] > lastPeak) {
				if (not found) found = true;
				else cout << ' ';
					cout << w[i];
			}
		}
	}
	if (not found) cout << '-';
	cout << endl;
}