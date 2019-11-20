EXENAME = main
OBJS = main.o HuffmanUtils.o HuffmanNode.o

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x -g

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp
	$(CXX) $< $(CXXFLAGS)

HuffmanUtils.o: HuffmanUtils.cpp HuffmanUtils.h
	$(CXX) $< $(CXXFLAGS)

HuffmanNode.o: HuffmanNode.cpp HuffmanNode.h
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o $(EXENAME)
