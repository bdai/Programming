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

class MissingParentheses {
public:
  int countCorrections(string par) {
    int current = 0;
    int ret = current;
    for (unsigned i = 0; i < par.size(); i++) {
      if (par[i] == '(')
	current++;
      else
	current--;
      while (current < 0) {
	ret++; current++ ;
      }
    }
    return ret + abs(current);
  }
};

int main() {
  return 0;
}
