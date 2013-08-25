class SDL_Surface;

class Render
{
  private:
    SDL_Surface *screen;
  public:
    Render();
    void render();
};

