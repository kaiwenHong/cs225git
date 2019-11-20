#ifndef _HUFFNODE_H
#define _HUFFNODE_H

#include <cstddef>
#include <iostream>
using namespace std;

class HuffmanNode {
    public:
        HuffmanNode *left_;
        HuffmanNode *right_;
        char char_;
        HuffmanNode();
};

#endif
