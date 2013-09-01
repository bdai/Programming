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

class NoOrderOfOperations {
  int eval (int num1, int num2, char op) {
    switch(op) {
    case '+':
      return num1 + num2;
    case '-':
      return num1 - num2;
    case '*':
      return num1 * num2;
    }
    return 0;
  }

public:
  int evaluate(string expr) {
    int ret = 0;
    char op = '+';
    bool num = 1;
    for (unsigned i = 0; i < expr.size(); i++) {
      if (num) {
	ret = eval(ret, expr[i] - '0', op);
	num = 0;
      } else {
	op = expr[i];
	num = 1;
      }
    }
    return ret;
  }
};


int main() {
  string str = "3+5*7";
  NoOrderOfOperations test;
  cout << test.evaluate(str) << endl;
  return 0;
}
