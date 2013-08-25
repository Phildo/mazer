class Render;
class InputHandler;

class Game
{
  private:
    Render *render;
    InputHandler *inputHandler;
    
    bool quit;
  public:
    Game();
    ~Game();

    void run();
};

