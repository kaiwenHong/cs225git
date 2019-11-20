#include <string>
#include "pet.h"

using namespace std;

Pet::Pet() {
    name = "Rover";
    birth_year = 2018;
    type = "dog";
    owner_name = "Wade";
}

Pet::Pet(string newPetName, int newBY, string newType, string newOwnerName) {
    name = newPetName;
    birth_year = newBY;
    type = newType;
    owner_name = newOwnerName;
}

void Pet::setName(string newName) {
  name = newName;
}

void Pet::setBY(int newBY) {
  birth_year = newBY;
}

void Pet::setType(string newType) {
  type = newType;
}

void Pet::setOwnerName(string newName) {
  owner_name = newName;
}

string Pet::getName() {
  return name;
}

int Pet::getBY() {
  return birth_year;
}

string Pet::getType() {
  return type;
}

string Pet::getOwnerName() {
  return owner_name;
}
