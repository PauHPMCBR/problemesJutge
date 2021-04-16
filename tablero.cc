#include <iostream>
using namespace std;


int main(){
	int n, m;
	cin >> n >> m;
	if (n%2 != 0 || m%2 != 0) cout << "NO" << endl;
	else {
		cout << "SI" << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				bool b = (j+1)%2;
				if (i >= m-1) {
					if (j == 0) b = false;
					else if (j == 1) if (i != n-1) b = true;
				}
				else if (j >= n-1) {
					if (i == 0) b = false;
					else if (i == 1) if (j != m-1) b = true;
				}
				if (b) cout << '#';
				else cout << '.';
			}
			cout << endl;
		}
	}
}