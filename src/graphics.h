struct SDL_Surface;

class Graphics
{
  private:
    SDL_Surface *screen;
  public:
    Graphics();
    ~Graphics();

    void render(Renderer &r);
};

