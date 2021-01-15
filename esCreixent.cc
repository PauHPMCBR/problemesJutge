#include <iostream>
using namespace std;

bool es_creixent(int n) {
	if (n < 10) return true;
	if (n%10 < (n%100)/10) return false;
	return es_creixent(n/10);
}

int main() {
	int n;
	cin >> n;
	cout << es_creixent(n) << endl;
}