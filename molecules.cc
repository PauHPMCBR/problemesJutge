#include <bits/stdc++.h>
using namespace std;
//save the last sum, and then remove all speeds that exceed the next position
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long sum = 0;
	vector<pair<int,int>>v(n); //vector sorted by position
	set<pair<int,int>>s; //set sorted by speed
	for (int i = 0; i < n; ++i) cin >> v[i].first;
	for (int i = 0; i < n; ++i) {
		cin >> v[i].second;
		s.insert({v[i].second, v[i].first});
	}
	sort(v.begin(), v.end());
	int lastSum = 0; //used to save the last sum
	int lastSpeed; //to compare speed with previous one
	int lastPos = -1; //same with pos
	int numUsed = 0; //stores the amount of molecules in the lastSum variable
	unordered_map<int,bool>used; //stores if a molecule is used in lastSum variable
 
	for (int i = 0; i < n; ++i) { //iterate from position left to position right
		int speed = v[i].second;
		int pos = v[i].first;
		s.erase({speed,pos}); //erase the current position, we'll not compare positions to the left
 
		if (used[pos]) { //erase the current position from used map, the lastSum variable and numsUsed if it was used
			used[pos] = false;
			lastSum -= abs(lastPos - pos);
			--numUsed;
		}
		lastSum -= (pos - lastPos)*numUsed; //update lastSum to the new location, every position is closer to the current position now
 
		pair<int,int>p1 = {speed,pos}; //for the lower_bound
 
		if (lastPos == -1) { //if it's the first time, initialize all variables. we sum every position that has a greater speed than the first position
			if (!s.empty()) {
				for (auto it = lower_bound(s.begin(), s.end(), p1); it != s.end(); ++it) {
					sum += abs(pos - (*it).second);
					++numUsed;
					used[(*it).second] = true;
				}
			}
			lastSum = sum;
			lastPos = pos;
			lastSpeed = speed;
		}
		else {
			if (!s.empty()) {
				pair<int,int>p2 = {lastSpeed,lastPos}; //for lower_bound
				if (lastSpeed < speed) { //if the current speed is faster, then erase the molecules in the range of pos-lastPos
					for (auto it = upper_bound(s.begin(), s.end(), p2); it != upper_bound(s.begin(), s.end(), p1); ++it) {
						if (used[(*it).second]) {
							lastSum -= abs(pos - (*it).second);
							--numUsed;
							used[(*it).second] = false;
						}
					}
				}
				else if (lastSpeed > speed) { //if speed is slower, add molecules in the range of pos-lastPos, as they now should be counted
					for (auto it = upper_bound(s.begin(), s.end(), p1); it != upper_bound(s.begin(), s.end(), p2); ++it) {
						if (!used[(*it).second]) {
							lastSum += abs(pos - (*it).second);
							++numUsed;
							used[(*it).first] = true;
						}
					}
				}
			}
			sum += lastSum; //update variables
			lastPos = pos;
			lastSpeed = speed;
		}
	}
	cout << sum << endl;
}