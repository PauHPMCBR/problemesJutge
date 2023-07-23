#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int LENGTH_ALPHABET = 'z' - 'a' + 1;

char most_frequent_letter(const string& s) {
	vector<int>freqs(LENGTH_ALPHABET);
	char letter;
	int maxFreq = 0;
	for (int i = 0; i < s.size(); ++i) {
		++freqs[s[i]-'a'];
		if ((freqs[s[i]-'a'] > maxFreq) or ((freqs[s[i]-'a'] == maxFreq) and (s[i] < letter))) {
			maxFreq = freqs[s[i]-'a'];
			letter = s[i];
		}
	}
	return letter;
}

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);
	int n;
	cin >> n;
	vector<string>v(n);
	int lenSum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		lenSum += v[i].size();
	}
	double average = double(lenSum)/n;
	cout << average << endl;
	for (int i = 0; i < n; ++i) {
		if (v[i].size() >= average) {
			cout << v[i] << ": " << most_frequent_letter(v[i]) << endl;
		}
	}
}