#include <iostream>
#include "Foo.h"
#include "Bar.h"

using namespace std;
using namespace potd;

int main() {
    Bar *b1, *b2, *b3;

    cout << "There are " << Foo::get_count() << " Foo's in the world." << endl;
    b1 = new Bar("aramis");
    cout << "There are " << Foo::get_count() << " Foo's in the world." << endl;
    b2 = new Bar(*b1);
    cout << "There are " << Foo::get_count() << " Foo's in the world." << endl;
    b3 = new Bar("porthos");
    cout << "There are " << Foo::get_count() << " Foo's in the world." << endl;
    cout << "b1 is " << b1->get_name() << endl ;
    cout << "b2 is " << b2->get_name() << endl ;
    cout << "b3 is " << b3->get_name() << endl ;
    *b1 = *b3;
    *b2 = *b3;
    cout << "There are " << Foo::get_count() << " Foo's in the world." << endl;
    cout << "b1 is " << b1->get_name() << endl ;
    cout << "b2 is " << b2->get_name() << endl ;
    cout << "b3 is " << b3->get_name() << endl ;
    *b1 = *b3;
    *b2 = *b3;
    delete b1;
    cout << "There are " << Foo::get_count() << " Foo's in the world." << endl;
    delete b2;
    cout << "There are " << Foo::get_count() << " Foo's in the world." << endl;
    delete b3;
    cout << "There are " << Foo::get_count() << " Foo's in the world." << endl;
}
