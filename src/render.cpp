#include "render.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "maze.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32; //bits-per-pixel

void load_image(const char *filename, SDL_Surface **surface)
{
  SDL_Surface *loadedImage    = NULL;
  loadedImage = IMG_Load(filename);

  if(loadedImage != NULL)
  {
    *surface = SDL_DisplayFormatAlpha(loadedImage);
    SDL_FreeSurface(loadedImage);
  }
}

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip = NULL)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  SDL_BlitSurface(source, clip, destination, &offset);
}

Render::Render()
{
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
  SDL_WM_SetCaption("mazer",NULL);
  
  load_image("../assets/proud_face.png", &face);
  load_image("../assets/top.png",        &top);
  load_image("../assets/right.png",      &right);
  load_image("../assets/bottom.png",     &bottom);
  load_image("../assets/left.png",       &left);
}

void Render::draw(MazeBlock *blocks)
{
  SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
  apply_surface((screen->w-face->w)/2,(screen->h-face->h)/2,face,screen);

  int x = 40;
  int y = 30;
  for(int i = 0; i < x; i++)
  {
    for(int j = 0; j < y; j++)
    {
      if(!(blocks[(j*y)+i].type & OPEN_TOP))    apply_surface(i*(SCREEN_WIDTH/x),j*(SCREEN_HEIGHT/y),top,   screen);
      if(!(blocks[(j*y)+i].type & OPEN_RIGHT))  apply_surface(i*(SCREEN_WIDTH/x),j*(SCREEN_HEIGHT/y),right, screen);
      if(!(blocks[(j*y)+i].type & OPEN_BOTTOM)) apply_surface(i*(SCREEN_WIDTH/x),j*(SCREEN_HEIGHT/y),bottom,screen);
      if(!(blocks[(j*y)+i].type & OPEN_LEFT))   apply_surface(i*(SCREEN_WIDTH/x),j*(SCREEN_HEIGHT/y),left,  screen);
    }
  }

  SDL_Flip(screen);
}

Render::~Render()
{
  SDL_FreeSurface(screen);
}

