#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


vector<string> topThree(string filename) {
    string line;
    ifstream infile (filename);
    vector<string> ret;
    if (infile.is_open()) {
        while (getline(infile, line)) {
            // do things
        }
    }
    infile.close();
    return ret;
}

