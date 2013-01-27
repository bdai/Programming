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

class YahtzeeScore {
public:
  int maxPoints(vector <int> toss) {
    int sum = 0;
    for (int i = 1; i <= 6; i++) {
      int tmp = 0;
      for (unsigned j = 0; j < toss.size(); j++)
	if (toss[j] == i)
	  tmp += i;
      if (tmp > sum)
	sum = tmp;
    }
    return sum;
  }
};

int main() {
  return 0;
}
