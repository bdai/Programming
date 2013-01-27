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

class GameOfLifeDivTwo {
  int N;
  string update(string str) {
    string ret(str);
    for (int i = 0; i < N; i++) {
      int left = i - 1, right = i + 1;
      if (left < 0)
	left = N - 1;
      if (right >= N)
	right = 0;
      int sum = (str[i] + str[left] + str[right]) - (int)('0') * 3;
      if (sum >= 2)
	ret[i] = '1';
      else
	ret[i] = '0';
    }
    return ret;
  }
public:
  string theSimulation(string init, int T) {
    string str(init);
    N = (int) init.size();
    for (int t = 0; t < T; t++)
      str = update(str);
    return str;
  }
};

int main() {
  return 0;
}
