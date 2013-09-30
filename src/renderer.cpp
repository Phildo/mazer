#include "renderer.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "graphics.h"

Renderer::Renderer()
{
  sprite = new SDL_Surface();
}

Renderer::~Renderer()
{
  SDL_FreeSurface(sprite);
}

void Renderer::load_image(const char* filename, SDL_Surface* surface)
{
  SDL_Surface *loadedImage = NULL;
  loadedImage = IMG_Load(filename);

  if(loadedImage != NULL)
  {
    surface = SDL_DisplayFormatAlpha(loadedImage);
    SDL_FreeSurface(loadedImage);
  }
}

void Renderer::apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  SDL_BlitSurface(source, clip, destination, &offset);
}

void Renderer::render(void* r, const Graphics* g)
{
  //SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
  //apply_surface((screen->w-face->w)/2,(screen->h-face->h)/2,face,screen);
}

