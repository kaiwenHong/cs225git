#include <iostream>
#include <vector>
#include <string>
#include "Hash.h"

using namespace std;

int main() {
    vector<string> inputs {
        "Fourth Doctor",
        "Harry Sullivan",
        "Leela",
        "K9",
        "Romana I",
        "Romana II",
        "Adric",
        "Tegan Jovanka",
        "Nyssa of Traken",
        "Ninth Doctor",
        "Rose Tyler",
        "Adam Mitchell",
        "Jack Harkness",
        "Tenth Doctor",
        "Mickey Smith",
        "Donna Noble",
        "Martha Jones",
        "Astrid Peth",
        "Wilfred Mott",
        "Eleventh Doctor",
        "Amy Pond",
        "Rory Williams",
        "River Song",
        "Craig Owens",
        "John Riddell",
        "Queen Nefertiti of Egypt",
        "Clara Oswald" };

 	for (int i=1; i<=11; i++) {
 		cout<< "performing hash on the inputs with array size " << to_string(i) << " =>\t"<< to_string(countCollisions(i, inputs)) << endl;
 	}
 	return 0;
 }
