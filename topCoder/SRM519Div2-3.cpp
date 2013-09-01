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

class BinaryCards {
  vector<long long> powers;
  long long largest(long long number) {
    vector<int> digit(64, 0);
    long long num = number;
    for (int i = 62; i >= 0; i--)
      if (num >= powers[i]) {
	digit[i] = 1;
	num -= powers[i];
      }
    for (int i = 0; i < 63; i++)
      if (!digit[i])
	return number + powers[i];
    return 0;
  }
  bool check(long long num) {
    for (int i = 0; i < 63; i++)
      if (num == powers[i])
	return 1;
    return 0;
  }
public:
  long long largestNumber(long long A, long long B) {
    if (A == B)
      return A;
    long long current = 1;
    powers.push_back(current);
    for (int i = 1; i < 64; i++) {
      current *= 2;
      powers.push_back(current);
    }
    for (long long i = B - 1; i >= A; i--) {
      long long flip = largest(i);
      if (flip > current)
	current = flip;
      if (check(i))
	break;
    }
    return current;
  }
};

int main() {
  BinaryCards test;
  cout << test.largestNumber(1, 99999999999999999) << endl;
  return 0;
}
