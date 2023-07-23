#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Teacher {
	string name;
	int sweets;
	int carrots;
};

bool comp(Teacher a, Teacher b) {
	if (a.sweets != b.sweets) return (a.sweets > b.sweets);
	if (a.carrots != b.carrots) return (a.carrots > b.carrots);
	if (a.name.size() != b.name.size()) return (a.name.size() < b.name.size());
	return (a.name < b.name);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		vector<Teacher>teachers(t);
		for (int j = 0; j < t; ++j) cin >> teachers[j].name >> teachers[j].sweets >> teachers[j].carrots;
		sort(teachers.begin(), teachers.end(), comp);
		for (int j = 0; j < t; ++j) cout << teachers[j].name << endl;
		cout << endl;
	}
}