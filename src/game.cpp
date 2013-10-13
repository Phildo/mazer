#include "game.h"

#include <SDL/SDL.h>
#include <iostream>
#include "graphics.h"
//#include "inputhandler.h"
#include "timer.h"
#include "scene.h"
#include "mainscene.h"

const int FPS = 10;
const int MS_PER_TICK = 1000/FPS;//200;

Game::Game()
{
  graphics     = new Graphics();
  //inputHandler = new InputHandler();
  timer        = new Timer();
  mainScene    = new MainScene();
}

void Game::initialize()
{
  scene = mainScene;
}

void Game::run()
{
  int tickSeconds = 0;
  SDL_Event event;

  timer->stamp();
      tick();
  while(!SDL_PollEvent(&event) || event.type != SDL_QUIT)
  {
    tickSeconds += timer->msSinceStamp();
    timer->stamp();

    while(tickSeconds > MS_PER_TICK)
    {
      tickSeconds -= MS_PER_TICK;
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
  scene->tick();
}

void Game::tickGraphics()
{
  graphics->clear();
  scene->render(graphics);
  graphics->flip();
}

Game::~Game()
{
  delete graphics;
  //delete inputHandler;
  delete timer;
  delete mainScene;
}

