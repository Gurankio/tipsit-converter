#ifndef MAP_DELETE_VALUE
#define MAP_DELETE_VALUE

#include <map>
#include <iterator>

using namespace std;

template<typename K, typename V>
int mapDeleteValue(map<K, V> & mapOfElemen, V value) {
  int totalDeletedElements = 0;
  auto it = mapOfElemen.begin();

  // Iterate through the map
  while (it != mapOfElemen.end()) {
    // Check if value of this entry matches with given value
    if (it->second == value) {
      totalDeletedElements++;
      // Erase the current element, erase() will return the
      // next iterator. So, don't need to increment
      it = mapOfElemen.erase(it);
    } else
      // Go to next entry in map
      it++;
  }
  return totalDeletedElements;
}

#endif // ifndef MAP_DELETE_VALUE
