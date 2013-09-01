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

class BrickN {
  int kk;
  vector<vector<long long> > dp;
  int counting(int ww, int hh) {
    if (dp[ww][hh] >= 0)
      return dp[ww][hh];
    if (hh == 0) {  
      dp[ww][hh] = 1;
      return 1;
    }
    if (ww == 0) {
      dp[ww][hh] = 1;
      return 1;
    }
    if (hh == 1) {
      if (ww == 1) {
	dp[ww][hh] = 1;
	return 1;
      } else {

    }
    return dp[ww][hh];
  }
public:
  int countStructures(int w, int h, int k) {
    kk = k;
    dp.resize(w + 1, vector<long long>(h + 1, -1));
    return counting(w, h);
  }
};

int main() {
  BrickN test;
  cout << test.countStructures(3, 1, 3) << endl;
  return 0;
}
