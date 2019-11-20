#include <iostream>
#include "Node.h"

using namespace std;

void printList(Node *head) {
  if (head == NULL) {
    cout << "Empty list" << endl;
    return;
  }

  Node *temp = head;
  int count = 0;
  while(temp != NULL) {
    cout << "Node " << count << ": " << temp ->data_ << endl;
    count++;
    temp = temp->next_;
  }
}

int main() {
  // Example #1
  Node n_0, n_1, n_2, n_22, n_3, n_4;
  n_0.data_ = 0;
  n_1.data_ = 1;
  n_2.data_ = 2;
  n_22.data_ = 1;
  n_3.data_ = 2;
  n_4.data_ = 3;

  n_0.next_ = &n_1;
  n_1.next_ = &n_2;
  n_2.next_ = NULL;

  n_22.next_ = &n_3;
  n_3.next_ = &n_4;
  n_4.next_ = NULL;

  cout<<"First List:"<<endl;
  printList(&n_0);
  cout<<"Second List:"<<endl;
  printList(&n_22);

  Node *r1 = listSymmetricDifference(&n_0, &n_22);
  cout<<"Symmetric Difference"<<endl;
  printList(r1);
  cout<<endl;


  // Example #2
  Node p00, p01, p02, p03, p10, p11, p12, p13, p14, p15, p16;

  // List 1: 0 2 2 2
  p00.data_ = 0; p00.next_ = &p01;
  p01.data_ = 2; p01.next_ = &p02;
  p02.data_ = 2; p02.next_ = &p03;
  p03.data_ = 2; p03.next_ = NULL;

  // List 2: 0 0 0 4
  p10.data_ = 0; p10.next_ = &p11;
  p11.data_ = 0; p11.next_ = &p12;
  p12.data_ = 0; p12.next_ = &p13;
  p13.data_ = 2; p13.next_ = &p14;
  p14.data_ = 2; p14.next_ = &p15;
  p15.data_ = 2; p15.next_ = &p16;
  p16.data_ = 4; p16.next_ = NULL;

  cout<<"First List:"<<endl;
  printList(&p00);
  cout<<"Second List:"<<endl;
  printList(&p10);

  Node *r2 = listSymmetricDifference(&p00, &p10);
  cout<<"Symmetric Difference"<<endl;
  printList(r2);
  cout<<endl;

  return 0;
}
