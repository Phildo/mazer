#include "eventhandler.h"

EventHandler::EventHandler()
{

}

bool EventHandler::requestsQuit()
{
  while(SDL_PollEvent(&event))
  {
    if(event.type == SDL_QUIT) return true;
    else if(event.type == SDL_KEYDOWN)
    {
      switch(event.key.keysym.sym)
      {
        case SDLK_UP: case SDLK_w:
          //apply_surface(100,100,hello,screen);
          break;
        case SDLK_LEFT: case SDLK_a:
          //apply_surface(SCREEN_WIDTH-100-hello->w,100,hello,screen);
          break;
        case SDLK_DOWN: case SDLK_s:
          //apply_surface(SCREEN_WIDTH-100-hello->w,SCREEN_HEIGHT-100-hello->h,hello,screen);
          break;
        case SDLK_RIGHT: case SDLK_d:
          //apply_surface(100,SCREEN_HEIGHT-100-hello->h,hello,screen);
          break;
        default:;
      }
    }
  }
  return false;
}

