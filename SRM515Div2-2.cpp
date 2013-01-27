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

class RotatedClock {
  bool isValid(int h, int m) {
    if (m % 6 != 0)
      return 0;
    int hou = h % 30 * 2;
    int minu = m / 6;
    return hou  == minu;
  }
  string timeRet(int h, int m) {
    string ret;
    if (h > 9) {
      ret += "1";
      ret += '0' + h % 10;
    } else {
      ret += "0";
      ret += '0' + h;
    }
    ret += ":";
    ret += '0' + m / 10;
    ret += '0' + m % 10;
    return ret;
  }
public:
  string getEarliest(int hourHand, int minuteHand) {
    for (int i = 0; i < 360; i += 30)  {
      int h = (hourHand + i) % 360;
      int m = (minuteHand + i) % 360;
      if (isValid(h, m)) {
	int hh = h / 30;
	int mm = m / 6;
	return timeRet(hh, mm);
      }
    }
    return "";
  }
};

int main() {
  RotatedClock test;
  cout << test. getEarliest(240, 36) << endl;
  return 0;
}
