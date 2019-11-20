/* Your code here! */
#pragma once
#include <vector>
#include "cs225/PNG.h"
#include "dsets.h" // Disjoint sets from 6.1
#include <stdlib.h>
#include <queue>
#include <assert.h>

enum { RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3 };
enum { NOWALL = 0, RIGHTWALL = 1, DOWNWALL = 2, BOTHWALLS = 3 };

class SquareMaze {

  public:
    SquareMaze();
    void makeMaze(int width, int height);
    bool canTravel(int x, int y, int dir) const;
    void setWall(int x, int y, int dir, bool exists);
    std::vector<int> solveMaze();
    cs225::PNG *drawMaze() const;
    cs225::PNG *drawMazeWithSolution();
    cs225::PNG *drawCreativeMaze();

  private:
    DisjointSets sets; // final tree
    vector<int> squares; // index is the square, value is walls
    int width;
    int height;
    int getIndex(int x, int y) const;
    int getX(int index) const;
    int getY(int index) const;
};
