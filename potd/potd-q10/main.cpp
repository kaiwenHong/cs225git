#include <iostream>
#include "Base.h"
#include "Derived.h"

using namespace std;

int main() {
    Base *x1 = new Base();
    Base *x2 = new Derived();
    Derived *y1 = new Derived();

    cout << x1->foo() << endl;
    cout << x2->foo() << endl;
    cout << y1->foo() << endl;
    cout << x1->bar() << endl;
    cout << x2->bar() << endl;
    cout << y1->bar() << endl;

    delete x1;
    delete x2;
    delete y1;
}
