#include "mainscene.h"

#include "maze.h"
#include "player.h"
#include "mazerenderer.h"
#include "playerrenderer.h"
#include "inputhandler.h"

MainScene::MainScene()
{
  maze = new Maze(40,30);
  player = new Player(1,1);

  mazeRenderer = new MazeRenderer();
  playerRenderer = new PlayerRenderer();
}

void MainScene::render(const Graphics* g) const
{
  mazeRenderer->render(maze, g);
  playerRenderer->render(player, g);
}

void MainScene::tick(const Input& i)
{
  player->move((int)i.up, (int)i.down, (int)i.left, (int)i.right);
}

MainScene::~MainScene()
{
  delete maze;
  delete mazeRenderer;
}

