class Render;
class EventHandler;

class Game
{
  private:
    Render *render;
    EventHandler *eventHandler;
    
    bool quit;
  public:
    Game();
    ~Game();

    void begin();
};

