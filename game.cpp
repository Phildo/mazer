#include "game.h"
#include "render.h"
#include "eventhandler.h"

Game::Game()
{
  render = new Render();
  eventHandler = new EventHandler();

  quit = false;
}

void Game::begin()
{
  while(!quit)
  {
    quit = eventHandler->requestsQuit();
  }
}

Game::~Game()
{
}

