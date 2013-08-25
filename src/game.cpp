#include "game.h"

#include <SDL/SDL.h>
#include "render.h"
#include "inputhandler.h"
#include "timer.h"

const int MS_PER_TICK = 200;

Game::Game()
{
  render = new Render();
  inputHandler = new InputHandler();
  timer = new Timer();
}

void Game::initialize()
{

}

void Game::run()
{
  int tickSeconds = 0;
  SDL_Event event;

  timer->stamp();
  while(!SDL_PollEvent(&event) || event.type != SDL_QUIT)
  {
    tickSeconds += timer->msSinceStamp();

    while(tickSeconds > MS_PER_TICK)
    {
      tickSeconds -= MS_PER_TICK;
      tick();
    }
  }
}

void Game::tick()
{

}

Game::~Game()
{
  delete render;
  delete inputHandler;
  delete timer;
}

