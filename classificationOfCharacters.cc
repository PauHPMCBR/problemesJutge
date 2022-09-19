#include <bits/stdc++.h>
using namespace std;

int main(){
	char c;
	cin >> c;
	if (c <= 'z' && c >= 'a') cout << "lowercase" << endl;
	else cout << "uppercase" << endl;
	bool isVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
	if (isVowel) cout << "vowel" << endl;
	else cout << "consonant" << endl;
}