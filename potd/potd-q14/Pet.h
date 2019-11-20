#pragma once
#include "Animal.h"
#include <string>

using namespace std;

class Pet : public Animal {

public:
  Pet();
  Pet(string, string, string, string);
  string print();
  string getName();
  void setName(string);
  string getOwnerName();
  void setOwnerName(string);

private:
  string name_;
  string owner_name_;

};
