#ifndef _TIMER_H
#define _TIMER_H

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

#endif

