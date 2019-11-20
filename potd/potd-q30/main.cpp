#include <iostream>
#include "HuffmanNode.h"
#include "HuffmanUtils.h"
using namespace std;

int main() {
  HuffmanNode n[26];

  n[0].left_ = n+1;
  n[0].right_ = n+2;
  n[1].left_ = n+3;
  n[1].right_ = n+4;
  n[4].left_ = n+5;
  n[5].char_ = '.';
  n[4].right_ = n+6;
  n[6].left_ = n+7;
  n[7].left_ = n+8;
  n[7].right_ = n+9;
  n[8].char_ = 'S';
  n[9].char_ = '2';
  n[3].left_ = n+10;
  n[3].right_ = n+11;
  n[10].left_ = n+12;
  n[10].right_ = n+13;
  n[11].left_ = n+14;
  n[11].right_ = n+15;
  n[12].char_ = 'L';
  n[13].char_ = '5';
  n[14].char_ = 'V';
  n[15].char_ = 'Y';
  n[2].left_ = n+16;
  n[2].right_ = n+17;
  n[16].char_ = ' ';
  n[17].left_ = n+18;
  n[17].right_ = n+19;
  n[18].left_ = n+20;
  n[18].right_ = n+21;
  n[20].char_ = 'I';
  n[21].char_ = 'O';
  n[19].left_ = n+22;
  n[19].right_ = n+23;
  n[23].char_ = 'E';
  n[22].left_ = n+24;
  n[22].right_ = n+25;
  n[24].char_ = 'C';
  n[25].char_ = 'D';

  string binary_str = "1100100000110100101111101110001100100110101101000101010001111110110010110010111011101010";
  string expected_str = "I LOVE CS 225. YES I DO.";

  cout << "Given String: " << binaryToString(binary_str, n) << endl;
  cout << "Expected String: " << expected_str << endl;
  cout << "Given Binary: " << stringToBinary(expected_str, n) << endl;
  cout << "Expected Binary: " << binary_str << endl;

  return 0;
}
