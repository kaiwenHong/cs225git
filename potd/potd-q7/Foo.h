#ifndef FOO_H
#define FOO_H

#include <string>

using namespace std;

namespace potd {
    class Foo {
        public:
            Foo(string);
            Foo(const Foo &);
            Foo & operator=(const Foo &);
            ~Foo();
            static int get_count();
            string get_name();
        private:
            static int count_;
            string name_;
    };
}

#endif
