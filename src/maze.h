enum MazeBlockType
{
  CLOSE_NONE         = 0,
  CLOSE_TOP          = 1,
  CLOSE_RIGHT        = 2,
  CLOSE_TOP_RIGHT    = 3,  //CLOSE_TOP | CLOSE_RIGHT
  CLOSE_BOTTOM       = 4,
  CLOSE_VERTICAL     = 5,  //CLOSE_TOP | CLOSE_BOTTOM
  CLOSE_RIGHT_BOTTOM = 6,  //CLOSE_RIGHT | CLOSE_RIGHT
  CLOSE_LEFT         = 8,
  CLOSE_LEFT_TOP     = 9,  //CLOSE_LEFT | CLOSE_TOP
  CLOSE_HORIZONTAL   = 10, //CLOSE_LEFT | CLOSE_RIGHT
  CLOSE_BOTTOM_LEFT  = 12, //CLOSE_BOTTOM | CLOSE_LEFT
  CLOSE_ALL          = 15  //CLOSE_TOP | CLOSE_RIGHT | CLOSE_BOTTOM | CLOSE_LEFT
};

struct MazeBlock
{
  int x;
  int y;
  MazeBlockType type;
};

class Maze
{
  private:
    MazeBlock *blocks;
    int height;
    int width;
  public:
    Maze(int x, int y);
    ~Maze();

    MazeBlock *getBlocks();
};

