#ifndef POTD_H
#define POTD_H

#include <string>

using namespace std;

struct Node {
    int data_;
    Node *next_;
};

void insertSorted(Node **head, Node *item);

#endif
