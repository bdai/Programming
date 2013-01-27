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

int direcx[] = {1, 1, -1, -1};
int direcy[] = {1, -1, 1, -1};
class MagicalGirlLevelTwoDivTwo {
public:
  string isReachable(vector <int> jump, int x, int y) {
    vector< vector<bool> > grid(202, vector<bool>(202, 0));
    grid[100][100] = 1;
    int len = (int) jump.size();
    int xx, yy;
    bool update = 1;
    while (update) {
      update = 0;
      for (int i = 0; i < 202; i++)
	for (int j = 0; j < 202; j++) {
	  if (grid[i][j]) {
	    for (int k = 0; k < len; k++) { 
	      for (int l = 0; l < 4; l++) {
		xx = i + direcx[l] * jump[k];
		yy = i + direcy[l];
		if (xx < 202 && xx >= 0 && yy < 202 && yy >= 0 &&
		      !grid[xx][yy]) {
		  grid[xx][yy] = 1;
		  update = 1;
		}

	      }
	      for (int l = 0; l < 4; l++) {
		xx = i + direcx[l];
		yy = i + direcy[l] * jump[k];
		if (xx < 202 && xx >= 0 && yy < 202 && yy >= 0 &&
		      !grid[xx][yy]) {
		  grid[xx][yy] = 1;
		  update = 1;
		}
	      }
	    }
	  }
	}
    }
    if (grid[x + 100][y + 100])
      return "YES";
    return "NO";
  }
};

int main() {
  MagicalGirlLevelTwoDivTwo test;
  int myint[] = {2};
  vector <int> input (myint, myint + sizeof(myint) / sizeof(int));
  cout << test.isReachable(input, 5, 4) << endl;
  return 0;
}
