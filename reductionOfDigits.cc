#include <iostream>
using namespace std;

int sum_of_digits(int n) {
	if (n < 10) return n;
	return sum_of_digits(n/10)+(n%10);
}

int reduction_of_digits(int n) {
	if (n < 10) return n;
	return reduction_of_digits(sum_of_digits(n));
}