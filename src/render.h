struct SDL_Surface;
struct MazeBlock;

class Render
{
  private:
    SDL_Surface *screen;
    SDL_Surface *face;
    SDL_Surface *top;
    SDL_Surface *right;
    SDL_Surface *bottom;
    SDL_Surface *left;
  public:
    Render();
    ~Render();
    void draw(MazeBlock *blocks);
};

