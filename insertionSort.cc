#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<double>& v) {
	for (int i = 1; i < v.size(); ++i) {
		double x = v[i];
		int pos = i;
		while (pos != 0 and v[pos-1] > x) {
			v[pos] = v[pos-1];
			--pos;
		} 
		v[pos] = x;
	}
}