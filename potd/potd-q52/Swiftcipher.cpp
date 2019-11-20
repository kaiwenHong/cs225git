#include "Swiftcipher.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

/* Swift Cipher: Frequency of words in a file corresponds to its location in the decrypted sentence */
string decipherer(string filename) {

	string input;
	string line;
	ifstream myfile(filename);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
		 input += line;
		 input += " ";
		}
		input.pop_back();
		myfile.close();
	}

	map <string, int> word_frequency;
	string word= "";
	for (size_t i = 0; i <= input.length(); i++) {
 		if (input[i] != ' ' && i < input.length()){
    	word = word + input[i];
    } else if (word_frequency.count(word) == 0) {
      word_frequency[word] = 0;
      word = "";
  	} else {
    	word_frequency[word]++;
    	word = "";
		}
	}

	string result = "";
	for (int i = 0; i < 50; i++) {
		for (auto it = word_frequency.begin(); it != word_frequency.end(); it++) {
			if (it->second == i) {
				result += it->first;
				result += ' ';
				break;
			}
		}
	}

	result.pop_back();
	return result;

}
