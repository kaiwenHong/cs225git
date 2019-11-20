#include <string>
#include <iostream>
#include "Animal.h"

using namespace std;

Animal::Animal() {
  type_ = "cat";
  food_ = "fish";
}

Animal::Animal(string newType, string newFood) {
  type_ = newType;
  food_ = newFood;
}

string Animal::getType() {
  return type_;
}
void Animal::setType(string newType) {
  type_ = newType;
}

string Animal::getFood() {
  return food_;
}

void Animal::setFood(string newFood) {
  food_ = newFood;
}

string Animal::print() {
  return "I am a " + getType() + ".";
}
