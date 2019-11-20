#include "Foo.h"
#include <string>

using namespace potd;
using namespace std;

int Foo::count_ = 0;

Foo::Foo(string name) {
    this->name_ = name;
    Foo::count_++;
}

Foo::Foo(const Foo &that) {
    this->name_ = that.name_;
    Foo::count_++;
}

Foo::~Foo() {
    Foo::count_--;
}

Foo & Foo::operator=(const potd::Foo &that) {
    this->name_ = that.name_;
    Foo::count_++;
    return *this;
}

int Foo::get_count() {
    return Foo::count_;
}

string Foo::get_name() {
    return name_;
}
