#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Track {
  string artist, title, genre;
  int year;
};

bool comp(Track t1, Track t2) {
  if (t1.artist != t2.artist) return t1.artist < t2.artist;
  if (t1.year != t2.year) return t1.year < t2.year;
  return t1.title < t2.title;
}

vector<vector<Track>>g;

vector<Track> read_tracks(int n) {
  vector<Track>v(20);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].artist >> v[i].title >> v[i].genre >> v[i].year;
    int ind = 0;
    while (ind < g.size() and g[ind][0].genre != v[i].genre) ++ind;
    if (ind == g.size()) g.push_back({v[i]});
    else g[ind].push_back(v[i]);
  }
  return v;
}

void print_track(const Track &t) {
  cout << t.artist;
  cout << " (" << t.year;
  cout << ") " << t.title << " (" << t.genre << ")" << endl;
}

int main() {
  int n;
  cin >> n;
  vector<Track>v = read_tracks(n);
  for (int i = 0; i < g.size(); ++i) sort(g[i].begin(), g[i].end(), comp);
  string genre;
  while (cin >> genre) {
    int ind = 0;
    while (ind < g.size() and g[ind][0].genre != genre) ++ind;
    if (ind != g.size()) {
      for (int i = 0; i < g[ind].size(); ++i) print_track(g[ind][i]);
    }
  }
}