#include "game.h"

#include <SDL/SDL.h>
#include "render.h"
#include "inputhandler.h"
#include "timer.h"

Game::Game()
{
  render = new Render();
  inputHandler = new InputHandler();
  timer = new Timer();
}

void Game::run()
{
  SDL_Event event;
  while(!SDL_PollEvent(&event) || event.type != SDL_QUIT)
  {
    
  }
}

Game::~Game()
{
  delete render;
  delete inputHandler;
  delete timer;
}

