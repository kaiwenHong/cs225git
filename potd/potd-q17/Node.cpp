#include "Node.h"

using namespace std;

void sortList(Node **head) {
  bool unsorted = true;
  while(unsorted) {
    unsorted = false;
    Node *curr = *head;
    Node *prev = nullptr;
    Node *prev2 = nullptr;
    while(curr != nullptr) {
      if (prev == *head && prev->data_ > curr->data_) {
        prev->next_ = curr->next_;
        curr->next_ = prev;
        *head = curr;
        unsorted = true;
      } else if (prev2 != nullptr && prev != nullptr && prev->data_ > curr->data_) {
        prev->next_ = curr->next_;
        curr->next_ = prev;
        prev2->next_ = curr;
        unsorted = true;
      }
      prev2 = prev;
      prev = curr;
      curr = curr->next_;
    }
  }
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
