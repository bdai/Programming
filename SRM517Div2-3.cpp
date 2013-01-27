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

struct grass {
  int init, grow;
};

bool comp(grass a, grass b) {
  if (a.grow == b.grow)
    return a.init < b.init;
  return a.grow < b.grow;
}

class CuttingGrass {
  vector<grass> ele;
  int len, height;
  bool finish(vector<grass> tmp) {
    int sum = 0;
    for (int i = 0; i < len; i++)
      sum += tmp[i].init;
    return sum <= height;
  }

  bool possible(int num) {
    vector<grass> rep(ele);
    for (int i = 0; i < num; i++) {
      if (finish(rep))
	return 1;
      for (int j = 0; j < len; j++)
	rep[j].init += rep[j].grow;
      rep[len - num + i].init = 0;
    }
    return 0;
  }
  int bisec(int low, int high) {
    if (low == high)
      return low;
    int mid = (low + high) / 2;
    if (possible(mid))
      return bisec(low, mid);
    return bisec(mid, high);
  }
public:
  int theMin(vector<int> init, vector<int> grow, int H) {
    len = (int) init.size();
    for (int i = 0; i < len; i++) {
      grass here;
      here.init = init[i];
      here.grow = grow[i];
      ele.push_back(here);
    }
    height = H;
    sort(ele.begin(), ele.end(), comp);
    if (!possible(len))
      return -1;
    return bisec(0, len);
  }
};

int main() {
  int myint1[] = {5, 8, 58};
  vector<int> init(myint1, myint1 + sizeof(myint1) / sizeof(int));
  int myint2[] = {2, 1, 1};
  vector<int> grow(myint2, myint2 + sizeof(myint2) / sizeof(int));
  CuttingGrass test;
  cout << test.theMin(init, grow, 16) << endl;
  return 0;
}
