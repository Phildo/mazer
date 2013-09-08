#include "graphics.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32; //bits-per-pixel

Graphics::Graphics()
{
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
  SDL_WM_SetCaption("mazer",NULL);
}

Graphics::~Graphics()
{
  SDL_FreeSurface(screen);
}

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

