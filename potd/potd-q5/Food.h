#pragma once
#include <string>

using namespace std;

class Food {
  private:
    string name_;
    int quantity_;

  public:
    string get_name();
    void set_name(string name);
    int get_quantity();
    void set_quantity(int quantity);
};