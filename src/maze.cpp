#include "maze.h"
#include <stdlib.h>

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

void setBlockType(MazeBlock *blocks, int x, int y, int width, int height, MazeBlockType t)
{
  blocks[(width*y)+x].type = (MazeBlockType)(blocks[(width*y)+x].type | t);

  if(t & CLOSE_TOP)    blocks[(width*(y-1))+x  ].type = (MazeBlockType)(blocks[(width*(y-1))+x  ].type | CLOSE_BOTTOM);
  if(t & CLOSE_RIGHT)  blocks[(width* y)   +x+1].type = (MazeBlockType)(blocks[(width* y)   +x+1].type | CLOSE_LEFT);
  if(t & CLOSE_BOTTOM) blocks[(width*(y+1))+x  ].type = (MazeBlockType)(blocks[(width*(y+1))+x  ].type | CLOSE_TOP);
  if(t & CLOSE_LEFT)   blocks[(width* y)   +x-1].type = (MazeBlockType)(blocks[(width* y)   +x-1].type | CLOSE_RIGHT);
}

MazeBlock *generate(int width, int height)
{
  MazeBlock *blocks = new MazeBlock[width*height];
  int x;
  int y;
  for(y = 0; y < height; y++)
    for(x = 0; x < width; x++)
      blocks[(y*width)+x].type = CLOSE_NONE;

  for(y = 0; y < height; y++)
    for(x = 0; x < width; x++)
      if(x != 0 && x != width-1 && y != 0 && y != height-1)
        setBlockType(blocks,x,y,width,height,(MazeBlockType)rand());

  for(y = 1; y < height-1; y++)
  {
    setBlockType(blocks,0,      y,width,height,CLOSE_RIGHT);
    setBlockType(blocks,width-1,y,width,height,CLOSE_LEFT);
  }

  for(x = 1; x < width-1; x++)
  {
    setBlockType(blocks,x,       0,width,height,CLOSE_BOTTOM);
    setBlockType(blocks,x,height-1,width,height,CLOSE_TOP);
  }

  return blocks;
}

MazeBlock *Maze::getBlocks()
{
  return blocks;
}
