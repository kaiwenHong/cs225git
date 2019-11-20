#pragma once
#include <string>
#include "Base.h"

class Derived : public Base {
  public:
    string foo();
    virtual string bar();
    virtual ~Derived() {}
};
