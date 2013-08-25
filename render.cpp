#include "render.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


Render::Render()
{
int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;
int SCREEN_BPP = 32; //bits-per-pixel
  //if(SDL_Init(SDL_INIT_EVERYTHING) == -1)// return 1;
  SDL_Init(SDL_INIT_EVERYTHING);
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
  //if(screen == NULL) //return 1;
  //SDL_WM_SetCaption("mazer",NULL);
  //return true;
}

void Render::render()
{

}

/*
bool load_files()
{
  hello = load_image("assets/proud_face.png");
  if(hello == NULL) return false;
  return true;
}

void clean_up()
{
  SDL_FreeSurface(hello);
  SDL_FreeSurface(screen);
  SDL_Quit();
}

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


void doit()
{
  if(!init())       return 1;
  if(!load_files()) return 1;
  SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
  apply_surface(100,100,hello,screen);
  if(SDL_Flip(screen) == -1) return 1;
}
*/
