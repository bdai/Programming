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

class CubePacking {
  int d1, d2, d3;
  int evalVol() {
    return d1 * d2 * d3;
  }
  int upperInt(int small, int large) {
    if (large % small == 0)
      return large / small;
    return large / small + 1;
  }
public:
  int getMinimumVolume(int Ns, int Nb, int L) {
    int ret = 1 << 30;

    d1 = d2 = L;
    d3 = L * Nb + upperInt(d1 * d2, Ns);
    if (evalVol() < ret)
      ret = evalVol();

    int dims;
    for (dims = 1; dims <= 100; dims++) 
      if (dims * dims * dims >= Nb)
	break;
    int diff = L * L * L * (dims * dims * dims - Nb);
    d1 = d2 = d3 = dims * L;
    if (diff >= Ns) {
      if (evalVol() < ret)
	ret = evalVol();
    } else {
      d3 += upperInt(dims * dims * L * L, Ns);
      if (evalVol() < ret)
	ret = evalVol();
      for (int i = 1; i < Ns; i++) {
	d1 = d2 = d3 = dims * L + i;
	if (evalVol() >= Nb * L * L * L + Ns)
	  break;
      }
      if (evalVol() < ret)
	ret = evalVol();
    }
    return ret;
  }
};

int main() {
  CubePacking test;
  cout << test.getMinimumVolume(12345, 987, 10) << endl;
  return 0;
}
