class Graphics;
class InputHandler;
class Timer;
class Maze;
class MazeRenderer;

class Game
{
  private:
    Graphics *graphics;
    InputHandler *inputHandler;
    Timer *timer;
    Maze *maze;
    MazeRenderer *mazerenderer;

    void tick();
    void tickLogic();
    void tickGraphics();

  public:
    Game();
    ~Game();

    void initialize();
    void run();
};

