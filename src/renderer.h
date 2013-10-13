#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "renderutils.h"

class Graphics;

class Renderer
{
  public:
    virtual ~Renderer() {};
    virtual void render(void* r, const Graphics* g) const = 0;
};

#endif

