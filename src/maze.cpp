#include "maze.h"
#include <stdlib.h>

Maze::Maze(int x, int y)
{
  generate(x, y);
}

Maze::~Maze()
{
  delete [] blocks;
}

//void Maze::generate(int x, int y, int startx, int starty, int endx, int endy)
void Maze::generate(int x, int y)
{
  blocks = new MazeBlock[x*y];
  for(int i = 0; i < x; i++)
    for(int j = 0; j < y; j++)
      blocks[(j*y)+i].type = OPEN_NONE;

  for(int i = 0; i < x; i++)
    for(int j = 0; j < y; j++)
      blocks[(j*y)+i].type = (MazeBlockType)rand();//OPEN_NONE;
}

MazeBlock *Maze::getBlocks()
{
  return blocks;
}
