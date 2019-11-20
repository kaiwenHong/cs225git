EXENAME = main
OBJS = main.o OfficeHour.o Staffer.o Student.o

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

tests.o: tests.cpp catch.hpp
	$(CXX) $< $(CXXFLAGS)

OfficeHour.o: OfficeHour.cpp
	$(CXX) $< $(CXXFLAGS)

Staffer.o: Staffer.cpp
	$(CXX) $< $(CXXFLAGS)

Student.o: Student.cpp
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o $(EXENAME)
