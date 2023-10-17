#include "include/window.h"
#include "SDL_pixels.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include <stdio.h>

window_t *window_create(char *title, int x, int y)
{
    window_t *window = (window_t *)malloc(sizeof(window_t));
    if (!window) {
        fprintf(stderr, "couldn't allocate %s:%d", __FILE__, __LINE__);
        return NULL;
    }
    window->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                                      SDL_WINDOWPOS_UNDEFINED, x, y,
                                      SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (!window->window) {
        fprintf(stderr, "couldn't create window\n");
        return NULL;
    }
    window->renderer =
        SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED);
    if (!window->renderer) {
        fprintf(stderr, "couldn't create renderer\n");
        return NULL;
    }
    window->open = 1;
    return window;
}

_Bool window_isopen(window_t *window) { return window->open; }

void window_close(window_t *window) { window->open = 0; }

void window_clear(window_t *window) { SDL_RenderClear(window->renderer); }

void window_update(window_t *window) { SDL_RenderPresent(window->renderer); }

void window_destroy(window_t *window)
{
    SDL_DestroyRenderer(window->renderer);
    SDL_DestroyWindow(window->window);
    free(window);
}
