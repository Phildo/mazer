#ifndef _PLAYERRENDERER_H_
#define _PLAYERRENDERER_H_

#include "renderer.h"

class PlayerRenderer : public Renderer
{
  private:
  public:
    PlayerRenderer();
    ~PlayerRenderer();
    void render(void* r, const Graphics* g) const;
};

#endif

