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

class NetworkXZeroOne {
public:
  string reconstruct(string m) {
    int len = (int)m.size();
    string ret(m);
    int i;
    for (i = 0; i < len; i++) 
      if (ret[i] != '?')
	break;
    bool o;
    if (ret[i] == 'o')
      o = 0;
    else
      o = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (o) {
	ret[j] = 'o';
	o = 0;
      } else {
	ret[j] = 'x';
	o = 1;
      }
    }
    if (ret[i] == 'o')
      o = 0;
    else
      o = 1;
    for (int j = i + 1; j < len; j++) {
     if (o) {
	ret[j] = 'o';
	o = 0;
      } else {
	ret[j] = 'x';
	o = 1;
      }
    }
    return ret;

  }
};

int main() {
  return 0;
}
