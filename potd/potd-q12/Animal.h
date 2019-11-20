#pragma once
#include <string>

using namespace std;

class Animal {
  private:
    string type_;
  public:
    string food_;
    string getType();
    void setType(string);
    string getFood();
    void setFood(string);
    string print();
    Animal();
    Animal(string, string);
};
