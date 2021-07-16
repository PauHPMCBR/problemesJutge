#include <iostream>
using namespace std;

void count_and_add(int& num, int& sum) {
    int n;
    num = 0, sum = 0;
    while (cin >> n) {
        ++num;
        sum += n;
    }
}
