#include <iostream>
using namespace std;

int main(){
	double n;
	cin >> n;
	cout << int(n) << ' ';
	if (int(n) == n) cout << int(n) << ' ';
	else cout << int(n)+1 << ' ';
	if (n - int(n) >= 0.5) cout << int(n)+1 << endl;
	else cout << int(n) << endl;
}