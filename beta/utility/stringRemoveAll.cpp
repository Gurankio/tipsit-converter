/*
 * String Remove All
 * https://stackoverflow.com/questions/32435003
 */

#ifndef STRING_REMOVE_ALL
#define STRING_REMOVE_ALL

#include <string>

using namespace std;

void stringRemoveAll(string& s, string& p) {
  string::size_type n = p.length();

  for (string::size_type i = s.find(p);
       i != string::npos;
       i = s.find(p))
    s.erase(i, n);
}

#endif
