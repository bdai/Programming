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

class CountingSeries {
public:
  long long countThem (long long a, long long b, long long c, long long d,
		       long long up) {
    long long num1 = (up - a) / b + 1;
    long long current = c, num2 = 0;
    while (current <= up) {
      if ( current < a || (current - a) % b)
	num2++;
      current *= d;
      if (d == 1)
	break;
    }
    return num1 + num2;
  }
};

int main() {
  CountingSeries test;
  cout << test.countThem(452, 24, 4, 5, 600) << endl;
  return 0;
}
