#include "Thing.h"
#include <string>

using namespace potd;
using namespace std;

Thing::Thing(int size) {
    props_max_ = size;
    props_ct_ = 0;
    properties_ = new string[props_max_];
    values_ = new string[props_max_];
}

Thing::Thing(const Thing & thatThing){
    props_max_ = thatThing.props_max_;
    props_ct_ = thatThing.props_ct_;
    properties_ = new string[props_max_];
    values_ = new string[props_max_];
    _copy(thatThing);
}

Thing & Thing::operator=(const Thing & thatThing) {
    _destroy();
    props_max_ = thatThing.props_max_;
    props_ct_ = thatThing.props_ct_;
    properties_ = new string[props_max_];
    values_ = new string[props_max_];
    _copy(thatThing);
    return *this;
}

int Thing::set_property(string name, string value) {
    for (int i = 0; i < props_ct_; i++) {
      if (properties_[i] == name) {
        values_[i] = value;
        return i;
      }
    }
    if (props_ct_ < props_max_) {
      properties_[props_ct_] = name;
      values_[props_ct_] = value;
      props_ct_++;
      return props_ct_ - 1;
    }
    return -1;
}

string Thing::get_property(string name) {
    for (int i = 0; i < props_ct_; i++) {
      if (properties_[i] == name) {
        return values_[i];
      }
    }
    return "";
}

void Thing::_copy(const Thing & anotherThing) {
    for (int i = 0; i < props_max_; i++) {
      properties_[i] = anotherThing.properties_[i];
      values_[i] = anotherThing.values_[i];
    }
}

void Thing::_destroy() {
    delete[] properties_;
    delete[] values_;
}

Thing::~Thing() {
    _destroy();
}
