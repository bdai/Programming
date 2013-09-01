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

class DucksAlignment {
  int len1;
  int len2;
  vector<string> grid;
  int count;
  int moves(int x, int y, int d) {
    vector<int> pos(count, 0);
    int ret = 0;
    for (int i = 0; i < (int)len1; i++)
      for (int j = 0; j < (int)len2; j++)
	if (grid[i][j] == 'o') {
	  if (d == 0) {
	    ret += abs(i - x);
	    if (j < y) {
	      ret += y - j;
	      pos[0]++;
	    } else if (j >= y + count) {
	      ret += j - y - count + 1;
	      pos[count - 1]++;
	    } else {
	      pos[j - y]++;
	    }
	  } else {
	    ret += abs(j - y);
	    if (i < x) {
	      ret += x - i;
	      pos[0]++;
	    } else if (i >= x + count) {
	      ret += i - x - count + 1;
	      pos[count - 1]++;
	    } else {
	      pos[i - x]++;
	    }
	  }
	}
    for (int i = 0; i < count; i++) {
      if (!pos[i]) {
	int dist = count;
	bool left = 0;
	for (int j = (int) (i - 1); j >= 0; j--)
	  if (pos[j] > 1 && (int) (i - j) < dist) {
	    dist = (int) (i - j);
	    left = 1;
	    break;
	  }

	for (int j = i + 1; j < count; j++)
	  if (pos[j] > 1 && (int) (j - i) < dist) {
	    dist = (int) (j - i);
	    left = 0;
	    break;
	  }
	ret += dist;
	pos[i] = 1;
	if (left) 
	  pos[i - dist]--;
	else 
	  pos[i + dist]--;
      }
    }
    return ret;
  }
public:
  int minimumTime(vector<string> input) {
    grid = input;
    len1 = (int)grid.size();
    len2 = (int)grid[0].size();
    count = 0;
    for (int i = 0; i < len1; i++)
      for (int j = 0; j < len2; j++)
	if (input[i][j] == 'o')
	  count++;
    int ret = 1 << 16;
    for (int i = 0; i < len1; i++)
      for (int j = 0; j <= len2 - count; j++)
	ret = min(ret, moves(i, j, 0));
    for (int i = 0; i < len2; i++)
      for (int j = 0; j <= len1 - count; j++)
	ret = min(ret, moves(j, i, 1));
    return ret;
  }
};

int main() {
  DucksAlignment test;
  vector<string> input;
  string tmp(".o");
  input.push_back(tmp);
  tmp = "o.";
  input.push_back(tmp);
  cout << test.minimumTime(input) << endl;
  return 0;
}
