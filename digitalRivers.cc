#include <iostream>
#include <vector>
using namespace std;

int getNext(int n) {
	int sum = 0;
	int res = n;
	while (n > 0) {
		sum += n%10;
		n /= 10;
	}
	return res+sum;
}

int encounter_of_rivers(int n) {
	int r1 = 1, r3 = 3, r9 = 9;
	while (true) {
		while (r1 < n) r1 = getNext(r1);
		while (r3 < n) r3 = getNext(r3);
		while (r9 < n) r9 = getNext(r9);
		if (r1 == n or r3 == n or r9 == n) return n;
		n = getNext(n);
	}
}