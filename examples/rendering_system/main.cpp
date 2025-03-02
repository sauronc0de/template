#include "rendering_system.h"
#include <iostream>

int main(int argc, char *args[])
{
  {
    //* Create rendering system
    RenderingSystemAO *renderingSystem = new RenderingSystemAO();
    bool quit = false;
    SDL_Event event;
    while(!quit)
    {
      // Example of input events. Pending to create an AO with this:
      while(SDL_PollEvent(&event))
      {
        if(event.type == SDL_QUIT)
        {
          quit = true;
        }
      }

      // Update renderer
      renderingSystem->update();
    }
  }
  //* Destroy rendering system

  return 0;
}
