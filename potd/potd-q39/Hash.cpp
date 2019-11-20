#include <vector>
#include <string>
#include "Hash.h"

using namespace std;

int hashFunction(string s, int M) {
   // Your Code Here
   //hash function to sum up the ASCII characters of the letters of the string
   int sum = 0;
   for (char c : s) sum += c;
   return sum % M;
 }

int countCollisions (int M, vector<string> inputs) {
	int collisions = 0;
	// Your Code Here
  vector<int> sum;
  for (string s : inputs) {
    for (int i : sum) {
      if (hashFunction(s, M) == i) {
        collisions++;
        break;
      }
    }
    sum.push_back(hashFunction(s, M));
  }
	return collisions;
}
