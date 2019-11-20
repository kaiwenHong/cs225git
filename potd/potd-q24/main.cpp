#include <iostream>
#include <cstdlib>
#include "Memory.h"

using namespace std;

int main() {
  // Create a memory
  Memory memory = Memory();

  // Print the statistics
  memory.printStats();

  // Allocate 0x4000 bits of memory
  std::cout << "Allocating 4 chunks of memory..." << '\n';
  size_t size = 0x4000;
  unsigned address1 = memory.allocate(size);
  unsigned address2 = memory.allocate(size);
  unsigned address3 = memory.allocate(size);
  unsigned address4 = memory.allocate(size);

  // Print statistics
  memory.printStats();

  std::cout << "Freeing the second chunk..." << '\n';
  memory.free(address2);
  memory.printStats();

  std::cout << "Freeing the third chunk..." << '\n';
  memory.free(address3);
  memory.printStats();

  std::cout << "Defragmenting..." << '\n';
  memory.defragment();
  memory.printStats();

  return 0;
}
