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
     

double pib(const Paisos& p, char c, double d) {
	double s = 0;
	for (Pais p1 : p) {
		if (p1.nom[0] != c) continue;
		for (Provincia prov : p1.provs) {
			if (double(prov.habitants) / double(prov.area) > d) s += prov.pib;
		}
	}
	return s;
}

int main() {

}