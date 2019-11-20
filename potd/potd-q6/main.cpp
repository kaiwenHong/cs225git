#include <iostream>
#include "potd.h"

using namespace std;
using namespace potd;

int main() {
    int x[5] = {1,2,3,4,-1};

    for(int i=0; x[i] != -1; i++)
        cout << x[i] << " ";
    cout << endl;

    int *y = raise(x);

    for(int i=0; y[i] != -1; i++)
        cout << y[i] << " ";
    cout << endl;
}
