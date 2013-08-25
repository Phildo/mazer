#include "game.h"

#include <SDL/SDL.h>
#include "render.h"
#include "inputhandler.h"

SDL_Event event;

Game::Game()
{
  render = new Render();
  inputHandler = new InputHandler();

  quit = false;
}

void Game::run()
{
  while(!SDL_PollEvent(&event) || event.type != SDL_QUIT)
  {
    
  }
}

Game::~Game()
{
  delete render;
  delete inputHandler;
}

