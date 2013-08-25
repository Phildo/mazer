#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "sdl_help.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32; //bits-per-pixel

SDL_Event event;
SDL_Surface *hello = NULL;
SDL_Surface *screen = NULL;

bool init()
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == -1) return 1;
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
  if(screen == NULL) return 1;
  SDL_WM_SetCaption("mazer",NULL);
  return true;
}

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

int main(int argc, char **args)
{
  if(!init())       return 1;
  if(!load_files()) return 1;

  bool quit = false;

  SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
  //apply_surface(100,100,hello,screen);
  if(SDL_Flip(screen) == -1) return 1;
  
  while(!quit)
  {
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT) quit = true;
      else if(event.type == SDL_KEYDOWN)
      {
        switch(event.key.keysym.sym)
        {
          case SDLK_UP: case SDLK_w:
            apply_surface(100,100,hello,screen);
            break;
          case SDLK_LEFT: case SDLK_a:
            apply_surface(SCREEN_WIDTH-100-hello->w,100,hello,screen);
            break;
          case SDLK_DOWN: case SDLK_s:
            apply_surface(SCREEN_WIDTH-100-hello->w,SCREEN_HEIGHT-100-hello->h,hello,screen);
            break;
          case SDLK_RIGHT: case SDLK_d:
            apply_surface(100,SCREEN_HEIGHT-100-hello->h,hello,screen);
            break;
          default:;
        }
        if(SDL_Flip(screen) == -1) return 1;
      }
    }
  }

  clean_up();
  return 0;
}

