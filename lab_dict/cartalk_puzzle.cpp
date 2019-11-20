/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>
#include <iostream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of (string, string, string) tuples
 * Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<std::tuple<std::string, std::string, std::string>> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    vector<std::tuple<std::string, std::string, std::string>> ret;

    /* Your code goes here! */
    vector<std::string> words;
    string line;
    ifstream myfile(word_list_fname);
    if (myfile.is_open()) {
      while (getline(myfile, line)) {
        words.push_back(line);
      }
      myfile.close();
    }

    for (size_t i = 0; i < words.size(); i++) {
      std::string first_removed = words[i].substr(1, words[i].size());
      std::string word_backup = words[i]; //Well apparently erase will change the original string :(
      std::string second_removed = word_backup.erase(1, 1);
      if (d.homophones(words[i], first_removed) && d.homophones(words[i], second_removed)) {
        ret.push_back(std::make_tuple(words[i], first_removed, second_removed));
      }
    }

    return ret;
}
