#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> common_elems(unordered_map<string, int> &mapA,
                                        unordered_map<string, int> &mapB) {

    // your code here
    unordered_map<string, int> result;
    auto it = mapB.begin();
    while (it != mapB.end()) {
      unordered_map<string, int>::const_iterator got = mapA.find(it->first);
      if (got != mapA.end()) {
          result.insert(make_pair(it->first, (it->second + got->second)));
          got = mapA.erase(got);
          it = mapB.erase(it);
          continue;
      }
      ++it;
    }
    return result;
}
