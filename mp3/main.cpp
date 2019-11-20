#include "List.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

using namespace cs225;

int main() {

  List<int> testList;
//  List<int> secondList;
  for (int i = 0; i < 10; i++) {
    testList.insertBack(rand() % 100);
//    secondList.insertBack(i+2);
  }
  testList.print(std::cout);
  cout << endl;
  // secondList.print(std::cout);
  // cout << endl;
  testList.mergesort(&testList.front(), 10);
  testList.print(std::cout);
  cout << endl;
  // secondList.print(std::cout);
  // cout << endl;

  return 0;
}
