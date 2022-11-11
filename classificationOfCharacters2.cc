#include <iostream>
using namespace std;

void print_line(char c, string s, bool b) {
	cout << s << "('" << c << "') = ";
	if (b) cout << "true" << endl;
	else cout << "false" << endl;
}

int main() {
	char c;
	cin >> c;
	bool lower = (c <= 'z' && c >= 'a');
	bool upper = (c <= 'Z' && c >= 'A');
	bool vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
	bool digit = (c <= '9' && c >= '0');
	print_line(c, "letter", lower or upper);
	print_line(c, "vowel", vowel);
	print_line(c, "consonant", not vowel and (lower or upper));
	print_line(c, "uppercase", upper);
	print_line(c, "lowercase", lower);
	print_line(c, "digit", digit);
}