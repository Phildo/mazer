struct SDL_Surface;

class Render
{
  private:
    SDL_Surface *screen;
    SDL_Surface *face;
  public:
    Render();
    ~Render();
    void draw();
};

