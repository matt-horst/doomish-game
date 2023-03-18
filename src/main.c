#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <SDL2/SDL.h>

#define ASSERT(_e, ...) if (!(_e)) { fprintf(stderr, __VA_ARGS__); exit(1); }

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct
{
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *texture;
  uint32_t pixels[SCREEN_WIDTH * SCREEN_HEIGHT];
  bool quit;
} State;

int main()
{
  ASSERT(
      SDL_Init(SDL_INIT_VIDEO) == 0,
      "SDL failed to initialize: %s\n", SDL_GetError());

  State state;

  state.window = SDL_CreateWindow(
    "Demo",
    SDL_WINDOWPOS_CENTERED_DISPLAY(0),
    SDL_WINDOWPOS_CENTERED_DISPLAY(0),
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    0);

  ASSERT(
      state.window != NULL,
      "SLD failed to create window: %s\n", SDL_GetError());

  state.quit = false;
  while (!state.quit)
  {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT) state.quit = true;
    }
  }

  SDL_DestroyWindow(state.window);
  return 0;
}
