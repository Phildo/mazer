#ifndef _MAZERENDERER_H_
#define _MAZERENDERER_H_

#include "renderer.h"

class Maze;

class MazeRenderer : public Renderer
{
  private:
    SDL_Surface *top;
    SDL_Surface *right;
    SDL_Surface *bottom;
    SDL_Surface *left;
  public:
    MazeRenderer();
    ~MazeRenderer();
    void render(void* v, const Graphics* g) const;
};

#endif

