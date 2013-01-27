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

class NetworkXMessageRecovery {
public:
  string recover(vector<string> m) {
    int len = (int)m.size();
    string ret = "";
    sort(m.begin(), m.end());
    while(1) {
      char best = '{';
      for (int i = 0; i < len; i++) 
	if (m[i].size() > 0) {
	  char current = m[i][0];
	  for (int j = 0; j < len; j++) 
	    for (int k = 1; k < (int)m[j].size(); k++)
	      if (m[j][k] == current)
		current = '{';
	  best = best < current ? best : current;
	}
      if (best == '{')
	break;
      ret += best;
      for (int i = 0; i < len; i++)
	if (m[i].size() > 0 && m[i][0] == best)
	  m[i] = m[i].substr(1);
    }
    return ret;
  }
};

int main() {
  return 0;
}
