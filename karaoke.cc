#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	map<string,int>m;
	vector<string>v;
	cin >> n;
	string song;
	getline(cin, song);
	for (int i = 0; i < n; ++i) {
		getline(cin, song);
		if (m[song] == 0) v.push_back(song);
		m[song] += 1;
	}
	for (auto i : v) {
		cout << m[i] << ' ' << i << endl;
	} 
}