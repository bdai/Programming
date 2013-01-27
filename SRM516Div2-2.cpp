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

class NetworkXOneTimePad {
  string xxor(string str1, string str2) {
    int len = (int) str1.size();
    string ret(str1);
    for (int i = 0; i < len; i++) {
      if (str1[i] == str2[i])
	ret[i] = '0';
      else
	ret[i] = '1';
    }
    return ret;
  }
public:
  int crack(vector<string> p, vector<string> c) {
    int ret = 0;
    for (int i = 0; i < (int) c.size(); i++)
      for (int j = 0; j < (int) p.size(); j++) {
	string num = xxor(c[i], p[j]);
	bool valid = 1;
	for (int k = 0; k < (int) c.size(); k++) {
	  if (k != i) {
	    bool success = 0;
	    for (int l = 0; l < (int) p.size(); l++) {
	      if ( xxor(c[k],p[l]) == num) {
		success = 1;
		break;
	      }
	    }
	    if (!success)
	      valid = 0;
	  }
	  if (!valid)
	    break;
	}
	if (valid)
	  ret++;
      }
    return ret / c.size();
  }
};

int main() {
  return 0;
}
