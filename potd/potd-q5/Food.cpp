#include "Food.h"
#include <string>

using namespace std;

string Food::get_name() {
    return name_;
}

void Food::set_name(string name) {
    name_ = name;
}

int Food::get_quantity() {
    return quantity_;
}

void Food::set_quantity(int quantity) {
    quantity_ = quantity;
}