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

class MinskyMysteryDiv2 {
  long long getFac (long long N) {
    if (N % 2 == 0) return 2;
    long long upper = static_cast<long long> (sqrt((double)N));
    for (long long num = 3; num <= upper; num += 2) 
      if (N % num == 0) return num;
    return N;
  }
public:
  long long computeAnswer(long long N) {
    if (N == 0 || N == 1) return -1;
    long long fac = getFac(N);
    return N / fac + fac;
  }
};


int main() {
  return 0;
}
