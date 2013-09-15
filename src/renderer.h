struct SDL_Surface;
class Renderer
{
  protected:
    void load_image(const char& filename, SDL_Surface& surface);
    void apply_surface(int x, int y, const SDL_Surface& source, SDL_Surface& destination, SDL_Rect *clip = NULL);
    SDL_Surface* sprite;
  public:
    virtual Renderer() = 0;
    virtual ~Renderer() = 0;

    virtual void render(Graphics *g) = 0;
};

