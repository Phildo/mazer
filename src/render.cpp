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
  //apply_surface((screen->w-face->w)/2,(screen->h-face->h)/2,face,screen);

  int width = 40;
  int height = 30;
  for(int y = 0; y < height; y++)
  {
    for(int x = 0; x < width; x++)
    {
      //if(x == 0 || y == 0 || x == width-1 || y == height-1) apply_surface(x*(SCREEN_WIDTH/width),y*(SCREEN_HEIGHT/height),face,screen);
      if(blocks[(y*width)+x].type & CLOSE_TOP)    apply_surface(x*(SCREEN_WIDTH/width),y*(SCREEN_HEIGHT/height),top,   screen);
      if(blocks[(y*width)+x].type & CLOSE_RIGHT)  apply_surface(x*(SCREEN_WIDTH/width),y*(SCREEN_HEIGHT/height),right, screen);
      if(blocks[(y*width)+x].type & CLOSE_BOTTOM) apply_surface(x*(SCREEN_WIDTH/width),y*(SCREEN_HEIGHT/height),bottom,screen);
      if(blocks[(y*width)+x].type & CLOSE_LEFT)   apply_surface(x*(SCREEN_WIDTH/width),y*(SCREEN_HEIGHT/height),left,  screen);
    }
  }

  SDL_Flip(screen);
}

Render::~Render()
{
  SDL_FreeSurface(screen);
}

