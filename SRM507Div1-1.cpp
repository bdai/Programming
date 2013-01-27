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

class CubeStickers {
public:
  string isPossible (vector<string> sticker) {
    map<string, int> color;
    for (unsigned i = 0; i < sticker.size(); i++)
      color[sticker[i]]++;

    vector<int> counts;
    for (map<string, int>::iterator iter = color.begin();
	 iter != color.end(); iter++) 
      counts.push_back(iter -> second);

    int sum = 0;
    for (unsigned i = 0; i < counts.size(); i++)
      if (counts[i] >= 2)
	sum += 2;
      else
	sum++;
    if (sum >= 6)
      return "YES";
    else
      return "NO";
  }
};

int main() {
  return 0;
}
