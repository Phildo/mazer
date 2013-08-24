#include <SDL/SDL.h>
#include <SDL/SDL_image.h> //"/Library/Frameworks/SDL2_image.framework/Versions/A/Headers/SDL_image.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32; //bits-per-pixel

SDL_Surface *load_image(char *filename)
{
  SDL_Surface *loadedImage    = NULL;
  SDL_Surface *optimizedImage = NULL;
  loadedImage = IMG_Load(filename);
  if(loadedImage != NULL)
  {
    optimizedImage = SDL_DisplayFormat(loadedImage);
    SDL_FreeSurface(loadedImage);
  }

  return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;

  SDL_BlitSurface(source, NULL, destination, &offset);
}

int main(int argc, char **args)
{
  SDL_Surface *hello = NULL;
  SDL_Surface *screen = NULL;
  if(SDL_Init(SDL_INIT_EVERYTHING) == -1) return 1;
  SDL_WM_SetCaption("mazer",NULL);
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
  if(screen == NULL) return 1;
  hello = load_image("assets/proud_face.png");
  apply_surface(100,100,hello,screen);
  if(SDL_Flip(screen) == -1) return 1;
  SDL_Delay(2000);
  SDL_FreeSurface(hello);
  SDL_FreeSurface(screen);
  SDL_Quit();
  return 0;
}

