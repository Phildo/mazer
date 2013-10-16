#ifndef _MAZE_H_
#define _MAZE_H_

enum MazeBlockWallType
{
  WALL_NONE         = 0,
  WALL_TOP          = 1,
  WALL_RIGHT        = 2,
  WALL_TOP_RIGHT    = 3,  //TOP | RIGHT
  WALL_BOTTOM       = 4,
  WALL_VERTICAL     = 5,  //TOP | BOTTOM
  WALL_RIGHT_BOTTOM = 6,  //RIGHT | RIGHT
  WALL_LEFT         = 8,
  WALL_LEFT_TOP     = 9,  //LEFT | TOP
  WALL_HORIZONTAL   = 10, //LEFT | RIGHT
  WALL_BOTTOM_LEFT  = 12, //BOTTOM | LEFT
  WALL_ALL          = 15  //TOP | RIGHT | BOTTOM | LEFT
};

struct MazeBlock
{
  int x;
  int y;
  MazeBlockWallType type;
};

class Maze
{
  private:
    MazeBlock *blocks;
    int height;
    int width;

    bool wallOpen(  MazeBlock& block, MazeBlockWallType t) const;
    bool wallClosed(MazeBlock& block, MazeBlockWallType t) const;
    void closeBlockWall(       MazeBlock* blocks, int x, int y, MazeBlockWallType t) const;
    void openBlockWall(        MazeBlock* blocks, int x, int y, MazeBlockWallType t) const;
    bool hasUntouchedNeighbors(MazeBlock* blocks, int x, int y) const;
    MazeBlock *generate();
  public:
    Maze(int w, int h);
    ~Maze();

    int getHeight() const;
    int getWidth() const;
    bool isValidMove(int srcX, int srcY, int destX, int destY) const;
    MazeBlock *getBlocks() const;
};

#endif

