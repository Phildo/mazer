class Render;
class InputHandler;
class Timer;
class Maze;

class Game
{
  private:
    Render *render;
    InputHandler *inputHandler;
    Timer *timer;
    Maze *maze;

    void tick();

  public:
    Game();
    ~Game();

    void initialize();
    void run();
};

