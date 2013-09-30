#include "mazerenderer.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "maze.h"
#include "graphics.h"

MazeRenderer::MazeRenderer()
{
  load_image("../assets/top.png",    top);
  load_image("../assets/right.png",  right);
  load_image("../assets/bottom.png", bottom);
  load_image("../assets/left.png",   left);
}

void MazeRenderer::render(void* v, const Graphics* g)
{
  Maze* m = (Maze*)v;
  int w = m->getWidth();
  int h = m->getHeight();
  int gw = g->getWidth();
  int gh = g->getHeight();
  SDL_Surface *screen = g->getScreen();
  MazeBlock* blocks = m->getBlocks();

  for(int y = 0; y < h; y++)
  {
    for(int x = 0; x < w; x++)
    {
      if(blocks[(y*w)+x].type & WALL_TOP)    apply_surface(x*(gw/w),y*(gh/h),top,   screen);
      if(blocks[(y*w)+x].type & WALL_RIGHT)  apply_surface(x*(gw/w),y*(gh/h),right, screen);
      if(blocks[(y*w)+x].type & WALL_BOTTOM) apply_surface(x*(gw/w),y*(gh/h),bottom,screen);
      if(blocks[(y*w)+x].type & WALL_LEFT)   apply_surface(x*(gw/w),y*(gh/h),left,  screen);
    }
  }
}

MazeRenderer::~MazeRenderer()
{
  SDL_FreeSurface(top);
  SDL_FreeSurface(right);
  SDL_FreeSurface(bottom);
  SDL_FreeSurface(left);
}

