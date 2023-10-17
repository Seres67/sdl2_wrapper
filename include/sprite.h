#ifndef GAME_ENGINE_SPRITE_H
#define GAME_ENGINE_SPRITE_H

#include "SDL_rect.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "point.h"
#include "window.h"

struct sprite_s
{
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect rect;
    point_t point;
};
typedef struct sprite_s sprite_t;

sprite_t *sprite_create(char *path, int x, int y, int rect_width,
                        int rect_height, window_t *window);

void sprite_render(sprite_t *sprite, window_t *window);
void sprite_destroy(sprite_t *sprite);

#endif // !GAME_ENGINE_SPRITE_H
