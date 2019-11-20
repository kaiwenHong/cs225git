#include <iostream>
#include "hello.h"

std::string hello() {
    
    unsigned your_age = 19;
    std::string your_name = "Kevin";
    
    std::string return_msg;
        
    return_msg = "Hello world! My name is " + your_name + " and I am " + std::to_string(your_age) + " years old.";
    
    return return_msg;
    
}
