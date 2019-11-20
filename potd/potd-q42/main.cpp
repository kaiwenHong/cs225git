#include <iostream>
#include "potd.cpp"

using namespace std;

int main() {
    unordered_map<string, int> mapA({{"a", 1}, {"b", 2}, {"c", 3}});
    unordered_map<string, int> mapB({{"a", 4}, {"b", 5}, {"d", 6}});

    unordered_map<string, int> common = common_elems(mapA, mapB);

    // check your outputs here
    std::cout << "Return map contains:";
    for ( auto it = common.begin(); it != common.end(); ++it )
      cout << " " << it->first << ":" << it->second << endl;

    std::cout << "Original mapA contains:";
    for ( auto it = mapA.begin(); it != mapA.end(); ++it )
      cout << " " << it->first << ":" << it->second << endl;

      std::cout << "Original mapB contains:";
      for ( auto it = mapB.begin(); it != mapB.end(); ++it )
        cout << " " << it->first << ":" << it->second << endl;
}
