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

class DropCoins {
  int counting (const vector<string>& str,
		unsigned i, unsigned j,
		unsigned k, unsigned l) {
    int count = 0;
    for (unsigned x = i; x <= k; x++)
      for (unsigned y = j; y <= l; y++)
	if (str[x][y] == 'o')
	  count++;
    return count;
  }
public:
  int getMinimum(vector<string> str, int K) {
    unsigned len1 = str.size();
    unsigned len2 = str[0].size();
    int count = 1 << 16;
    for (unsigned i = 0; i < len1; i++) 
      for (unsigned j = 0; j < len2; j++)
	for (unsigned k = i; k < len1; k++)
	  for (unsigned l = j; l < len2; l++) 
	    if (counting(str, i, j, k, l) == K) {
	      int w1 = i, w2 = len1 - k - 1;
	      int h1 = j, h2 = len2 - l - 1;
	      int tmp = min(w1, w2) * 2 + max(w1, w2);
	      tmp += min(h1, h2) * 2 + max(h1, h2);
	      if (tmp < count)
		count = tmp;
	    }
    if (count == 1 << 16)
      return -1;
    return count;
  }
};

int main() {
  DropCoins test;
  vector<string> tt;
  string tmp = ".o..";
  tt.push_back(tmp);
  tmp = "oooo";
  tt.push_back(tmp);
  tmp = "..o.";
  tt.push_back(tmp);
  cout << test.getMinimum(tt, 3) << endl;
  return 0;
}
