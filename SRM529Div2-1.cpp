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

class PairingPawns {
public:
  int savedPawnCount(vector<int> start) {
    for (unsigned i = start.size() - 1; i > 0; i--) 
      start[i - 1] += start[i] / 2;
    return start[0];
  }
};

int main() {
  return 0;
}
