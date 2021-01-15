#include <bits/stdc++.h>
using namespace std;

void escriu_linia(char c, string s, bool b) {
         cout << s << "('" << c << "') = ";
         if (b) cout << "cert" << endl;
         else cout << "fals" << endl;
}

int main() {
	char c;
	cin >> c;
	bool majuscula = (c <= 'Z' && c >= 'A');
	bool minuscula = (c <= 'z' && c >= 'a');
	escriu_linia(c, "lletra", majuscula || minuscula);
	bool vocal = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
	escriu_linia(c, "vocal", vocal);
	escriu_linia(c, "consonant", !vocal && (majuscula || minuscula));
	escriu_linia(c, "majuscula", majuscula);
	escriu_linia(c, "minuscula", minuscula);
	escriu_linia(c, "digit", (c <= '9' && c >= '0'));
}