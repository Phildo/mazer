#include "mainscene.h"

#include "maze.h"
#include "mazerenderer.h"

MainScene::MainScene()
{
  maze = new Maze(40,30);
  mazeRenderer = new MazeRenderer();
}

void MainScene::render(const Graphics* g) const
{
  mazeRenderer->render(maze, g);
}

void MainScene::tick(const Input& i)
{
}

MainScene::~MainScene()
{
  delete maze;
  delete mazeRenderer;
}

