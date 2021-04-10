#include <bits/stdc++.h>
using namespace std;

vector <string> noms;
int n;

void escriu(int pos) {
	if (pos == noms.size()-n-1) return;
	if (noms.size() % 2 == 1) if (pos == noms.size()-n) return;
	cout << noms[pos-n] << endl;

	escriu(pos-1);
}

int main() {
	string prov;	
	//cin >> n;
	while (cin >> prov) {
		noms.push_back(prov);
	}
	n = noms.size()/2;
	if (noms.size() % 2 == 1) ++n;
	escriu(noms.size()-1);
}