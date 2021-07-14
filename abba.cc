#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n;
vector <int> v;

void escriu() {
	bool abba = false;
	for (int i = 0; i < n-3; ++i) {
		if (v[i] == 0 && v[i+1] == 1 && v[i+2] == 1 && v[i+3] == 0) abba = true;
	}
	if (abba == true) {
		cout << char('A' + v[0]);
		for (int i = 1; i < n; ++i) {
			cout << char('A' + v[i]);
		} cout << endl;
	}	
}


void enqv(int p){
	if (p == n) return escriu();
	v[p] = 0;
	enqv(p + 1);
	v[p] = 1;
	enqv(p + 1);

	
	
}


int main() {
	cin >> n;
	v = vector<int>(n);
	enqv(0);
}

