#ifndef _MAZERENDERER_H
#define _MAZERENDERER_H

#include "renderer.h"
class Maze;
class MazeRenderer : class Renderer
{
  private:
    SDL_Surface *top;
    SDL_Surface *right;
    SDL_Surface *bottom;
    SDL_Surface *left;
  public:
    MazeRenderer();
    ~MazeRenderer();
    void render(const Maze& m, const Graphics& g);
};

#endif

