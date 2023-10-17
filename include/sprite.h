#ifndef GAME_ENGINE_SPRITE_H
#define GAME_ENGINE_SPRITE_H

#include "SDL_rect.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "point.h"
#include "window.h"

struct sprite_s
{
    SDL_Texture *texture;
    SDL_Rect rect;
    point_t position;
};
typedef struct sprite_s sprite_t;

sprite_t *sprite_create(char *path, SDL_Rect display_rect, window_t *window);
void sprite_render(sprite_t *sprite, window_t *window);
void sprite_destroy(sprite_t *sprite);

#endif // !GAME_ENGINE_SPRITE_H
