#ifndef _GRAPHICS_H
#define _GRAPHICS_H

struct SDL_Surface;

class Graphics
{
  private:
    SDL_Surface* screen;
  public:
    Graphics();
    ~Graphics();

    SDL_Surface* screen();
};

#endif

