EXENAME = main

CXX = clang++
CXXFLAGS = -std=c++11 -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): main.cpp pet.h pet.o
	$(CXX) $(CXXFLAGS) main.cpp pet.o -o $(EXENAME)

pet.o: pet.h pet.cpp
	$(CXX) $(CXXFLAGS) -c pet.cpp

.PHONY: clean
clean:
	rm -f $(EXENAME)
