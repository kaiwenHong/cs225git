#include <string>
#include <iostream>
#include<algorithm>

#include "Hash.h"

int main()
{
    std::string s = "POTS";
	int M = 13;
    std::cout<<"Bernstein hash of "<<s<<" with range "<<M<<" is: "<<bernstein(s, M)<<'\n'; 	
    std::cout<<"Bernstein hash of the reverse of "<<s<<" - " <<reverse(s)<<" - with range "<<M<<", is: "<<bernstein(reverse(s), M)<<'\n';
}
