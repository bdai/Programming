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

class CorrectMultiplication {
  int min(int a, int b) {
    return a > b ? a : b;
  }
public:
  long long getMinimum(int a, int b, int c) {
    int res = a + b + c - 3;
    for (int A = 1; A < res + c; A++)
      for (int B = 1; B <= (res + c) / A; B++) {
	long long C = A * B;
	res = min(res, abs(A - a) + abs(B - b) + abs(C - c));
      }
    return res;
  }
};

int main() {
  return 0;
}
