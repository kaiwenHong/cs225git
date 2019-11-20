EXENAME = main

CXX = clang++
CXXFLAGS = -std=c++0x -g -O0 -Wall -Wextra

all : $(EXENAME)

$(EXENAME): main.cpp Foo.o Foo.h Bar.o Bar.h
	$(CXX) $(CXXFLAGS) main.cpp Foo.cpp Bar.cpp -o $(EXENAME)

Foo.o: Foo.cpp Foo.h
	$(CXX) $(CXXFLAGS) -c Foo.cpp

Bar.o: Foo.h Bar.h Bar.cpp
	$(CXX) $(CXXFLAGS) -c Bar.cpp

.PHONY: clean
clean:
	rm -f -r *.o *.dSYM $(EXENAME)
