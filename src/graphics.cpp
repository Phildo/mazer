#include "graphics.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "rendererh.h"

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

void Graphics::render(Renderer& r)
{
  
}
