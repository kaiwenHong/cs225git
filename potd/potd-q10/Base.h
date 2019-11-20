#pragma once
#include <string>

using namespace std;

class Base {
  public:
    string foo();
    virtual string bar();
    virtual ~Base() {}
};
