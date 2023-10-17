#ifndef GAME_ENGINE_WINDOW_H
#define GAME_ENGINE_WINDOW_H

#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include <SDL2/SDL.h>

struct window_s
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    _Bool open;
};

typedef struct window_s window_t;

window_t *window_create(char *title, int x, int y);
_Bool window_isopen(window_t *window);
void window_close(window_t *window);
void window_clear(window_t *window);
void window_update(window_t *window);
void window_destroy(window_t *window);

#endif // !GAME_ENGINE_WINDOW_H
