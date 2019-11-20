#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "cs225/PNG.h"

using namespace std;

int main()
{
    // Function is in maze.cpp/h (base.png -> creative.png)
    SquareMaze m;
    m.makeMaze(102, 102);
    cs225::PNG* output = m.drawCreativeMaze();
    output->writeToFile("creative.png");
    delete output;

    return 0;
}
