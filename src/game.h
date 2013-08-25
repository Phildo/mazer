class Render;
class InputHandler;
class Timer;

class Game
{
  private:
    Render *render;
    InputHandler *inputHandler;
    Timer *timer;

    void tick();

  public:
    Game();
    ~Game();

    void initialize();
    void run();
};

