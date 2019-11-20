#include <iostream>
#include <string>
using namespace std;

#include "Square.h"

Square::Square() {
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}

void Square::setName(string newName) {
  name = newName;
}

void Square::setLength(double newVal) {
  *lengthptr = newVal;
}

string Square::getName() const {
  return name;
}

double Square::getLength() const {
  return *lengthptr;
}

Square::Square(const Square & other) {
    name = other.getName();
    lengthptr = new double;
    *lengthptr = other.getLength();
}

Square::~Square() {
    delete lengthptr;
}

Square & Square::operator=(const Square & other) {
  name = other.getName();
  delete lengthptr;
  lengthptr = new double;
  *lengthptr = other.getLength();
  return *this;
}

Square Square::operator+(const Square & other) {
  Square *result = new Square();
  result->setName(name+other.name);
  result->setLength(*lengthptr+*(other.lengthptr));
  return *result;
}
