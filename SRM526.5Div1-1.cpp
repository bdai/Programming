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

class MagicCandy {
public:
  int whichOne(int n) {
    int ret = n, count = n;
    while (count > 1) {
      int sq = (int) sqrt(count);
      if (sq * sq == count) ret--;
      count -= sq;
    }
    return ret;
  }
};

int main() {
  MagicCandy test;
  cout << test.whichOne(20) << endl;
  return 0;
}
