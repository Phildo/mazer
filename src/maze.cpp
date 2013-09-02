#include "maze.h"
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

bool hasAvailableEdges(MazeBlock *blocks, int x, int y, int width, int height)
{
    if(blocks[((y+1)*width)+x].type == WALL_ALL) return true;
    if(blocks[((y-1)*width)+x].type == WALL_ALL) return true;
    if(blocks[(y*width)+(x+1)].type == WALL_ALL) return true;
    if(blocks[(y*width)+(x-1)].type == WALL_ALL) return true;

    return false;
}

MazeBlock *generate(int width, int height)
{
  MazeBlock *blocks = new MazeBlock[width*height];
  MazeBlock *curBlock;
  int x;
  int y;

  //set default state
  for(y = 0; y < height; y++)
    for(x = 0; x < width; x++)
    {
      blocks[(y*width)+x].type = WALL_NONE;
      blocks[(y*width)+x].x = x;
      blocks[(y*width)+x].y = y;
    }
  for(y = 1; y < height-1; y++)
    for(x = 1; x < width-1; x++)
      closeBlockWall(blocks,x,y,width,height,WALL_ALL);

  //drunken walk through for a bit

  std::list<MazeBlock *> edges;
  std::list<MazeBlock *>::iterator e_it;
  edges.push_back(&blocks[(1*width)+1]);

  int newx;
  int newy;
  MazeBlockWallType dir;
  while(!edges.empty())
  {
    curBlock = *edges.begin();
    x = curBlock->x;
    y = curBlock->y;

    while(hasAvailableEdges(blocks, x, y, width, height))
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

      if(newx != 0 && newx != width-1 && newy != 0 && newy != height-1 && blocks[(newy*width)+newx].type == WALL_ALL)// || (~(int)(blocks[(y*width)+x].type) & dir))
      {
        openBlockWall(blocks,x,y,width,height,dir);
        if(!hasAvailableEdges(blocks, x, y, width, height)) edges.remove(curBlock);
        x = newx;
        y = newy;
        curBlock = &blocks[(y*width)+x];
        if(hasAvailableEdges(blocks, x, y, width, height)) edges.push_back(curBlock);

        //expensive...
        if(!hasAvailableEdges(blocks, x, (y+1), width, height)) edges.remove(&blocks[((y+1)*width)+x]);
        if(!hasAvailableEdges(blocks, x, (y-1), width, height)) edges.remove(&blocks[((y-1)*width)+x]);
        if(!hasAvailableEdges(blocks, (x+1), y, width, height)) edges.remove(&blocks[(y*width)+(x+1)]);
        if(!hasAvailableEdges(blocks, (x-1), y, width, height)) edges.remove(&blocks[(y*width)+(x-1)]);
      }
    }
  }
  return blocks;
}

MazeBlock *Maze::getBlocks()
{
  return blocks;
}

