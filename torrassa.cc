#include <iostream>
using namespace std;

int main(){
	int h, m, t;
	while (cin >> h >> m >> t) {
		int counter = 0;
		while (t > 0) {
			--t;
			++m;
			if (m == 60) {
				m = 0;
				++h;
				counter += h+4;
				if (h >= 12) counter -= 12;
				if (h == 24) h = 0;
				if (h == 12) counter += 100;
			}
			else if (m % 15 == 0) counter += m%15; 
		}
		cout << counter << endl;
	}
}