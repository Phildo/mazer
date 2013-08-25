#include "Game.h"

#include <SDL/SDL.h>

int main(int argc, char **args)
{
  SDL_Init(SDL_INIT_EVERYTHING);

  Game *g = new Game();
  g->run();
  delete g;

  SDL_Quit();
  return 0;
}

