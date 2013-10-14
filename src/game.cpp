#include "game.h"

#include <SDL/SDL.h>
#include <iostream>
#include "graphics.h"
#include "inputhandler.h"
#include "timer.h"
#include "scene.h"
#include "mainscene.h"

const int FPS = 1;
const int MS_PER_TICK = 1000/FPS;

Game::Game()
{
  graphics     = new Graphics();
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
  Input input;

  timer->stamp();
  while(!SDL_PollEvent(&event) || event.type != SDL_QUIT)
  {
    tickSeconds += timer->msSinceStamp();
    timer->stamp();

    while(tickSeconds > MS_PER_TICK)
    {
      tickSeconds -= MS_PER_TICK;

      tickInput(event, input);
      tickLogic(input);
      tickGraphics();
    }
  }
}

void Game::tickInput(const SDL_Event& e, Input& i)
{
  InputHandler::takeInput(e, i);
}

void Game::tickLogic(const Input& i)
{
  scene->tick(i);
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
  delete timer;
  delete mainScene;
}

