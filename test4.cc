#include <iostream>
using namespace std;

int main() {
    int n = 1;
    for (int i = 0; i < 1000000000; ++i)
        for (int j = 0; j < 1000000000; ++j) {if (n == 1) n = 0; if (n == 0) n = 1;}
    cout << "done" << endl;
}
