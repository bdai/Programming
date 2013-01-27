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

class PassingGrade {
  int ceiling(double num) {
    int inum = (int) num;
    if (num - inum < 1e-3)
      return inum;
    return inum + 1;
  }
public:
  int pointsNeeded(vector<int> pe, vector<int> pp, int final) {
    int total = 0;
    for (unsigned i = 0; i < pp.size(); i++)
      total += pp[i];
    total += final;
    double req = total * .65;
    for (unsigned i = 0; i < pe.size(); i++)
      req -= pe[i];
    if (req < 0) req = 0;
    int ret = ceiling(req);
    if (ret > final) ret = -1;
    return ret;
  }
};

int main() {
  return 0;
}
