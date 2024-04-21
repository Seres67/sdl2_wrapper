#ifndef SDL2_WRAPPER_WINDOW_H
#define SDL2_WRAPPER_WINDOW_H

#include "point.h"
#include <SDL2/SDL_render.h>

typedef struct
{
    SDL_Renderer *renderer;
    SDL_Window *window;
} wrapper_window;

wrapper_window *wrapper_create_window(const char *title, wrapper_vector_2d pos,
                                      wrapper_vector_2d size);
void wrapper_window_close(wrapper_window *window);
void wrapper_window_render(wrapper_window *window);
void wrapper_window_clear(wrapper_window *window, wrapper_vector_4d color);

#endif // !SDL2_WRAPPER_WINDOW_H
