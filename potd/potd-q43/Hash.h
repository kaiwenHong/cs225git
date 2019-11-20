#ifndef _HASH_H
#define _HASH_H

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

unsigned long bernstein(std::string str, int M);
float hash_goodness(std::string str, int M);

#endif
