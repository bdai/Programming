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

class LargestSubsequence {
public:
  string getLargest(string s) {
    int len = (int) s.size();
    string ret("");
    int pos = 0;
    while (pos < len) {
      int start = pos;
      char c = s[start];
      for (int i = pos + 1; i < len; i++)
	if (s[i] > c) {
	  c = s[i];
	  pos = i;
	}
      ret += c;
      pos++;
    }
    return ret;
  }
};

int main() {
  LargestSubsequence test;
  cout << test.getLargest("test") << endl;
  return 0;
}
