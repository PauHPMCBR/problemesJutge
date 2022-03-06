#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long double total = 0, win = 0, ties = 0, lose = 0;

void addCase(ll s, ll c, ll cardsUsed, long double frac){
	if (c > 21) {win += frac; return;}
	if (cardsUsed == 2 && c == 21) {lose += frac; return;}
	if (c > s) {lose += frac; return;}
	if (c == s) {ties += frac; return;}
	win += frac; return;
}

void b(vector<ll>v, ll s, ll c, ll cardsUsed, ll cardsLeft, long double frac, ll aces) {
	ll acesMult = 1;
	if (c + aces*11 <= 21) acesMult = 11;
	if (c+aces*acesMult >= 17) return addCase(s, c+aces*acesMult, cardsUsed, frac);
	for (ll i = 1; i < 11; ++i) {
		if (v[i] != 0) {
			--v[i];
			if (i == 1) b(v, s, c, cardsUsed+1, cardsLeft-1, frac*(v[i]+1)/cardsLeft, aces+1);
			else b(v, s, c+i, cardsUsed+1, cardsLeft-1, frac*(v[i]+1)/cardsLeft, aces);
			++v[i];
		}
	}
}


int main(){
	ll s, c;
	string S;
	cin >> S >> c;
	vector<ll>v(11);
	ll totalCards = 0;
	for (ll i = 1; i <= 10; ++i) {cin >> v[i]; totalCards += v[i];}
	if (S == "B") {
		cout << "100.0" << endl << "0.0" << endl << "0.0" << endl;
		return 0;
	}
	s = stoi(S);
	if (s > 21) {
		cout << "0.0" << endl << "0.0" << endl << "100.0" << endl;
		return 0;
	}
	int aces = 0;
	if (c == 11 || c == 1) {++aces; c = 0;}
	b(v, s, c, 1, totalCards, 1, aces);
	total = win+ties+lose;
	cout << setprecision(1) << fixed;
	cout << double(floor(win*1000/total))/10 << endl;
	cout << double(floor(ties*1000/total))/10 << endl;
	cout << double(floor(lose*1000/total))/10 << endl;
}