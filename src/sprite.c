#include "SDL_image.h"
#include "SDL_rect.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include "point.h"
#include <include/sprite.h>
#include <stdio.h>

sprite_t *sprite_create(char *path, SDL_Rect display_rect, window_t *window)
{
    sprite_t *sprite = (sprite_t *)malloc(sizeof(sprite_t));
    if (!sprite) {
        fprintf(stderr, "couldn't alloc sprite\n");
        return NULL;
    }
    SDL_Surface *surface = IMG_Load(path);
    if (!surface) {
        fprintf(stderr, "couldn't load img\n");
        return NULL;
    }
    sprite->texture = SDL_CreateTextureFromSurface(window->renderer, surface);
    if (!sprite->texture) {
        fprintf(stderr, "couldn't create texture from surface\n");
        return NULL;
    }
    sprite->rect = display_rect;
    sprite->position = (point_t){display_rect.x, display_rect.y};
    return sprite;
}

void sprite_render(sprite_t *sprite, window_t *window)
{
    SDL_RenderCopy(window->renderer, sprite->texture, NULL, &sprite->rect);
}

void sprite_destroy(sprite_t *sprite)
{
    SDL_DestroyTexture(sprite->texture);
    free(sprite);
}
