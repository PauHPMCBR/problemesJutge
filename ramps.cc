#include <iostream>
#include <vector>
using namespace std;

vector<int> ramps_pos(const vector <int>& V) {
	vector<int>w;
	for (int i = 0; i < V.size()-2; ++i) {
		if (V[i] < V[i+1] and V[i+1] < V[i+2]) w.push_back(i);
		else if (V[i] > V[i+1] and V[i+1] > V[i+2]) w.push_back(i); 
	}
	return w;
}

int pot_conflictive (const vector <int>& B) {
	int cnt = 0;
	for (int i = 0; i < B.size(); ++i) {
		for (int j = i+1; j < B.size(); ++j) {
			if (B[j]-B[i] < 3) ++cnt;
		}
	}
	return cnt;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int>v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		vector<int>ramps = ramps_pos(v);
		cout << "positions with a ramp:";
		for (int i = 0; i < ramps.size(); ++i) cout << ' ' << ramps[i];
		cout << endl;
		cout << "potentially conflictive: " << pot_conflictive(ramps) << endl;
		cout << "---" << endl;
	}
}