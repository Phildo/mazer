#ifndef _GAME_H_
#define _GAME_H_

class Graphics;
class InputHandler;
class Timer;
class Scene;
class MainScene;

union SDL_Event;
struct Input;

class Game
{
  private:
    Graphics* graphics;
    InputHandler* inputHandler;
    Timer* timer;
    Scene* scene;

    MainScene* mainScene;

    void tickInput(const SDL_Event& e, Input& i);
    void tickLogic(const Input& i);
    void tickGraphics();

  public:
    Game();
    ~Game();

    void initialize();
    void run();
};

#endif

