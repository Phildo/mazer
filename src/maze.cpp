#include "maze.h"
#include <iostream>
#include <list>

MazeBlock *generate(int width, int height);

Maze::Maze(int x, int y)
{
  width = x;
  height = y;
  blocks = generate(width, height);
}

Maze::~Maze()
{
  delete [] blocks;
}

void closeBlockWall(MazeBlock *blocks, int x, int y, int width, int height, MazeBlockWallType t)
{
  blocks[(width*y)+x].type = (MazeBlockWallType)(blocks[(width*y)+x].type | t);

  if(t & WALL_TOP)    blocks[(width*(y-1))+x  ].type = (MazeBlockWallType)(blocks[(width*(y-1))+x  ].type | WALL_BOTTOM);
  if(t & WALL_RIGHT)  blocks[(width* y)   +x+1].type = (MazeBlockWallType)(blocks[(width* y)   +x+1].type | WALL_LEFT);
  if(t & WALL_BOTTOM) blocks[(width*(y+1))+x  ].type = (MazeBlockWallType)(blocks[(width*(y+1))+x  ].type | WALL_TOP);
  if(t & WALL_LEFT)   blocks[(width* y)   +x-1].type = (MazeBlockWallType)(blocks[(width* y)   +x-1].type | WALL_RIGHT);
}

void openBlockWall(MazeBlock *blocks, int x, int y, int width, int height, MazeBlockWallType t)
{
  blocks[(width*y)+x].type = (MazeBlockWallType)(blocks[(width*y)+x].type & ~t);

  if(t & WALL_TOP)    blocks[(width*(y-1))+x  ].type = (MazeBlockWallType)(blocks[(width*(y-1))+x  ].type & ~WALL_BOTTOM);
  if(t & WALL_RIGHT)  blocks[(width* y)   +x+1].type = (MazeBlockWallType)(blocks[(width* y)   +x+1].type & ~WALL_LEFT);
  if(t & WALL_BOTTOM) blocks[(width*(y+1))+x  ].type = (MazeBlockWallType)(blocks[(width*(y+1))+x  ].type & ~WALL_TOP);
  if(t & WALL_LEFT)   blocks[(width* y)   +x-1].type = (MazeBlockWallType)(blocks[(width* y)   +x-1].type & ~WALL_RIGHT);
}

MazeBlock *generate(int width, int height)
{
  MazeBlock *blocks = new MazeBlock[width*height];
  std::list<MazeBlock> curWalk;
  int x;
  int y;
  int newx;
  int newy;
  MazeBlockWallType dir;

  //set default state
  for(y = 0; y < height; y++)
    for(x = 0; x < width; x++)
      blocks[(y*width)+x].type = WALL_NONE;
  for(y = 1; y < height-1; y++)
    for(x = 1; x < width-1; x++)
      closeBlockWall(blocks,x,y,width,height,WALL_ALL);

  //drunken walk through for a bit
  x = 1;
  y = 1;
  for(int i = 0; i < 500; i++)
  {
    newx = x;
    newy = y;
    switch(rand()%4)
    {
      case 0: dir = WALL_BOTTOM; newy = (y+1); break;
      case 1: dir = WALL_LEFT;   newx = (x-1); break;
      case 2: dir = WALL_TOP;    newy = (y-1); break;
      case 3: dir = WALL_RIGHT;  newx = (x+1); break;
    }

    if(newx != 0 && newx != width-1 && newy != 0 && newy != height-1)
    {
      if(blocks[(newy*width)+newx].type == WALL_ALL)// || (~(int)(blocks[(y*width)+x].type) & dir))
        openBlockWall(blocks,x,y,width,height,dir);
      x = newx;
      y = newy;
    }
  }
  return blocks;
}

MazeBlock *Maze::getBlocks()
{
  return blocks;
}

