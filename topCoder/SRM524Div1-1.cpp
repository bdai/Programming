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

class MagicDiamonds {
  bool isPrime(long long n) {
    if (n == 2 || n == 3)
      return 1;
    if (n % 2 == 0)
      return 0;
    for (long long i = 3; i <= sqrt(n); i += 2)
      if (n % i == 0)
	return 0;
    return 1;
  }
public:
  long long minimalTransfer (long long n) {
    if (n == 1 || n == 3)
      return n;
    if (isPrime(n))
      return 2;
    return 1;
  }
};

int main() {
  return 0;
}
