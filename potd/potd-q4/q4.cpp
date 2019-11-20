#include <iostream>
#include "Circle.h"

using namespace std;

void pass_by_value(Circle c) {
    cout<<"In pass_by_value, the memory address of c is: "<<(&c)<<endl;
}

void pass_by_pointer(Circle* c){
    cout<<"In pass_by_pointer, the memory address of c is: "<<(c)<<endl;
}    

void pass_by_ref(Circle& c) {
    cout<<"In pass_by_ref, the memory address of c is: "<<(&c)<<endl;
}
