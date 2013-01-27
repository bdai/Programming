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

class bli {
public:
  int r, a;
};

bool comp(const bli& a,
     const bli& b) {
  return a.r > b.r;
}

class MagicBlizzard {
public:
  double expectation(vector<int> rr, vector<int> aa) {
    vector<bli> vec;
    int N = (int) rr.size();
    int range = 0, sum = 0;
    for (int i = 0; i < N; i++) {
      bli tmp;
      tmp.r = rr[i];
      tmp.a = aa[i];
      vec.push_back(tmp);
      if (tmp.r > range)
	range = tmp.r;
      sum += tmp.a;
    }
    sort(vec.begin(), vec.end(), comp);
    vector<double> indi(sum + 1, 0);
    indi[0] = 1;
    int pos = 0, prev = -1;
    for (int i = 0; i < N; i++) {
      double prob = 1;
      if (prev != -1)
	for (int k = 1; k <= pos; k++) {
	  indi[k] /= static_cast<double> (prev * 2 + 1);
	  prob -= indi[k];
	}
      indi[0] = prob;
      prev = vec[i].r;

      for (int j = 0; j < vec[i].a; j++) {
	prob = 1;
	for (int k = pos + 1; k > 0; k--) {
	  indi[k] += indi[k - 1] / static_cast<double> (vec[i].r * 2 + 1);
	  prob -= indi[k];
	}
	indi[0] = prob;
      }
    }
    double ret = 0;
    for (int i = 1; i <= sum; i++)
      ret += i * i * indi[i];
    return ret;
  }
};

int main() {
  return 0;
}
