enum MazeBlockType
{
  OPEN_TOP          = 1,
  OPEN_RIGHT        = 2,
  OPEN_TOP_RIGHT    = 3,  //OPEN_TOP | OPEN_RIGHT
  OPEN_BOTTOM       = 4,
  OPEN_VERTICAL     = 5,  //OPEN_TOP | OPEN_BOTTOM
  OPEN_RIGHT_BOTTOM = 6,  //OPEN_RIGHT | OPEN_RIGHT
  OPEN_LEFT         = 8,
  OPEN_LEFT_TOP     = 9,  //OPEN_LEFT | OPEN_TOP
  OPEN_HORIZONTAL   = 10, //OPEN_LEFT | OPEN_RIGHT
  OPEN_BOTTOM_LEFT  = 12, //OPEN_BOTTOM | OPEN_LEFT
  OPEN_ALL          = 15  //OPEN_TOP | OPEN_RIGHT | OPEN_BOTTOM | OPEN_LEFT
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
    void generate(int x, int y);
  public:
    Maze(int x, int y);
    ~Maze();

    MazeBlock *getBlocks();
};

