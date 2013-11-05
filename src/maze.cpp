#include "maze.h"
#include <list>
#include <stdlib.h>

Maze::Maze(int w, int h)
{
  width = w;
  height = h;
  blocks = generate();
}

Maze::~Maze()
{
  delete [] blocks;
}

bool Maze::wallOpen(MazeBlock& block, MazeBlockWallType t) const
{
  return !(block.type & t);
}

bool Maze::wallClosed(MazeBlock& block, MazeBlockWallType t) const
{
  return (block.type & t);
}

void Maze::closeBlockWall(MazeBlock* blocks, int x, int y, MazeBlockWallType t) const
{
  blocks[(width*y)+x].type = (MazeBlockWallType)(blocks[(width*y)+x].type | t);

  if(t & WALL_TOP)    blocks[(width*(y-1))+x  ].type = (MazeBlockWallType)(blocks[(width*(y-1))+x  ].type | WALL_BOTTOM);
  if(t & WALL_RIGHT)  blocks[(width* y)   +x+1].type = (MazeBlockWallType)(blocks[(width* y)   +x+1].type | WALL_LEFT);
  if(t & WALL_BOTTOM) blocks[(width*(y+1))+x  ].type = (MazeBlockWallType)(blocks[(width*(y+1))+x  ].type | WALL_TOP);
  if(t & WALL_LEFT)   blocks[(width* y)   +x-1].type = (MazeBlockWallType)(blocks[(width* y)   +x-1].type | WALL_RIGHT);
}

void Maze::openBlockWall(MazeBlock* blocks, int x, int y, MazeBlockWallType t) const
{
  blocks[(width*y)+x].type = (MazeBlockWallType)(blocks[(width*y)+x].type & ~t);

  if(t & WALL_TOP)    blocks[(width*(y-1))+x  ].type = (MazeBlockWallType)(blocks[(width*(y-1))+x  ].type & ~WALL_BOTTOM);
  if(t & WALL_RIGHT)  blocks[(width* y)   +x+1].type = (MazeBlockWallType)(blocks[(width* y)   +x+1].type & ~WALL_LEFT);
  if(t & WALL_BOTTOM) blocks[(width*(y+1))+x  ].type = (MazeBlockWallType)(blocks[(width*(y+1))+x  ].type & ~WALL_TOP);
  if(t & WALL_LEFT)   blocks[(width* y)   +x-1].type = (MazeBlockWallType)(blocks[(width* y)   +x-1].type & ~WALL_RIGHT);
}

bool Maze::hasUntouchedNeighbors(MazeBlock* blocks, int x, int y) const
{
    if(blocks[((y+1)*width)+x].type == WALL_ALL) return true;
    if(blocks[((y-1)*width)+x].type == WALL_ALL) return true;
    if(blocks[(y*width)+(x+1)].type == WALL_ALL) return true;
    if(blocks[(y*width)+(x-1)].type == WALL_ALL) return true;

    return false;
}

MazeBlock* Maze::generate()
{
  MazeBlock* blocks = new MazeBlock[width*height];
  MazeBlock* curBlock;
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
      closeBlockWall(blocks,x,y,WALL_ALL);

  std::list<MazeBlock*> edges;
  std::list<MazeBlock*>::iterator e_it;
  edges.push_back(&blocks[(1*width)+1]);

  int newx;
  int newy;
  MazeBlockWallType dir;
  while(!edges.empty())
  {
    curBlock = *edges.begin();
    x = curBlock->x;
    y = curBlock->y;

    while(hasUntouchedNeighbors(blocks, x, y))
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

      if(newx != 0 && newx != width-1  && 
         newy != 0 && newy != height-1 && 
         blocks[(newy*width)+newx].type == WALL_ALL)
      {
        openBlockWall(blocks,x,y,dir);
        if(!hasUntouchedNeighbors(blocks, x, y)) edges.remove(curBlock);
        x = newx;
        y = newy;
        curBlock = &blocks[(y*width)+x];
        if(hasUntouchedNeighbors(blocks, x, y)) edges.push_back(curBlock);

        //expensive...
        if(!hasUntouchedNeighbors(blocks, x, (y+1))) edges.remove(&blocks[((y+1)*width)+x]);
        if(!hasUntouchedNeighbors(blocks, x, (y-1))) edges.remove(&blocks[((y-1)*width)+x]);
        if(!hasUntouchedNeighbors(blocks, (x+1), y)) edges.remove(&blocks[(y*width)+(x+1)]);
        if(!hasUntouchedNeighbors(blocks, (x-1), y)) edges.remove(&blocks[(y*width)+(x-1)]);
      }
    }
  }
  return blocks;
}

int Maze::getHeight() const
{
  return height;
}

int Maze::getWidth() const
{
  return width;
}

bool Maze::isValidMove(int srcX, int srcY, int destX, int destY) const
{
  MazeBlockWallType srcWallCheck = WALL_NONE;
  if(srcX > destX) srcWallCheck = (MazeBlockWallType)(srcWallCheck | WALL_LEFT);
  if(srcX < destX) srcWallCheck = (MazeBlockWallType)(srcWallCheck | WALL_RIGHT);
  if(srcY > destY) srcWallCheck = (MazeBlockWallType)(srcWallCheck | WALL_TOP);
  if(srcY < destY) srcWallCheck = (MazeBlockWallType)(srcWallCheck | WALL_BOTTOM);
  return wallOpen(blocks[(width*srcY)+srcX], srcWallCheck);
}

MazeBlock* Maze::getBlocks() const
{
  return blocks;
}

