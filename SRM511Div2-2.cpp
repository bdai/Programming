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

class Zoo {
public:
  long long theCount(vector<int> input) {
    vector<int> count(input.size() + 1, 0);
    for (int i = 0; i < (int) input.size(); i++){
      if (input[i] > (int)input.size())
	return 0;
      count[input[i]]++;
    }
    if (count[0] == 0)
      return 0;
    long long ret = 1;
    bool single = 0;
    for (int i = 0; i < (int) count.size() - 1; i++) {
      if (count[i] > 2 || count[i + 1] > count[i])
	return 0;
      if (count[i] == 2) {
	ret *= 2;
      } else if (count[i] == 1) {
	if (!single) {
	  ret *= 2;
	  single = 1;
	}
      }
    }
    return ret;
  }
};

int main() {
  int myint[] = {1, 0, 0, 1};
  vector<int> vec(myint, myint + sizeof(myint) / sizeof(int));
  Zoo test;
  cout << test.theCount(vec) << endl;
  return 0;
}
