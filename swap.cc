#include <iostream>
using namespace std;

void swap2(int& a, int& b) {
	a = a+b;
	b = a-b;
	a = a-b;
}