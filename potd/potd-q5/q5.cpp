#include "Food.h"

void increase_quantity(Food *f) {
    f->set_quantity(f->get_quantity() + 1);
}
