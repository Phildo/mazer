#ifndef _RENDERER_H_
#define _RENDERER_H_

struct SDL_Surface;
struct SDL_Rect;
class Graphics;

class Renderer
{
  protected:
    void load_image(const char* filename, SDL_Surface* surface);
    void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = 0);
    SDL_Surface* sprite;
  public:
    Renderer();
    virtual ~Renderer() = 0;
    virtual void render(void* r, const Graphics* g) = 0;
};

#endif

