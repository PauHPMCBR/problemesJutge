#include <bits/stdc++.h>
using namespace std;

//returns the fattened x
int fatten(int x) {
	if (x < 10) return x; //base case
	int digit = x%10; //get the 1st possible digit
	x = fatten(x/10); //recurive func
	int digit2 = x%10; //get the 2nd possible digit
	x *= 10;
	if (digit > digit2) x += digit;
	else x += digit2;
	return x;
}

int main() {
	int x;
	cin >> x;
	cout << fatten(x) << endl;
}