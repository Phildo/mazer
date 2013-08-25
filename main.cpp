#include "Game.h"

#include <SDL/SDL.h>

int main(int argc, char **args)
{
  Game *g = new Game();
  g->begin();
  return 0;
}

