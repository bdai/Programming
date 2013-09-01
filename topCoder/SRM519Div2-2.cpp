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
#include <sstream>
using namespace std;

struct node {
  long long x, y;
};

class ThreeTeleports {
  vector<node> grid;
  vector<long long> retNum(string str) {
    vector<long long> ret(4, 0);
    istringstream input;
    input.str(str);
    for (int i = 0; i < 4; i++) {
      input >> ret[i];
    }
    return ret;
  }
  long long myabs(long long num) {
    return num > 0 ? num : -num;
  }
  long long distance(int index1, int index2) {
    if ( index1 > index2 ) {
      int tmp = index1;
      index1 = index2;
      index2 = tmp;
    }
    if (index2 - index1 == 1 && index1  % 2 == 1)
      return 10;
    return myabs(grid[index1].x - grid[index2].x) + myabs(grid[index1].y - grid[index2].y);
  }
public:
  int shortestDistance(int x1, int y1, int x2, int y2, vector<string> input) {
    grid.resize(8);;
    grid[0].x = x1;
    grid[0].y = y1;
    grid[7].x = x2;
    grid[7].y = y2;
    for (int i = 0; i < 3; i++) {
      vector<long long> tmp = retNum(input[i]);
      grid[i * 2 + 1].x = tmp[0];
      grid[i * 2 + 1].y = tmp[1];
      grid[i * 2 + 2].x = tmp[2];
      grid[i * 2 + 2].y = tmp[3];
    }
    vector<long long> dist(8, 0);
    for (int i = 1; i < 8; i++)
      dist[i] = distance(i, 0);
    vector<bool> visit(8, 0);
    visit[0] = 1;
    for (int iter = 0; iter < 7; iter++) {
      int current = 0;
      long long minDist = -1;
      for (int i = 0; i < 8; i++) {
	if (!visit[i]) {
	  if (minDist == -1 || minDist > dist[i]) {
	    current = i;
	    minDist = dist[i];
	  } 
	}
      }
      visit[current] = 1;
      for (int i = 0; i < 8; i++)
	if (!visit[i]) 
	  dist[i] = min(dist[i], dist[current] + distance(current, i));
      
    }
    return (int)dist[7];
  }
};

int main() {
  ThreeTeleports test;
  vector<string> input;
  input.push_back("1 1 18 20");
  input.push_back("1000 1003 1000 1004");
  input.push_back("1000 1005 1000 1006");
  cout << test.shortestDistance(0, 0, 20, 20, input) << endl;
  return 0;
}
