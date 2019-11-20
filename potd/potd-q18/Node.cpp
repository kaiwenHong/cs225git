#include "Node.h"

using namespace std;

void mergeList(Node *first, Node *second) {
  while(first != nullptr && second != nullptr) {
    Node *next1 = first->next_;
    first->next_ = second;
    Node *next2 = second->next_;
    if(next1 != nullptr) second->next_ = next1;
    first = next1;
    second = next2;
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
