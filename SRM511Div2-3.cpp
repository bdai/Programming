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

class FiveHundredEleven {
  int n;
  vector<int> input;
  int result[512][100];
  bool isWinning(int mem, int played) {
    if (mem == 511) return 1;
    if (played == n) return 0;
    int& pos = result[mem][played];
    if (pos == -1) {
      pos = 0;
      int cnt = 0;
      for (int i = 0; i < n; i++)
	if ( (mem | input[i]) == mem)
	  cnt++;
      if (cnt > played && !isWinning(mem, played + 1))
	pos = 1;
      for (int i = 0; i < n; i++)
	if ( (mem | input[i]) != mem && !isWinning( mem | input[i], played + 1))
	  pos = 1;
    }
    return (bool) pos;
  }
public:
  string theWinner(vector<int> cards) {
    n = (int)cards.size();
    input = cards;
    for (int i = 0; i < 512; i++)
      for (int j = 0; j < n; j++)
	result[i][j] = -1;
    if (isWinning(0, 0))
      return "Fox Ciel";
    return "Toastman";
  }
};

int main() {
  return 0;
}
