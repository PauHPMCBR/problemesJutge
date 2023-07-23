#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	map<string,string>m;
	string ant = "-";
	for (int i = 0; i < n; ++i) {
		string prov;
		cin >> prov;
		m[prov] = ant;
		ant = prov;
	}
	cin >> n;
	while (n--) {
		string s1, s2;
		cin >> s1 >> s2;
		string ant1 = m[s1];
		string ant2 = m[s2];
		
	}
	for (string i : v) cout << i << endl;
}