#include <bits/stdc++.h>
using namespace std;

map<char,int>m = {{'C',2616},{'D',2937},{'E',3296},{'F',3492},{'G',3920},{'A',4400},{'B',4939}};
int main(){
	double prov;
	cin >> prov;
	int n = int(prov*10);
	char closest;
	int difference = 1e8;
	bool isGreater = false;
	double mobe1;
	double mobe2;
	for (auto i : m) {
		int pitch = i.second;
		if (pitch < n) {
			while (pitch < 4*n) {
				int diff = abs(n-pitch);
				if (diff < difference) {
					difference = diff;
					closest = i.first;
					isGreater = (n-pitch < 0);
					mobe1 = double(n)/10;
					mobe2 = double(pitch)/10;
				}
				pitch *= 2;
			}
		}
		else {
			while (pitch > n/4) {
				int diff = abs(n-pitch);
				if (diff < difference) {
					difference = diff;
					closest = i.first;
					isGreater = (n-pitch < 0);
					mobe1 = double(n)/10;
					mobe2 = double(pitch)/10;
				}
				pitch /= 2;
			}
		}
	}
	double inputPitch = double(m[closest])/10;
	double correctPitch = double(m[closest])/10;
	double modified = double(difference)/10;

	cout << "Input note: " << closest << " (" << fixed << setprecision(1) << mobe1 << " Hz)" << endl;
	cout << "Closest note: " << closest << " (" << fixed << setprecision(1) << mobe2 << " Hz)" << endl;
	if (modified == 0) cout << "Pitch Perfect!" << endl;
	else {
	if (isGreater) cout << "Increase frequency in " << fixed << setprecision(1) << modified << " Hz" << endl;
	else cout << "Decrease frequency in " << fixed << setprecision(1) << modified << " Hz" << endl;
}
}