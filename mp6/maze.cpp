/* Your code here! */
#include "maze.h"
#include <iostream>
using namespace std;
using namespace cs225;

SquareMaze::SquareMaze() {
  width = 0;
  height = 0;
}

void SquareMaze::makeMaze(int width, int height) {
  // resize maze
  this->width = width;
  this->height = height;
  squares.resize(width*height, BOTHWALLS);
  sets.addelements(width*height);

  while(sets.size(0) != width * height){ // while everything not in same set
    int rsquare = rand() % (width*height); // 0 to width*height-1
    int rwall = rand() % 2; // 0 (right) or 1 (down)
    if(rwall == 0){
      // on right perimeter or right square in same set
      if((rsquare+1)%width == 0 || sets.find(rsquare) == sets.find(rsquare+1)) continue;
      else{
        setWall(getX(rsquare), getY(rsquare), 0, false); // remove right wall
        sets.setunion(rsquare, rsquare+1); // union them into set
      }
    }
    else{ // rwall == 1
      // on lower perimeter or below square in same set
      if(rsquare+width >= width*height || sets.find(rsquare) == sets.find(rsquare+width)) continue;
      else{
        setWall(getX(rsquare), getY(rsquare), 1, false); // remove bottom wall
        sets.setunion(rsquare, rsquare+width); // union them into set
      }
    }
  }
}

bool SquareMaze::canTravel(int x, int y, int dir) const {
  //0=right 1=down 2=left 3=up
  if (width == 0 || height == 0) return false;

  if (dir == RIGHT) { //If can travel right
    if (x < width-1 && squares.at(getIndex(x, y)) != RIGHTWALL && squares.at(getIndex(x, y)) != BOTHWALLS) return true;
  }

  if (dir == DOWN) { //If can travel down
    if (y < height-1 && squares.at(getIndex(x, y)) != DOWNWALL && squares.at(getIndex(x, y)) != BOTHWALLS) return true;
  }

  if (dir == LEFT) { //If can travel left
    if (x != 0 && squares.at(getIndex(x - 1, y)) != RIGHTWALL && squares.at(getIndex(x - 1, y)) != BOTHWALLS) return true;
  }

  if (dir == UP) { //If can travel up
    if (y != 0 && squares.at(getIndex(x, y - 1)) != DOWNWALL && squares.at(getIndex(x, y - 1)) != BOTHWALLS) return true;
  }

  return false;
}

void SquareMaze::setWall(int x, int y, int dir, bool exists) {
  int wall = squares.at(getIndex(x, y));
  if(dir == RIGHT && exists){ // create right wall
    if(wall == NOWALL) squares.at(getIndex(x, y)) = RIGHTWALL;
    else if(wall == DOWNWALL) squares.at(getIndex(x, y)) = BOTHWALLS;
  }
  else if(dir == DOWN && exists){ // create down wall
    if(wall == NOWALL) squares.at(getIndex(x, y)) = DOWNWALL;
    else if(wall == RIGHTWALL) squares.at(getIndex(x, y)) = BOTHWALLS;
  }
  else if(dir == RIGHT && !exists){ // remove right wall
    if(wall == RIGHTWALL) squares.at(getIndex(x, y)) = NOWALL;
    else if(wall == BOTHWALLS) squares.at(getIndex(x, y)) = DOWNWALL;
  }
  else if(dir == DOWN && !exists){ // remove down wall
    if(wall == DOWNWALL) squares.at(getIndex(x, y)) = NOWALL;
    else if(wall == BOTHWALLS) squares.at(getIndex(x, y)) = RIGHTWALL;
  }
}

vector<int> SquareMaze::solveMaze() {
  vector<int> length(width * height, -1); //Fill them in with temp values. Width * height = max. possible length.
  vector<int> path(width * height, -1);
  vector<int> previous(width * height, -1);
  queue<int> q; //For backtracking purposes.
  q.push(0);

  while(!q.empty()) { //Where maze solving actually happens
    int index = q.front();
    int x = getX(index);
    int y = getY(index);
    if (canTravel(x, y, RIGHT) && length[index + 1] < 0) {
      length[index + 1] = length[index] + 1; //Increment length
      path[index + 1] = 0;
      previous[index + 1] = index;
      q.push(index + 1);
    }
    if (canTravel(x, y, DOWN) && length[index + width] < 0) {
      length[index + width] = length[index] + 1;
      path[index + width] = 1;
      previous[index + width] = index;
      q.push(index + width);
    }
    if (canTravel(x, y, LEFT) && length[index - 1] < 0) {
      length[index - 1] = length[index] + 1;
      path[index - 1] = 2;
      previous[index - 1] = index;
      q.push(index - 1);
    }
    if (canTravel(x, y, UP) && length[index - width] < 0) {
      length[index - width] = length[index] + 1;
      path[index - width] = 3;
      previous[index - width] = index;
      q.push(index - width);
    }
    q.pop();
  }

  int longestPathIndex = -1;
  int longestDist = -1;

  //Find the path with longest length in the last row
  for (int i = getIndex(0, height - 1); i < width * height; i++) {
    if (length[i] > longestDist) {
      longestPathIndex = i;
      longestDist = length[i];
    }
  }

  vector<int> result;
  while (longestPathIndex > 0) { //Actually push the path in to vector but starts from bottom
    result.push_back(path[longestPathIndex]);
    longestPathIndex = previous[longestPathIndex];
  }

  reverse(result.begin(), result.end());

  return result;
}

int SquareMaze::getIndex(int x, int y) const { //Helper function to get the index of square in vector
  return y * width + x;
}

int SquareMaze::getX(int index) const { //Helper to get x coordinate given an index.
  return index % width;
}

int SquareMaze::getY(int index) const { //Another helper to get y...
  return index / width;
}

PNG * SquareMaze::drawMaze() const {
  PNG* result = new PNG(width * 10 + 1, height * 10 + 1);
  for (int i = 0; i < width * 10 + 1; i++) { //Fill in the top wall first
    if (i < 1 || i > 9) {
      HSLAPixel & pixel = result->getPixel(i, 0);
      pixel.l = 0;
    }
  }
  for (int i = 0; i < height * 10 + 1; i++) { //Fill in the left wall
      HSLAPixel & pixel = result->getPixel(0, i);
      pixel.l = 0;
  }
  for (int x = 0; x < width; x++) { //Now draw the real thing
    for (int y = 0; y < height; y++) {
      //Draw the right wall of each square
      if (squares.at(getIndex(x, y)) == RIGHTWALL || squares.at(getIndex(x, y)) == BOTHWALLS) {
        for (int k = 0; k <= 10; k++) {
          HSLAPixel & pixel = result->getPixel((x+1)*10, y*10+k);
          pixel.l = 0;
        }
      }
      //Draw the bottom wall
      if (squares.at(getIndex(x, y)) == DOWNWALL || squares.at(getIndex(x, y)) == BOTHWALLS) {
        for (int k = 0; k <= 10; k++) {
          HSLAPixel & pixel = result->getPixel(x*10+k, (y+1)*10);
          pixel.l = 0;
        }
      }
    }
  }
  return result;
}

PNG * SquareMaze::drawMazeWithSolution() {
  //Import the base image and solution
  PNG* result = drawMaze();
  vector<int> solution = solveMaze();

  //Initialize the coordinate
  int x = 5;
  int y = 5;

  //I don't know why this works, but it does
  for (size_t i = 0; i < solution.size(); i++) {
    for (int j = 0; j < 10; j++) {
      HSLAPixel & pixel = result->getPixel(x, y);
      pixel.h = 0;
      pixel.s = 1;
      pixel.l = 0.5;
      pixel.a = 1;
      if (solution[i] == RIGHT) x++;
      if (solution[i] == DOWN) y++;
      if (solution[i] == LEFT) x--;
      if (solution[i] == UP) y--;
    }
  }

  //This is test-case oriented programming
  HSLAPixel & pixel = result->getPixel(x, y);
  pixel.h = 0;
  pixel.s = 1;
  pixel.l = 0.5;
  pixel.a = 1;

  //Idk how to get destination maze coordinates, but this might work?
  x -= 4;
  y += 5;
  for (int i = 0; i < 9; i++) {
    HSLAPixel & pixel = result->getPixel(x + i, y);
    pixel.l = 1;
  }

  return result;
}

PNG * SquareMaze::drawCreativeMaze() {
  PNG base;
  base.readFromFile("base.png");
  assert(width <= (int)(base.width() / 10) && height <= (int)(base.height() / 10));
  PNG* result = new PNG(width * 10 + 1, height * 10 + 1);
  for (int i = 0; i < width * 10 + 1; i++) { //Fill in the top wall first
    if (i < 1 || i > 9) {
      HSLAPixel & originPixel = base.getPixel(i, 0);
      HSLAPixel & newPixel = result->getPixel(i, 0);
      newPixel = originPixel;
    }
  }
  for (int i = 0; i < height * 10 + 1; i++) { //Fill in the left wall
    HSLAPixel & originPixel = base.getPixel(0, i);
    HSLAPixel & newPixel = result->getPixel(0, i);
    newPixel = originPixel;
  }
  for (int x = 0; x < width; x++) { //Now draw the real thing
    for (int y = 0; y < height; y++) {
      //Draw the right wall of each square
      if (squares.at(getIndex(x, y)) == RIGHTWALL || squares.at(getIndex(x, y)) == BOTHWALLS) {
        for (int k = 0; k <= 10; k++) {
          HSLAPixel & originPixel = base.getPixel((x+1)*10, y*10+k);
          HSLAPixel & newPixel = result->getPixel((x+1)*10, y*10+k);
          newPixel = originPixel;
        }
      }
      //Draw the bottom wall
      if (squares.at(getIndex(x, y)) == DOWNWALL || squares.at(getIndex(x, y)) == BOTHWALLS) {
        for (int k = 0; k <= 10; k++) {
          HSLAPixel & originPixel = base.getPixel(x*10+k, (y+1)*10);
          HSLAPixel & newPixel = result->getPixel(x*10+k, (y+1)*10);
          newPixel = originPixel;
        }
      }
    }
  }

  //Draw the solution
  vector<int> solution = solveMaze();

  //Initialize the coordinate
  int x = 5;
  int y = 5;

  //Actually start drawing solution
  for (size_t i = 0; i < solution.size(); i++) {
    for (int j = 0; j < 10; j++) {
      HSLAPixel & pixel = result->getPixel(x, y);
      HSLAPixel & originPixel = base.getPixel(x, y);
      if (originPixel.l != 1) { //Do not draw on empty area
        pixel.h = 0;
        pixel.s = 1;
        pixel.l = 0.5;
        pixel.a = 1;
      }
      if (solution[i] == RIGHT) x++;
      if (solution[i] == DOWN) y++;
      if (solution[i] == LEFT) x--;
      if (solution[i] == UP) y--;
    }
  }

  return result;
}
