#ifndef _INPUTHANDLER_H_
#define _INPUTHANDLER_H_

union SDL_Event;

struct Input
{
  bool up;
  bool down;
  bool left;
  bool right;
};

namespace InputHandler
{
    void takeInput(const SDL_Event& e, Input& i);
};

#endif

