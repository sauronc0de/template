#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <string>
#include <stdexcept>
#include <vector>

struct Sprite
{
  SDL_Texture *texture;
  SDL_Rect source;      // Crop from image
  SDL_Rect destination; // Draw on screen
};

class RenderingSystemAO
{
private:
  static constexpr size_t screen_width = 640;
  static constexpr size_t screen_height = 480;
  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
  std::vector<Sprite> sprites;

public:
  RenderingSystemAO()
  {
    // Init SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      throw std::runtime_error(std::string("Could not initialize SDL2: ") + SDL_GetError());
    }

    // Init window
    window = SDL_CreateWindow("DnT4", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, screen_width,
                              screen_height, SDL_WINDOW_SHOWN);
    if(!window)
    {
      throw std::runtime_error(std::string("could not create window: ") + SDL_GetError());
    }

    // Init renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer)
    {
      throw std::runtime_error(std::string("could not create renderer: ") + SDL_GetError());
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
  }

  ~RenderingSystemAO()
  {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
  }

  void update()
  {
    // Clear current renderer
    SDL_RenderClear(renderer);

    // Add all the sprites in the list
    for(auto sprite : sprites)
    {
      SDL_RenderCopy(renderer, sprite.texture, &sprite.source, &sprite.destination);
    }

    // Present the result
    SDL_RenderPresent(renderer);
  }

  void add_sprite(const Sprite &sprite)
  {
    sprites.push_back(sprite);
  }
};