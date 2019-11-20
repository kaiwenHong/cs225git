#include "potd.h"
#include <iostream>

using namespace std;

string stringList(Node *head) {

  string result = "Empty list";

  for (int i = 0; head != nullptr; i++) {
    if (i > 0) result += " -> ";
    else result = "";
    result += "Node " + to_string(i) + ": " + to_string(head->data_);
    head = head->next_;
  }

  return result;

}
