#include <bits/stdc++.h>
using namespace std;

int getNum(string s) {
	if (s == "pilar") return 1;
	if (s == "dos" || s == "torre") return 2;
	if (s == "tres") return 3;
	if (s == "quatre") return 4;
	if (s == "cinc") return 5;
	if (s == "sis") return 6;
	if (s == "set") return 7;
	if (s == "vuit") return 8;
	if (s == "nou") return 9;
	return 10;
}

int main(){
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	int w = getNum(s1);
	int h = getNum(s3);
	bool folre = false, manilles = false;
	while (cin >> s1) {
		cin >> s1;
		if (s1 == "folre") folre = true;
		else if (s1 == "manilles") manilles = true;
		else if (s1 == "l'agulla") ++w;
	}
	int spaces = 1+folre+manilles;
	if (w == 1) {
		for (int i = 0; i < h-spaces; ++i) {
			cout << string(spaces, ' ') << '#' << endl;
		}
		for (int i = 1; i <= spaces; ++i) {
			cout << string(spaces-i, ' ') << string(2*i+1, '#') << endl;
		}
	}
	else {
		cout << string(spaces + (w-1)/2, ' ') << '#' << endl;
		cout << string(spaces + (w-1)/2, ' ') << '#' << endl;
		if (w%2) cout << string(spaces-1 + (w-1)/2, ' ') << "# #" << endl;
		else cout << string(spaces + (w-1)/2, ' ') << "##" << endl;
		for (int i = 0; i < h-spaces-3; ++i) {
			cout << string(spaces, ' ') << string(w, '#') << endl;
		}
		for (int i = 1; i <= spaces; ++i) {
			cout << string(spaces-i, ' ') << string(w+2*i, '#') << endl;
		}
	}
}