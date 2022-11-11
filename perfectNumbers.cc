#include <iostream>
#include <cmath>
using namespace std;

bool is_perfect(int n) {
	if ((n==0) || (n==1)) return false;
	int h = 1;
  	double j = sqrt(n);
	for (int i = 2; i <= j; ++i) {
    	if (n%i == 0) {
			h += i;
			h += (n/i);
    	}
	}
	return n == h;
}