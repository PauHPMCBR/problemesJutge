#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
#define VI vector<int>
#define VVI vector<VI>

int psize; //the maximum length used in the primes array
int s = 4; //size of grid
int currentPrime = 0; //current prime position of array
int highest = -1; //only to track progress through couts

VI primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
VVI power; //array that contains the powers of all numbers until they reach the max
vector<VVI> distribution; //how every prime has its exponsents distributed into every used number until now
VVI factorized; //vector of the factorization of every number
VVI grid; //the main grid
VI b; //product of each row
VI a; //product of each column
set<int> notPut; //numbers to skip (will go in the diagonal)

chrono::steady_clock::time_point cBegin;
chrono::steady_clock::time_point cEnd;


void generatePower(int n) {
	power = VVI(n+1);
	for (int i = 2; i <= n; ++i) {
		power[i].push_back(1);
		int prov = i;
		while (prov <= n) {
			power[i].push_back(prov);
			prov *= i;
		}
	}
}

void generateFactorized(int n) {
	cout << n << endl;
	factorized.push_back({0});
	factorized.push_back({1});
	for (int i = 2; i <= n; ++i) {
		bool isNew = true;
		int prov = i;
		for (int j = psize-1; j >= 0; --j) {
			
			while (prov%primes[j] == 0) {
				if (isNew) {
					if (factorized.size() < i) {
						factorized.push_back({i-1});
					}
					factorized.push_back({primes[j]});
					isNew = false;
				}
				else {
					factorized[i].push_back(primes[j]);
				}
				prov /= primes[j];
			}
		}
	}
}

//començar posant els primers mes grans, i despres els petits.
void generateDistribution(int n, bool printDistribution) {
	distribution = vector<VVI>(psize, VVI(n+1, VI(1, 0)));
	VI prov(n+1, 1); //the construction of the number of the factorized vector
	VI lastPos(n+1, 0); //to store the last position of the factorization process
	for (int i = psize-1; i >= 0; --i) {
		for (int j = 1; j <= n; ++j) {

			if (notPut.count(j)) continue;

			int toMult = 1, appearances = 0;
			while(lastPos[j] < factorized[j].size() && factorized[j][lastPos[j]] == primes[i]) {
				toMult *= primes[i];
				++appearances;
				++lastPos[j];
			}
			if (appearances >= distribution[i][prov[j]].size()) distribution[i][prov[j]].push_back(1);
			else ++distribution[i][prov[j]][appearances];
			prov[j] *= toMult;
		}
	}
	if (printDistribution) {
		for (int i = 0; i < psize; ++i) {
			cout << "distribution of " << primes[i] << ": " << endl;
			for (int j = 1; j <= s*s; ++j) {
				cout << j << ": ";
				for (int h : distribution[i][j]) cout << h << ", ";
				cout << endl;
			}
		}
	}
}

void print(VVI& v) {
	int prov = psize;
	int extraOnes = -1;
	set<int>numbers;
	for (int i = 0; i < s*s; ++i) numbers.insert(i+1);
	for (int i = 0; i < s; ++i) {
		for (int j = 0; j < s; ++j) {
			if (i == j) {
				cout << primes[prov];
				numbers.erase(primes[prov]);
				++prov;
			}
			else {
				cout << v[i][j];
				if (v[i][j] == 1) ++extraOnes;
				if (numbers.count(v[i][j])) numbers.erase(v[i][j]);
			}
			cout << ' ';
		}
		cout << endl;
	}
	cout << "extra ones: " << extraOnes << "  Missing numbers: ";
	for (auto i : numbers) cout << i << ' ';
	cout << endl << endl;
	if (numbers.size() < 2) {
		while (true) bool stopWorking = true;
	}
}

void sol(int x, int y, bool f) {
	if (currentPrime < highest) {
		cEnd = chrono::steady_clock::now();
		int time = chrono::duration_cast<chrono::milliseconds>(cEnd-cBegin).count();
		highest = currentPrime;
		cout << currentPrime << ": ";
		cout << time << endl;
		cBegin = cEnd;
		print(grid);
	}
	if (x == s && y == s) {
		//cout << "used: " << used[currentPrime] << endl;
		if (currentPrime == -1) return print(grid);
		--currentPrime;
		sol(0, 0, true);
		++currentPrime;
		return;
	}
	if (y == s) return sol(x+1, x, !f);
	if (x == s) {
		if (b[y] != a[y]) return;
		return sol(y+1, y+1, !f);
	}
	if (x == y) return sol(x, y+1, f);
	int n = grid[x][y];
	for (int i = distribution[currentPrime][n].size()-1; i >= 0; --i) {
	//for (int i = 0; i < distribution[currentPrime][n].size(); ++i) {
		if (!distribution[currentPrime][n][i]) continue;
		a[x] += i;
		b[y] += i;
		--distribution[currentPrime][n][i];
		grid[x][y] *= power[primes[currentPrime]][i];
		if (f) sol(x, y+1, f);
		else sol(x+1, y, f);
		a[x] -= i;
		b[y] -= i;
		++distribution[currentPrime][n][i];
		grid[x][y] /= power[primes[currentPrime]][i];
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	srand(time(0));
	grid = VVI(s, VI(s, 1)); //every cell has the actual number until now
	a = VI(s,0);
	b = VI(s,0);
	psize = 0;
	do ++psize; while (primes[psize] <= s*s/2);
	for (int i = psize; i < primes.size(); ++i) notPut.insert(primes[i]);
	cBegin = chrono::steady_clock::now();

	cout << "calculating powers... ";
	generatePower(s*s);
	cEnd = chrono::steady_clock::now();
	cout << chrono::duration_cast<chrono::milliseconds>(cEnd-cBegin).count() << endl;
	cBegin = cEnd;

	cout << "factorizing numbers... ";
	generateFactorized(s*s);
	cEnd = chrono::steady_clock::now();
	cout << chrono::duration_cast<chrono::milliseconds>(cEnd-cBegin).count() << endl;
	cBegin = cEnd;

	cout << "generating distribution... ";
	generateDistribution(s*s, true);
	cEnd = chrono::steady_clock::now();
	cout << chrono::duration_cast<chrono::milliseconds>(cEnd-cBegin).count() << endl;
	cBegin = cEnd;																																																																																												

	currentPrime = psize-1;
	highest = psize;
	cout << "starting..." << endl;
	sol(0, 0, true);
}
