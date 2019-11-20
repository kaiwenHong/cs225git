#include <string>
#include <iostream>
#include "Hash.h"

int main()
{
    std::string s = "arbitrary";
	for (int i = 51; i <= 100; ++i)
	{	
        std::cout<<"Goodness of hash Bernstein hash function for \""<<s<<"\" with range="<<i<<" is: "<<hash_goodness(s,i)<< std::endl;	
	}	

}
