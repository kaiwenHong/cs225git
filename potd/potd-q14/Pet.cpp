#include "Pet.h"
#include "Animal.h"
#include <string>

using namespace std;

Pet::Pet() : Animal("cat", "fish"){
  name_ = "Fluffy";
  owner_name_ = "Cinda";
}

Pet::Pet(string type, string food, string name, string ownerName) : Animal(type, food){
  name_ = name;
  owner_name_ = ownerName;
}

string Pet::print() {
  return "My name is " + name_;
}

string Pet::getName() {
  return name_;
}

void Pet::setName(string name) {
  name_ = name;
}

string Pet::getOwnerName() {
  return owner_name_;
}

void Pet::setOwnerName(string ownerName) {
  owner_name_ = ownerName;
}
