

#ifndef WEIGHTED_UTILITY
#define WEIGHTED_UTILITY

#include <string>
#include <vector>

using namespace std;

int bit2int(string value, vector<int> w, int bit) {
  int res = 0;

  for (int i = 0; i < bit; ++i)
    res += (value[i] - '0') * w[i];

  return res;
}

#endif // ifndef NUMERIC_UTILITY
