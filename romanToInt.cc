#include <bits/stdc++.h>
using namespace std;

int romanToInt(string ss) {
	int nn = int(ss.length());
	if (0 == nn) {
		return 0;
	}
	int result = 0;
	for (int i = 0; i < nn; i++) {
		switch (ss[i]) {
			case 'I':
				result += 1;
				break;
			case 'V':
				result += 5;
				break;
			case 'X':
				result += 10;
				break;
			case 'L':
				result += 50;
				break;
			case 'C':
				result += 100;
				break;
			case 'D':
				result += 500;
				break;
			case 'M':
				result += 1000;
				break;
		}
	}
	for (int i = 1; i < nn; i++) {
		if ((ss[i] == 'V' || ss[i] == 'X') && ss[i - 1] == 'I') result -= 2;
		if ((ss[i] == 'L' || ss[i] == 'C') && ss[i - 1] == 'X') result -= 20;
		if ((ss[i] == 'D' || ss[i] == 'M') && ss[i - 1] == 'C') result -= 200;
	}
	return result;
}

string intToRoman(int nn) {
	string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	string result = "";
	for (auto int i = 0; i < 13; ++i) {
		while(nn - values[i] >= 0) {
			result += str_romans[i];
			nn -= values[i];
		}
	}
	return result;
}
