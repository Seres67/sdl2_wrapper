#ifndef SDL2_WRAPPER_DRAWABLE_H
#define SDL2_WRAPPER_DRAWABLE_H

#include "window.h"

typedef struct
{
    SDL_Texture *texture;
    SDL_Rect rect;
    _Bool active;
} wrapper_drawable;

void entity_add_drawable_component(int entity, char *texture_path,
                                   wrapper_window *window);

#endif // !SDL2_WRAPPER_DRAWABLE_H
