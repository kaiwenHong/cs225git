#include <iostream>
#include <string>
#include "Food.h"
#include "q5.h"

using namespace std;

int main() {
    Food fruit;
    fruit.set_name("apples");
    fruit.set_quantity(5);
    
    cout << "You have " << fruit.get_quantity() << " " << fruit.get_name() << endl;
  
    Food *ptr = &fruit;
    increase_quantity(ptr);
    
    cout << "You have " << fruit.get_quantity() << " " << fruit.get_name() << endl;

    return 0;

}
