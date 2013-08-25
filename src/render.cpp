#include "render.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32; //bits-per-pixel

SDL_Surface *load_image(const char *filename)
{
  SDL_Surface *loadedImage    = NULL;
  SDL_Surface *optimizedImage = NULL;
  loadedImage = IMG_Load(filename);

  if(loadedImage != NULL)
  {
    optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
    SDL_FreeSurface(loadedImage);
  }

  return optimizedImage;
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
  face = load_image("assets/proud_face.png");
  SDL_WM_SetCaption("mazer",NULL);
}

void Render::draw()
{
  SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
  apply_surface((screen->w-face->w)/2,(screen->h-face->h)/2,face,screen);
  SDL_Flip(screen);
}

Render::~Render()
{
  SDL_FreeSurface(screen);
}

