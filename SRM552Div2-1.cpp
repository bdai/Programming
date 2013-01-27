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

class FoxAndFlowerShopDivTwo {
  void compare (int& ret, int quant) {
    if (ret < quant)
      ret = quant;
  }

public:
  int theMaxFlowers (vector<string> f, int r, int c) {
    int ret, quant;
    unsigned row = f.size(), col = f[0].size();
    ret = quant = 0;

    for (unsigned i = 0; i < row; i++) 
      for (unsigned j = 0; j < (unsigned) c; j++)
	if (f[i][j] == 'F')
	  quant++;
    compare(ret, quant);
    quant = 0;
    for (unsigned i = 0; i < row; i++)
      for (unsigned j = c + 1; j < col; j++)
	if (f[i][j] == 'F')
	  quant++;
    compare(ret, quant);
    quant = 0;
    for (unsigned i = 0; i < (unsigned)r; i++)
      for (unsigned j = 0; j < col; j++)
	if (f[i][j] == 'F')
	  quant++;
    compare(ret, quant);
    quant = 0;
    for (unsigned i = r + 1; i < row; i++)
      for (unsigned j = 0; j < col; j++)
	if (f[i][j] == 'F')
	  quant++;
    compare(ret, quant);
    return ret;
  }
};

int main() {
  return 0;
}
