#ifndef _HUFFUTILS_H
#define _HUFFUTILS_H

#include <string>

using std::string;

string stringToBinary(string charString, HuffmanNode* huffmanTree);
string binaryToString(string binaryString, HuffmanNode* huffmanTree);

#endif
