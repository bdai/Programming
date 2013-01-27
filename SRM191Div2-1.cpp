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

class BettingMoney {
public:
  int moneyMade (vector<int> amounts, vector<int> cents, int final) {
    int cost, profit;
    cost = profit = 0;
    for (int i = 0; i < (int) amounts.size(); i++) {
      if (i != final) 
	profit += amounts[i] * 100;
      else 
	cost += amounts[i] * cents[i]; 
    }
    return profit - cost;
  }
};

int main() {
  return 0;
}
