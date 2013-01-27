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

class Poetry {
  bool isVowal(char c, bool end) {
    if (c == 'a' || c == 'e' || c == 'i' ||
	c == 'o' || c == 'u' || (c == 'y' && !end))
      return 1;
    return 0;
  }
  string getVowal(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    int len = (int)str.size();
    string ret = "";
    bool vowed = 0;
    while(str[len - 1] == ' ') len--;
    for (int i = len - 1; i >= 0; i--) {
      if (isVowal(str[i], i == len - 1) && !vowed) {
	vowed = 1;
      } 
      if (!isVowal(str[i], i == len - 1) && vowed) {
	break;
      }
      ret = str[i] + ret;
    }
    if (ret[0] == 'y') ret = ret.substr(1);
    return ret;
  }
  bool isEmpty(string& str) {
    for (unsigned i = 0; i < str.size(); i++)
      if (str[i] != ' ') return 0;
    return 1;
  }
public:
  string rhymeScheme(vector<string> poem) {
    char current = 'a';
    string ret = "";
    map<string, char> rhy;
    for (unsigned i = 0; i < poem.size(); i++) {
      string str = getVowal(poem[i]);
      if (isEmpty(str)) {
	ret += ' ';
	continue;
      }
      if (rhy.find(str) == rhy.end()) {
	rhy[str] = current++;
	if (current > 'z') current = 'A';
      }
      ret += rhy[str];
    }
    return ret;
  }
};

int main() {
  vector<string> test;
  string tmp = "I hope this problem";
  test.push_back(tmp);
  tmp = "            ";
  test.push_back(tmp);
  tmp = "           all";
  test.push_back(tmp);
  Poetry p;
  cout << p.rhymeScheme(test) << endl;;
  return 0;
}
