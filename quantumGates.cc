#include <bits/stdc++.h>
using namespace std;

int main(){
	double ar, ai, br, bi;
	cin >> ar >> ai >> br >> bi;
	string s;
	cin >> s;
	for (char c : s) {
		if (c == 'X') {
			swap(ar, br);
			swap(ai, bi);
		}
		else if (c == 'Y') {
			swap(ar, bi);
			swap(ai, br);
			ai *= -1;
			br *= -1;
		}
		else if (c == 'Z') {
			br *= -1;
			bi *= -1;
		}
		else {
			double par = ar, pbr = br, pai = ai, pbi = bi;
			ar = 1/sqrtl(2)*(par+pbr);
			ai = 1/sqrtl(2)*(pai+pbi);
			br = 1/sqrtl(2)*(par-pbr);
			bi = 1/sqrtl(2)*(pai-pbi);
		}
	}
	cout << setprecision(3) << fixed << '(' << ar;
	if (ai >= 0) cout << '+';
	cout << ai << "i)|0> + (" << br;
	if (bi >= 0) cout << '+';
	cout << bi << "i)|1>" << endl;
}