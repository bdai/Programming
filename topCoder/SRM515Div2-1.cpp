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

class FortunateNumbers {
  bool isFortunate(int num) {
    while( num > 0) {
      int digit = num % 10;
      if (digit != 5 && digit != 8)
	return 0;
      num /= 10;
    }
    return 1;
  }
  bool notIn(int num, vector<int> vec) {
    for (int i = 0; i < (int)vec.size(); i++)
      if (num == vec[i])
	return 0;
    return 1;
  }
public:
  int getFortunate(vector<int> a, vector<int> b, vector<int> c) {
    vector<int> number;
    for (int i = 0; i < (int) a.size(); i++) 
      for (int j = 0; j < (int) b.size(); j++)
	for (int k = 0; k < (int) c.size(); k++)
	  if (isFortunate(a[i] + b[j] + c[k]))
	    if ( notIn(a[i] + b[j] + c[k], number))
	      number.push_back(a[i] + b[j] + c[k]);
    return (int) number.size();
  }
};

int main() {
  return 0;
}
