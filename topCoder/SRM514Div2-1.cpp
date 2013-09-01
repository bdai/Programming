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

class MagicalGirlLevelOneDivTwo {
public:
  double theMinDistance(int d, int x, int y) {
    x = abs(x);
    y = abs(y);
    int stepx = x / d;
    int stepy = y / d;
    int newx = stepx * d - (d - x % d);
    int newy = stepy * d - (d - y % d);
    newx = newx > 0 ? newx : 0;
    newy = newy > 0 ? newy : 0;
    return sqrt( (double) newx * newx + newy * newy);
  }
};

int main() {
  MagicalGirlLevelOneDivTwo test;
  cout << test.theMinDistance(5, 10, 10) << endl;
  return 0;
}
