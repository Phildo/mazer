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
  int x = 0;
  int y = 0;
  MazeBlock *blocks = new MazeBlock[width*height];

  //set default full-maze state
  for(y = 0; y < height; y++)
  {
    for(x = 0; x < width; x++)
    {
      if(y == 0)
        blocks[(y*width)+x].type = WALL_BOTTOM;
      else if(y == height-1)
        blocks[(y*width)+x].type = WALL_TOP;
      else if(x == 0)
        blocks[(y*width)+x].type = WALL_RIGHT;
      else if(x == width-1)
        blocks[(y*width)+x].type = WALL_LEFT;
      else
        blocks[(y*width)+x].type = WALL_ALL;
    }
  }
  //corners...
  blocks[(0         *width)+        0].type = WALL_NONE;
  blocks[((height-1)*width)+        0].type = WALL_NONE;
  blocks[(0         *width)+(width-1)].type = WALL_NONE;
  blocks[((height-1)*width)+(width-1)].type = WALL_NONE;

  std::list<MazeBlock> curWalk;

  //drunken walk through for a bit
  x = 20;
  y = 15;
  int newx = 20;
  int newy = 15;

  MazeBlockWallType dir;
  for(int i = 0; i < 100000; i++)
  {
      dir = WALL_NONE;
      switch(rand()%4)
      {
        case 0: dir = WALL_BOTTOM; newy = y+1; break;
        case 1: dir = WALL_LEFT;   newx = x-1; break;
        case 2: dir = WALL_TOP;    newy = y-1; break;
        case 3: dir = WALL_RIGHT;  newx = x+1; break;
      }

      if(blocks[((newy+1)*width)+newx].type == WALL_ALL || blocks[((y+1)*width)+x].type & dir)
      {
        openBlockWall(blocks,x,y,width,height,dir);
        x = newx;
        y = newy;
        curWalk.push_front(blocks[(newy*width)+newx]);
      }
  }

  return blocks;
}

MazeBlock *Maze::getBlocks()
{
  return blocks;
}

