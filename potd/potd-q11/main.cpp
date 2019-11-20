#include <iostream>
#include <string>
#include "Square.h"

using namespace std;

int main(){
    Square a;
    Square b = a;
    Square c = a + b;
    cout << "Square a " << a.getName() << " " << a.getLength() << endl;
    cout << "Square b " << b.getName() << " " << b.getLength() << endl;
    cout << "Square c " << c.getName() << " " << c.getLength() << endl;
    return 0;
}
