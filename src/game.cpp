#include "game.h"

#include <SDL/SDL.h>
#include <iostream>
#include "graphics.h"
#include "inputhandler.h"
#include "timer.h"
#include "maze.h"
#include "mazerenderer.h"

const int FPS = 10;
const int MS_PER_TICK = 1000/FPS;//200;

Game::Game()
{
  graphics     = new Graphics();
  inputHandler = new InputHandler();
  timer        = new Timer();
  maze         = new Maze(40,30);
  mazerenderer = new MazeRenderer();
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
      //std::cout << "tick... " << tickSeconds << std::endl;
    }
  }
}

void Game::tick()
{
  tickLogic();
  tickGraphics();
}

void Game::tickLogic()
{

}

void Game::tickGraphics()
{
  mazerenderer->render(maze,graphics);
}

Game::~Game()
{
  delete graphics;
  delete inputHandler;
  delete timer;
  delete maze;
  delete mazerenderer;
}

