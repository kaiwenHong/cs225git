// main.cpp

#include "Pet.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Pet p("cat","fish","Garfield","John");

    cout << Animal(p).print() << endl;
    cout << p.print() << endl;
}
