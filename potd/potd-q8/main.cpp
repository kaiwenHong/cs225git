#include <iostream>
using namespace std;

#include "Queen.h"
#include "Piece.h"

void printPiece(Piece *p) {
  cout << "In printPiece, printType() of the same memory address is: "
       << p->getType() << endl;
}

int main() {
  Queen *q = new Queen();

  cout << "In main, printType() of Queen *q is: "
       << q->getType() << endl;

  printPiece(q);

  delete q;  // Don't forget to free your memory! :)
  return 0;
}
