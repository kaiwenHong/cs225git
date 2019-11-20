#include "potd.h"
#include <iostream>
using namespace std;

int main() {
  // Test 1: An empty list
  Node * head = NULL;
  cout << stringList(head) << endl;

  // Test 2: A list with exactly one node
  Node one = {1, NULL};
  cout << stringList(&one) << endl;

  // Test 3: A list with more than one node
  Node more = {2, &one};
  cout << stringList(&more) << endl;

  return 0;
}
