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

class RowAndCoins {
public:
  string getWinner(strging str) {
    unsigned len = str.size();
    if (str[0] == 'A' ||
	str[len - 1] == 'A')
      return "Alice";
    return "Bob";
  }
};

int main() {
  return 0;
}
