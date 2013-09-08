#include "renderer.h"

class MazeRender : class Renderer
{
  private:
    SDL_Surface *top;
    SDL_Surface *right;
    SDL_Surface *bottom;
    SDL_Surface *left;
  public:
    Render();
    ~Render();
    void draw(MazeBlock *blocks);
};

