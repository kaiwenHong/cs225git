#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>

using std::string;

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */

string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string result = "";
    HuffmanNode * curr = huffmanTree;
    for (const char& c : binaryString) {
      if (c == '0') curr = curr->left_;
      if (c == '1') curr = curr->right_;
      if (!curr->left_ && !curr->right_) {
        result += curr->char_;
        curr = huffmanTree;
      }
    }
    return result;
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */

string getChar(char currChar, string charString, HuffmanNode* curr) {
  if (!curr) return "";
  if (!curr->left_ && !curr->right_) {
    if (curr->char_ == currChar) return charString;
    return "";
  }
  string left = curr->left_ ? getChar(currChar, charString + "0", curr->left_) : "";
  string right = curr->right_ ? getChar(currChar, charString + "1", curr->right_) : "";
  if (left != "") return left;
  if (right != "") return right;
  return "";
}

string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string result = "";
    for (const char& c : charString) {
      result += getChar(c, "", huffmanTree);
    }
    return result;
}
