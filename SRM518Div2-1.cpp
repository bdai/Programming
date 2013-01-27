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

class TwiceString {
public:
  string getShortest(string s) {
    int len = (int)s.size();
    int i;
    for (i = 1; i < len; i++) {
      int j;
      for (j = 0; j < len - i; j++)
	if (s[j] != s[i + j])
	  break;
      if (j == len - i)
	return s + s.substr(len - i);
    }
    return s + s;
  }
};

int main() {
  TwiceString test;
  cout << test.getShortest("abracadabra") << endl;
  return 0;
}
