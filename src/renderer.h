#ifndef _RENDERER_H
#define _RENDERER_H

struct SDL_Surface;
class Graphics;

class Renderer
{
  protected:
    void load_image(const char& filename, SDL_Surface& surface);
    void apply_surface(int x, int y, const SDL_Surface& source, SDL_Surface& destination, SDL_Rect *clip = NULL);
    SDL_Surface* sprite;
  public:
    virtual void render(const Graphics& g) = 0;
};

#endif

