// Animal.cpp
#include <iostream>
#include <string>
#include "Animal.h"

using namespace std;

void Animal::setFood(string nu_food) {
    food_ = nu_food;
}

string Animal::getFood() {
    return food_;
}

void Animal::setType(string nu_type) {
    type_ = nu_type;
}

string Animal::getType() {
    return type_;
}

string Animal::print() {
    return "I am a " + type_;
};

Animal::Animal() : type_("cat"), food_("fish") { }

Animal::Animal(string type, string food) : type_(type), food_(food) { }
