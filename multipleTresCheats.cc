#include <iostream>
using namespace std;

bool es_multiple_3(int n) {
	return n%3 == 0;
}

int main() {
	int n;
	cin >> n;
	cout << es_multiple_3(n) << endl;
}