class Timer
{
  private:
    int stampTime;
  public:
    Timer();
    ~Timer();
    
    void stamp();
    int msSinceStamp();
};

