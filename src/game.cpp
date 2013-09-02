#include "game.h"

#include <SDL/SDL.h>
#include <iostream>
#include "render.h"
#include "inputhandler.h"
#include "timer.h"
#include "maze.h"

const int FPS = 10;
const int MS_PER_TICK = 1000/FPS;//200;

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
  tick(); //only tick once (rather than in the loop) because we're not doing anything...
  while(!SDL_PollEvent(&event) || event.type != SDL_QUIT)
  {
    tickSeconds += timer->msSinceStamp();
    timer->stamp();

    while(tickSeconds > MS_PER_TICK)
    {
      tickSeconds -= MS_PER_TICK;
      //std::cout << "tick... " << tickSeconds << "\n" << std::flush;
    }
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

