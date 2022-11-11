#include <iostream>
#include <cmath>
using namespace std;

int sum_min_max(int x, int y, int z) {
	return (min(x,min(y,z)) + max(x,max(y,z)));
}