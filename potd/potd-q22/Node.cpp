#include "Node.h"

using namespace std;

bool isPresent (Node *head, int data) {
    Node *curr = head;
    while(curr != NULL) {
      if(curr->data_ == data) return true;
      curr = curr->next_;
    }
    return false;
}

Node *listIntersection(Node *first, Node *second) {
  Node *result = nullptr;
  Node *curr = nullptr;
  while(second != nullptr) {
    if(isPresent(first, second->data_) && !isPresent(result, second->data_)) {
      if(result == nullptr && curr == nullptr) {
        result = new Node();
        result->data_ = second->data_;
        result->next_ = nullptr;
        curr = result;
      } else {
        curr->next_ = new Node();
        curr = curr->next_;
        curr->data_ = second->data_;
        curr->next_ = nullptr;
      }
    }
    second = second->next_;
  }
  return result;
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
