#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Submission {
	string idn;
	string exer;
	int time;
	string res;
};

bool comp(Submission a, Submission b) {
	return (a.time < b.time ? a : b);
}

struct Student {
	string idn;
	int gs;
	int ge;
	int re;
	int te;
	vector<string>greenExer;
	vector<string>triedExer;
	vector<string>redExer; //bruh quin pal get gutter
}

typedef vector<Submission> History;


Student update(Student s, Submission x) {
	if (res == "green") {
		int i = 0;
		while (i < s.greenExer.size() and s.greenExer[i] != x.exer) ++i;
		if (i == s.greenExer.size()) {
			s.greenExer.push_back(x.exer);
			++ge;
		}
		++gs;
	}
	else if (res == "red") 
}

int main() {
	int n;
	cin >> n;
	History hist(n);
	for (int i = 0; i < n; ++i) cin >> hist.idn >> hist.exer >> hist.time >> hist.res;
	vector<Student>stu;
	Student newStudent;

	sort(hist.begin(), hist.end(), comp);
	for (int i = 0; i < n; ++i) {
		int j = 0;
		while (j < stu.size() && stu[j].idn != hist[i].idn) ++j;
		if (j == stu.size()) {
			stu.push_back(newStudent);
			stu[j].idn = hist[i].idn;
		}
		stu[j] = update(stu[j], hist[i]);
	}
}