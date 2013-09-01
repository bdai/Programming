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
using namespace std;

class SRMCodingPhase {
  int pow2(int num) {
    int ret = 1;
    for (int i = 0; i < num; i++)
      ret *= 2;
    return ret;
  }
public:
  int countScore(vector<int> p, vector<int> s, int l) {
    int total = 0;
    for (int perm = 0; perm < 8; perm++) {
      int timeSpent = 0, current = 0, luck = l;
      for (int i = 2; i >= 0; i--)
	if (perm / pow2(i) % 2) {
	  if (s[i] > luck) {
	    current += p[i] - pow2(i + 1) * (s[i] - luck);
	    timeSpent += s[i] - luck;
	    luck = 0;
	  } else {
	    current += p[i] - pow2(i + 1);
	    luck -= s[i] - 1;
	    timeSpent += 1;
	  }
	}
      if (timeSpent <= 75 && current > total) 
	total = current;
    }
    return total;
  }
};

int main() {
  int myint1[] = {300, 600, 900};
  int myint2[] = {30, 65, 90};
  vector<int> vec1(myint1, myint1 + sizeof(myint1) / sizeof(int));
  vector<int> vec2(myint2, myint2 + sizeof(myint2) / sizeof(int));
  SRMCodingPhase test;
  cout << test.countScore(vec1, vec2, 25) << endl;
  return 0;
}
