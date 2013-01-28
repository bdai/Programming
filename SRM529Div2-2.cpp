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
#include <sstream>
using namespace std;

string roman[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
"XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX",
"XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX",
"XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL",
"XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L"};

struct kingObj {
  string name;
  int ordinal;
};
bool comp(kingObj a, kingObj b) {
  if (a.name == b.name) return a.ordinal < b.ordinal;
  return a.name < b.name;
}

class KingSort {
  int getNum(string str) {
    for (unsigned i = 0; i < 50; i++)
      if (str == roman[i]) return i + 1;
    return -1;
  }
  string getOrd(int num) {
    return roman[num - 1];
  }
public:
  vector <string> getSortedList(vector <string> kings) {
    vector <kingObj> cand;
    for (unsigned i = 0; i < kings.size(); i++) {
      size_t num = kings[i].find(' ');
      kingObj tmp;
      tmp.name = kings[i].substr(0, num);
      tmp.ordinal = getNum(kings[i].substr(num + 1, kings[i].size() - num - 1));
      cand.push_back(tmp);
    }
    sort(cand.begin(), cand.end(), comp);
    vector<string> ret;
    for (unsigned i = 0; i < cand.size(); i++) {
      string str = cand[i].name + " " + getOrd(cand[i].ordinal);
      ret.push_back(str);
    }
    return ret;
  }
};

int main() {
  vector<string> test;
  test.push_back("Louis IX");
  test.push_back("Louis VIII");
  KingSort obj;
  obj.getSortedList(test);

  return 0;
}
