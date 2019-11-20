#include "Bar.h"
#include <string>
#include <iostream>

using namespace potd;
using namespace std;

Bar::Bar(string name) {
    f_ = new Foo(name);
}

Bar::Bar(const Bar & that) {
    f_ = new Foo(*(that.f_));
}

Bar & Bar::operator=(const potd::Bar & that) {
    delete f_;
    f_ = new Foo(*(that.f_));
    return *this;
}

Bar::~Bar() {
    delete f_;
}

string Bar::get_name() {
    return f_->get_name();
}