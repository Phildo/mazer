class Render;
class InputHandler;
class Timer;

class Game
{
  private:
    Render *render;
    InputHandler *inputHandler;
    Timer *timer;

  public:
    Game();
    ~Game();

    void run();
};

