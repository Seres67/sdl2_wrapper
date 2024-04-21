#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <window.h>

wrapper_window *wrapper_create_window(const char *title, wrapper_vector_2d pos,
                                      wrapper_vector_2d size)
{
    wrapper_window *window = malloc(sizeof(wrapper_window));

    if (!window)
        return NULL;
    window->window = SDL_CreateWindow(title, pos.x, pos.x, size.x, size.y, 0);
    if (!window->window)
        return NULL;
    window->renderer =
        SDL_CreateRenderer(window->window, -1, SDL_RENDERER_SOFTWARE);
    if (!window->renderer)
        return NULL;
    return window;
}

void wrapper_window_close(wrapper_window *window)
{
    SDL_DestroyRenderer(window->renderer);
    SDL_DestroyWindow(window->window);
    free(window);
}

void wrapper_window_render(wrapper_window *window)
{
    SDL_RenderPresent(window->renderer);
}

void wrapper_window_clear(wrapper_window *window, wrapper_vector_4d color)
{
    SDL_SetRenderDrawColor(window->renderer, color.i, color.j, color.k,
                           color.l);
    SDL_RenderClear(window->renderer);
}
