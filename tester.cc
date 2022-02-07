#include <bits/stdc++.h>
using namespace std;

int main(){
	int size;
	cin >> size;
	vector<int>appearances(size*size, 0);
	vector<pair<int,int>>special;
	for (int i = 0; i < size*size; ++i) {
		int prov;
		cin >> prov;
		++appearances[prov-1];
	}
	for (int i = 0; i < size*size; ++i) {
		cout << i+1 << ' ' << appearances[i] << endl;
		if (appearances[i] != 1) special.push_back({i+1,appearances[i]});
	}
	cout << "specials:  ";
	for (auto i : special) cout << i.first << ' ' << i.second << "  ";
	cout << endl;
}