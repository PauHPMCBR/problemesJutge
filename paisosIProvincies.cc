#include <bits/stdc++.h>
using namespace std;

struct Provincia {
	string nom;
	string capital;
	int habitants;
	int area;
	double pib;
};

struct Pais {
	string nom;
	string capital;
	vector<Provincia> provs;
};
typedef vector<Pais> Paisos;
     

int habitants(const Paisos& p, double x) {
	int s = 0;
	for (Pais p1 : p) {
		int lel = 0;
		int sum = 0;
		for (Provincia prov : p1.provs) {
			if (prov.pib <= x) ++lel;
			sum += prov.habitants;
		}
		if (lel > 1) s += sum;
	}
	return s;
}

int main() {

}