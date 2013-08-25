#include "timer.h"
#include <SDL/SDL.h>

Timer::Timer()
{

}

void Timer::stamp()
{
  stampTime = SDL_GetTicks();
}

int Timer::msSinceStamp()
{
  return SDL_GetTicks() - stampTime;
}

Timer::~Timer()
{

}

