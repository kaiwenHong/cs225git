#include <iostream>
#include <string>
using namespace std;

#include "Food.h"
#include "potd.h"

int main() {
    Food apples, oranges, greater;
    apples.setName("apples");
    apples.setQuantity(5);
    oranges.setName("oranges");
    oranges.setQuantity(3);
    greater = more<Food>(apples, oranges);
    cout << "We have more " << greater.getName() << "." << endl;
    return 0;
}
