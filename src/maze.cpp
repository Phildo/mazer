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
    for(x = 0; x < width; x++)
      blocks[(y*width)+x].type = WALL_NONE;

  for(y = 1; y < height-1; y++)
    for(x = 1; x < width-1; x++)
      closeBlockWall(blocks,x,y,width,height,WALL_ALL);

  //drunken walk through for a bit

  //std::list<MazeBlock> curWalk;
  MazeBlockWallType dir;
  int newx;
  int newy;
  for(int e = 0; e < 15; e++)
  {
    x = (rand()%37)+1;//0-38;
    y = (rand()%27)+1;//0-28;
    for(int i = 0; i < 50; i++)
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

      if(blocks[(newy*width)+newx].type == WALL_ALL || (~(int)(blocks[(y*width)+x].type) & dir))
      {
        openBlockWall(blocks,x,y,width,height,dir);
        x = newx;
        y = newy;
        //curWalk.push_front(blocks[(newy*width)+newx]);
      }
    }
  }
  return blocks;
}

MazeBlock *Maze::getBlocks()
{
  return blocks;
}

