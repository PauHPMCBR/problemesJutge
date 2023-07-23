#include <iostream>
#include <vector>
using namespace std;

vector<int> concatenation(const vector<int>& v1, const vector<int>& v2) {
	vector<int>v;
	for (int i = 0; i < v1.size(); ++i) v.push_back(v1[i]);
	for (int i = 0; i < v2.size(); ++i) v.push_back(v2[i]);
	return v;
}