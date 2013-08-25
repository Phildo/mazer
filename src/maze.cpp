#include "maze.h"

Maze::Maze(int x, int y)
{
  generate(x, y);
}

Maze::~Maze()
{

}

void Maze::generate(int x, int y)
{
  blocks = new MazeBlock[x*y];
}

MazeBlock *Maze::getBlocks()
{
  return blocks;
}
