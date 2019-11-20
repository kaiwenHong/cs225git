#include "potd.h"
#include <math.h>
#include <iostream>

int *potd::raise(int *arr) {
    
    int size = 0;
    
    for(int i = 0; arr[i] != -1; i++)
        size++;
         
    int * return_array = new int[size];
    
    for(int i = 0; i < size - 1; i++)
        return_array[i] = pow(arr[i], arr[i + 1]);
    
    return_array[size - 1] = arr[size - 1];
    return_array[size] = -1;
    
    delete[] return_array;
    
    return return_array;

}