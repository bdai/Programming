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


class WhichDay {
  vector<string> week;
public:
  string getDay(vector<string> input) {
    week.push_back("Monday");
    week.push_back("Tuesday");
    week.push_back("Wednesday");
    week.push_back("Thursday");
    week.push_back("Friday");
    week.push_back("Saturday");
    week.push_back("Sunday");
    vector<bool> days(7, 1);
    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 7; j++)
	if (input[i] == week[j])
	  days[j] = 0;
    for (int i = 0; i < 7; i++)
      if (days[i])
	return week[i];
    return "0";
  }
};

int main() {
  return 0;
}
