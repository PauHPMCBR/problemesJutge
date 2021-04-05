#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	for (int i = 0; i < 26; ++i) {
		cout << i << ": ";
		for (char c : s) {
			if (c <= 'z' && c >= 'a') cout << char((c+i)-26*((c+i)>'z'));
			else if (c <= 'Z' && c >= 'A') cout << char((c+i)-26*((c+i)>'Z'));
			else cout << c;
		}
		cout << endl;
	}
}