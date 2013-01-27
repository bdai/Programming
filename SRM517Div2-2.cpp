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

class CompositeSmash {
  bool possible(int N, int t) {
    if (N < t) return 0;
    if (N == t) return 1;
    bool success = 0;
    for (int i = 2; i <= (int) sqrt(N); i++) 
      if (N % i == 0) { 
	if ( possible(i, t) || possible( N / i, t) ) {
	  success = 1;
	} else {
	  return 0;
	}
      }
    return success;
  }
public:
  string thePossible(int N, int t) {
    if (possible(N, t))
      return "Yes";
    return "No";
  }
};

int main() {
  CompositeSmash test;
  cout << test.thePossible(24517, 23868) << endl;
  return 0;
}
