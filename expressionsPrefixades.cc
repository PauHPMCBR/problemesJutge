#include <bits/stdc++.h>
using namespace std;

vector <char> c;
int it = 0;

int calculate() {
	if (c[it] == '+') {
		++it;
		int res1 = calculate();
		++it;
		return res1 + calculate();
	}
	if (c[it] == '-') {
		++it;
		int res1 = calculate();
		++it;
		return res1 - calculate();
	}
	if (c[it] == '*') {
		++it;
		int res1 = calculate();
		++it;
		return res1 * calculate();
	}
	int res = int(c[it] - '0');
	return res;

}

int main() {
	char prov;
	while (cin >> prov) c.push_back(prov);
	cout << calculate() << endl;
}