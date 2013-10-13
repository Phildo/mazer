#ifndef _MAIN_SCENE_H_
#define _MAIN_SCENE_H_

#include "scene.h"

class Maze;
class MazeRenderer;
struct Input;

class MainScene : public Scene
{
  private:
    Maze* maze;
    MazeRenderer* mazeRenderer;
  public:
    MainScene();
    ~MainScene();

    void render(const Graphics* g) const;
    void tick(const Input& i);
};

#endif

