#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node **head, Node *insert) {

  if (*head == NULL) {
    *head = insert;
    return;
  }

  if (insert->data_ <= (*head)->data_) {
    insert->next_ = *head;
    *head = insert;
    return;
  }

  Node *current = *head;

  while (current != NULL) {

    if (current->next_ == NULL) {
      current->next_ = insert;
      return;
    }

    if (insert->data_ >= current->data_ && insert->data_ <= current->next_->data_) {
      insert->next_ = current->next_;
      current->next_ = insert;
      return;
    }

    current = current->next_;

  }

}
