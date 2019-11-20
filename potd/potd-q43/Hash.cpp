#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "Hash.h"

using namespace std;

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	for (int i = 0; i < (int) str.length(); ++i)
	{
		b_hash = b_hash * 33 + str[i];
	}
	return b_hash % M;
}

float hash_goodness(std::string str, int M)
{
//  std::vector<unsigned long>* array = new std::vector<unsigned long>(M);	// Hint: This comes in handy
	float permutation_count = 0;
	float goodness = 0;
	map<unsigned long, int> frequency;
	do {
		if (permutation_count == M) break;
		// Code for computing the hash and updating the array
		unsigned long hash = bernstein(str, M);
		// for (size_t i = 0; i < array->size(); i++) {
		// 	if (hash == array->at(i)) {
		// 		goodness++;
		// 		break;
		// 	}
		// }
		// permutation_count++;
		// array->push_back(hash);
		permutation_count++;
		frequency[hash]++;
	} while(std::next_permutation(str.begin(), str.end()));

	//Code for determining goodness
	for (auto it : frequency) {
		if (it.second != 1) goodness += (it.second - 1);
	}

	return goodness / M;
}
