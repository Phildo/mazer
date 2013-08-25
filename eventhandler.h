#include <SDL/SDL.h>

class EventHandler
{
  private:
    SDL_Event event;
  public:
    EventHandler();

    bool requestsQuit();
};

