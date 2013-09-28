#include "render.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "maze.h"
#include "graphics.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32; //bits-per-pixel

MazeRenderer::MazeRenderer()
{
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
  SDL_WM_SetCaption("mazer",NULL);
  
  load_image("../assets/proud_face.png", &face);
  load_image("../assets/top.png",        &top);
  load_image("../assets/right.png",      &right);
  load_image("../assets/bottom.png",     &bottom);
  load_image("../assets/left.png",       &left);
}

void MazeRenderer::render(const Maze& m, const Graphics& g);
{
  SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
  //apply_surface((screen->w-face->w)/2,(screen->h-face->h)/2,face,screen);

  int width = 40;
  int height = 30;
  for(int y = 0; y < height; y++)
  {
    for(int x = 0; x < width; x++)
    {
      //if(x == 0 || y == 0 || x == width-1 || y == height-1) apply_surface(x*(SCREEN_WIDTH/width),y*(SCREEN_HEIGHT/height),face,screen);
      if(blocks[(y*width)+x].type & WALL_TOP)    apply_surface(x*(SCREEN_WIDTH/width),y*(SCREEN_HEIGHT/height),top,   screen);
      if(blocks[(y*width)+x].type & WALL_RIGHT)  apply_surface(x*(SCREEN_WIDTH/width),y*(SCREEN_HEIGHT/height),right, screen);
      if(blocks[(y*width)+x].type & WALL_BOTTOM) apply_surface(x*(SCREEN_WIDTH/width),y*(SCREEN_HEIGHT/height),bottom,screen);
      if(blocks[(y*width)+x].type & WALL_LEFT)   apply_surface(x*(SCREEN_WIDTH/width),y*(SCREEN_HEIGHT/height),left,  screen);
    }
  }
  SDL_Flip(screen);
}

Render::~Render()
{
  SDL_FreeSurface(top);
  SDL_FreeSurface(right);
  SDL_FreeSurface(bottom);
  SDL_FreeSurface(left);
}

