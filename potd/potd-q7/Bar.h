#pragma once
#include "Foo.h"
#include <string>

namespace potd {
    class Bar {
        
        private:
        Foo * f_;
        
        public:
        Bar(string name);
        Bar(const Bar &);
        Bar & operator=(const Bar &);
        ~Bar();
        string get_name();
        
    };   
}