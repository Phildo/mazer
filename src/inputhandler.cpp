#include "inputhandler.h"

#include <SDL/SDL.h>

InputHandler::InputHandler()
{
}

void InputHandler::takeInput(const SDL_Event& e, Input& i)
{
  if(e.type == SDL_KEYDOWN)
  {
    i.up    = false;
    i.down  = false;
    i.left  = false;
    i.right = false;
    switch(e.key.keysym.sym)
    {
      case SDLK_UP:    case SDLK_w: i.up = true; break;
      case SDLK_LEFT:  case SDLK_a: i.up = true; break;
      case SDLK_DOWN:  case SDLK_s: i.up = true; break;
      case SDLK_RIGHT: case SDLK_d: i.up = true; break;
    }
  }
}

InputHandler::~InputHandler()
{

}

