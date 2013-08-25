#include "game.h"

#include <SDL/SDL.h>
#include "render.h"
#include "inputhandler.h"
#include "timer.h"
#include "maze.h"

const int MS_PER_TICK = 200;

Game::Game()
{
  render = new Render();
  inputHandler = new InputHandler();
  timer = new Timer();
  maze = new Maze(40,30);
}

void Game::initialize()
{

}

void Game::run()
{
  int tickSeconds = 0;
  SDL_Event event;

  timer->stamp();
  tick();
  while(!SDL_PollEvent(&event) || event.type != SDL_QUIT)
  {
  /*
    tickSeconds += timer->msSinceStamp();

    while(tickSeconds > MS_PER_TICK)
    {
      tickSeconds -= MS_PER_TICK;
      //tick();
    }
    */
  }
}

void Game::tick()
{
  render->draw(maze->getBlocks());
}

Game::~Game()
{
  delete render;
  delete inputHandler;
  delete timer;
  delete maze;
}

