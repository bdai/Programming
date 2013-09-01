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

class UserName {
  bool isIn (const vector<string>& name,
	     const string& check) {
    for (unsigned i = 0; i < name.size(); i++)
      if (check == name[i])
	return 1;
    return 0;
  }
  string constr(int number) {
    string ret = "";
    while (number > 0) {
      char tmp = number % 10 + '0';
      ret = tmp + ret;
      number /= 10;
    }
    return ret;
  }
public:
  string newMember (vector <string> name, string input) {
    if (!isIn(name, input))
      return input;
    for (int i = 0; i < (int) name.size() + 1; i++) {
      string num (constr(i));
      string str = input + num;
      if (!isIn(name, str))
	return str;
    }
  }
};

int main() {
  return 0;
}
