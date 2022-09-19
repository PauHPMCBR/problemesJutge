#include <iostream>
using namespace std;

int main(){
	char c;
	cin >> c;
	if (c <= 'z' && c >= 'a') cout << char(c - int('a') + int('A')) << endl;
	else cout << char(c - int('A') + int('a')) << endl;
}