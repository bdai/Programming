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

class CoinReversing {
  long long nchoosek(int n, int k) {
    if (k > n / 2.0) k = n - k;
    if (k > n) return 0;
    if (k == 0) return 1;
    long long ret = 1;
    for (int i = k + 1; i <= n; i++)
      ret *= i;
    for (int i = 2; i <= n - k; i++)
      ret /= i;
    return ret;
  }
public:
  double expectedHeads(int N, vector<int> a) {
    vector<double> prob(N + 1, 0);
    prob[N] = 1;
    for (int i = 0; i < (int) a.size(); i++) {
      vector<double> current(N + 1, 0);
      int num = a[i];
      for (int head = 0; head < N + 1; head++) {
	if (prob[head] > 0) {
	  int tail = N - head;
	  for (int k = 0; k <= num; k++) {
	    long double p = nchoosek(head, k);
	    p /= (long double) nchoosek(N, num);
	    p *= nchoosek(tail, num - k);
	    int newH = head - k + num - k;
	    current[newH] += p;
	  }
	}
      }
      prob = current;
    }
    double ret = 0;
    for (int i = 0; i < N + 1; i++)
      ret += i * prob[i];
    return ret;
  }
};

int main() {
  int myint[] = {2, 2};
  vector<int> vec(myint, myint + sizeof(myint) / sizeof(int));
  CoinReversing test;
  cout << test.expectedHeads(3, vec) << endl;
  return 0;
}
