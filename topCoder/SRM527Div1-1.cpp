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

class P8XGraphBuilder {
public:
  int solve(vector<int> s) {
    int N = (int) s.size() + 1;
    // int res = N - 2;
    vector<int> dp(N, 0);
    dp[1] = s[1] - s[0];
    for (int i = 2; i <= N - 2; i++) {
      int maxw = - (1 << 16);;
      for (int j = 1; j <= i; j++) {
	if (dp[j] + dp[i - j] > maxw)
	  maxw = dp[j] + dp[i - j];
	dp[i] = max(maxw, s[i] - s[0]);
      }
    }
    return dp[N - 2] + N * s[0];
  }
};

int main() {
  int vec[] = {5, 0, 0};
  vector<int> input(vec, vec + sizeof(vec) / sizeof(int));
  P8XGraphBuilder test;
  cout << test.solve(input) << endl;
  return 0;
}
