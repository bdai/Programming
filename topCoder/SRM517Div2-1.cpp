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

class MonochromaticBoard {
public: 
  int theMin(vector <string> b) {
    int row, col;
    row = col = 0;
    int H = (int) b.size(), W = (int) b[0].size();
    for (int i = 0; i < H; i++) {
      int j;
      for (j = 0; j < W; j++)
	if (b[i][j] == 'W')
	  break;
      if (j == W)
	row++;
    }
    for (int i = 0; i < W; i++) {
      int j;
      for (j = 0; j < H; j++)
	if (b[j][i] == 'W')
	  break;
      if (j == H)
	col++;
    }
    bool white = 0;
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++)
	if (b[i][j] == 'W') 
	  white = 1;
    if (white)
      return row + col;
    else
      return min(row, col);
  }
};

int main() {
  return 0;
}
