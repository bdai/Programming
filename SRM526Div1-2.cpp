#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <list>
using namespace std;

class PrimeCompositeGame {
  vector<int> isPrime;
  vector<int> dp1, dp2;
  int kk;
  int checkPrime(int num) {
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= (int) sqrt(num); i += 2)
      if (num % i == 0)
	return 0;
    return 1;
  }
  int checkMe(int num) {
    for (int i = max(0, num - kk); i < num; i++)
      if (isPrime[i] == 1 && dp2[i] <= 0)
	return 1 - dp2[i];
    for (int i = num - 1; i >= max(0, num - kk); i--)
      if (isPrime[i] == 1)
	return -1 - dp2[i];
    return 0;
  }
 int checkDr(int num) {
    for (int i = max(0, num - kk); i < num; i++)
      if (isPrime[i] == 0 && dp1[i] <= 0)
	return 1 - dp1[i];
    for (int i = num - 1; i >= max(0, num - kk); i--)
      if (isPrime[i] == 0)
	return -1 - dp1[i];
    return 0;
  }
public:
  int theOutcome(int N, int K) {
    isPrime.resize(N + 1, 0);
    isPrime[0] = isPrime[1] = -1;
    kk = K;
    for (int i = 2; i <= N; i++) 
      isPrime[i] = checkPrime(i);
    dp1 = vector<int> (N + 1, 0);
    dp2 = vector<int> (N + 1, 0);
    dp1[3] = 1;
    for (int i = 4; i <= N; i++) {
      dp1[i] = checkMe(i);
      dp2[i] = checkDr(i);
    }
    return dp1[N];
  }
};

int main() {
  PrimeCompositeGame test;
  int a, b;
  cin >> a >> b;
  cout << test.theOutcome(a, b) << endl;
  return 0;
}
