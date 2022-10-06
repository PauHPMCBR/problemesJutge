#include <iostream>
using namespace std;

int main() {
	//string start = "beginning";
	//string end = "end";
	string s;
	bool start = 0;
	bool end = 0;
	int wordsBetween = 0;
	while (cin >> s and not end) {
		if (s == "beginning") start = true;
		else if (s == "end") end = true;
		else if (start) ++wordsBetween;
	}
	if (start and end) cout << wordsBetween << endl;
	else cout << "wrong sequence" << endl;
}