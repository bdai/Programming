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

class P8XMatrixRecovery {
  int R, C;
  bool match(const string& str1, const string& str2) {
    for (int i = 0; i < R; i++)
      if (str1[i] != '?' && str2[i] != '?' && str1[i] != str2[i])
	return 0;
    return 1;
  }
public:
  vector<string> solve(vector<string> rows, vector<string> cols) {
    R = (int) rows.size();
    C = (int) rows[0].size();
    vector<vector<int> > result;
    vector<int> res(C, -1);
    for (int i = 0; i < C; i++) {
      string cand("");
      for (int j = 0; j < R; j++)
	cand += rows[j][i];
      vector<int> tmp;
      for (int j = 0; j < C; j++)
	if (match(cand, cols[j])) 
	  tmp.push_back(j);
      result.push_back(tmp);
    }
    vector<bool> visit(C, 0);
    for (int i = 0; i < C; i++)

    return rows;
  }
};

int main() {
  return 0;
}
