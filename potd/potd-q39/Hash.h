#ifndef HASH_H
#define HASH_H

#include <vector>
#include <string>
#include "Hash.h"

int hashFunction(std::string s, int M);

int countCollisions (int M, std::vector<std::string> inputs);

#endif
