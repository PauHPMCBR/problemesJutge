#include <bits/stdc++.h>
using namespace std;
int n;
vector<bool>v;
vector<int> pasarela;
vector<bool>puente;

bool f(int pos, int dir, int pos2) { //1 = right, -1 = left
	if (pos2 = n) {
		return pos == 0;
	}
	if (dir == 1) {
		if (pos > 0 && puente[pos-1] == !v[pos2]) if (f(pos-1, -1, pos2+1)) {
			...
			return true;
		}
		puente.push_back(v[pos2]);
		if (f(pos+1, 1, pos2+1)) {
			pasarela.push_back(v[pos2]);
			...
		}
		puente.pop_back();
	}
	else {
		if (pos > 0 && puente[pos-1] == v[pos2]) if (f(pos-1, -1, pos2+1)) {
			...
			return true;
		}
		
	}
	return false;
}

int main(){
	cin >> n;
	v = vector<bool>(n);
	char prov;
	for (int i = 0; i < n; ++i) {
		cin >> prov;
		v[i] = (prov == 'D');
	}
	if (f(0,1,0)) {

	}
	else cout << "NO" << endl;
}