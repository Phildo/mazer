#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Surface *load_image(char *filename)
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

