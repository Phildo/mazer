#ifndef _GAME_H_
#define _GAME_H_

class Graphics;
//class InputHandler;
class Timer;
class Scene;
class MainScene;

class Game
{
  private:
    Graphics* graphics;
    //InputHandler* inputHandler;
    Timer* timer;
    Scene* scene;

    MainScene* mainScene;

    void tick();
    void tickLogic();
    void tickGraphics();

  public:
    Game();
    ~Game();

    void initialize();
    void run();
};

#endif

