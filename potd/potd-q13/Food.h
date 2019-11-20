#ifndef _FOOD_H
#define _FOOD_H

#include <iostream>
#include <string>
using namespace std;

class Food {
  private:
    string name_;
    int quantity_;
  public:
    Food();
    void setName(string newName);
    void setQuantity(int newQuantity);
    string getName() const;
    int getQuantity() const;
    bool operator>(const Food & that) const;
};

#endif
