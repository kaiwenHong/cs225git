EXENAME = main

CXX = clang++
CXXFLAGS = -std=c++11 -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): potd.h potd.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp potd.o -o $(EXENAME)

potd.o: potd.h potd.cpp
	$(CXX) $(CXXFLAGS) -c potd.cpp

.PHONY: clean
clean:
	rm -f *.o $(EXENAME)
