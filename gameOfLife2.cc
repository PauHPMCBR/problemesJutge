#include <bits/stdc++.h>
using namespace std;

vector<string> dia = {"XXX", "X..", ".X."};
vector<string> stra = {".X..X", "X....", "X...X", "XXXX."};

int main(){
	string s;
    bool first = true;
	while (cin >> s) {
        if (first) first = false;
        else cout << endl;
		if (s == "N") {
			for (int i = 0; i < 5; ++i) {
				for (int j = 3; j >= 0; --j)
					cout << stra[j][i];
				cout << endl;
			}
		}
		else if (s == "S") {
			for (int i = 4; i >= 0; --i) {
				for (int j = 0; j < 4; ++j)
					cout << stra[j][i];
				cout << endl;
			}
		}
		else if (s == "E") {
			for (int i = 0; i < 4; ++i) {
				for (int j = 4; j >= 0; --j)
					cout << stra[i][j];
				cout << endl;
			}
		}
		else if (s == "W") {
			for (int i = 3; i >= 0; --i) {
				for (int j = 0; j < 5; ++j)
					cout << stra[i][j];
				cout << endl;
			}
		}
		else if (s == "NW") {
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j)
					cout << dia[i][j];
				cout << endl;
			}
		}
		else if (s == "NE") {
			for (int i = 0; i < 3; ++i) {
				for (int j = 2; j >= 0; --j)
					cout << dia[i][j];
				cout << endl;
			}
		}
		else if (s == "SW") {
			for (int i = 2; i >= 0; --i) {
				for (int j = 0; j < 3; ++j)
					cout << dia[i][j];
				cout << endl;
			}
		}
		else {
			for (int i = 2; i >= 0; --i) {
				for (int j = 2; j >= 0; --j)
					cout << dia[i][j];
				cout << endl;
			}
		}
        
	}
}

