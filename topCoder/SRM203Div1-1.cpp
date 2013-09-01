#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <list>
#include <cmath>
#include <map>
using namespace std;

struct obj {
  string name, answer;
};

bool comp(const obj&a, const obj&b) {
  return a.name < b.name;
}

class MatchMaking {
  int getScore(const string& s1, const string& s2) const {
    int score = 0;
    for (unsigned i = 0; i < s1.size(); i++)
      if (s1[i] == s2[i])
	score++;
    return score;
  }
public:
  string makeMatch(vector<string> nw, vector<string> aw, 
		  vector<string> nm, vector<string> am,
		  string t) {
    vector<obj> m, w;
    for (unsigned i = 0; i < nw.size(); i++) {
      obj tmp;
      tmp.name = nw[i];
      tmp.answer = aw[i];
      w.push_back(tmp);
      tmp.name = nm[i];
      tmp.answer = am[i];
      m.push_back(tmp);
    }
    sort(w.begin(), w.end(), comp);
    sort(m.begin(), m.end(), comp);
    vector<bool> c(nw.size(), 0);
    for (unsigned i = 0; i < nw.size(); i++) {
      int index = -1;
      for (unsigned j = 0; j < nm.size(); j++)
	if (!c[j]) {
	  index = j;
	  break;
	}
      int maxs = 0;
      for (unsigned j = 0; j < nm.size(); j++)
	if (!c[j]) {
	  if (getScore(w[i].answer, m[j].answer) > maxs) {
	    index = j;
	    maxs = getScore(w[i].answer, m[j].answer);
	  }
	}
      if (w[i].name == t)
	return m[index].name;
      c[index] = 1;
    }
    return "";
  }
};

int main() {
  vector <string> t1, t2, t3, t4;
  t1.push_back("A");
  t1.push_back("B");
  t1.push_back("C");
  t2.push_back("a");
  t2.push_back("a");
  t2.push_back("a");
  t3.push_back("A");
  t3.push_back("B");
  t3.push_back("C");
  t4.push_back("a");
  t4.push_back("b");
  t4.push_back("b");
  MatchMaking test;
  cout << test.makeMatch(t1, t2, t3, t4, "B");
  return 0;
}
