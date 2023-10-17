#include "SDL_image.h"
#include "SDL_render.h"
#include "SDL_surface.h"
#include <include/sprite.h>
#include <stdio.h>

sprite_t *sprite_create(char *path, int x, int y, int rect_width,
                        int rect_height, window_t *window)
{
    sprite_t *sprite = (sprite_t *)malloc(sizeof(sprite_t));
    if (!sprite) {
        fprintf(stderr, "couldn't alloc sprite\n");
        return NULL;
    }
    sprite->surface = IMG_Load(path);
    if (!sprite->surface) {
        fprintf(stderr, "couldn't load image %s\n", path);
        return NULL;
    }
    sprite->texture =
        SDL_CreateTextureFromSurface(window->renderer, sprite->surface);
    if (!sprite->texture) {
        fprintf(stderr, "couldn't create texture from surface\n");
        return NULL;
    }
    sprite->rect.w = rect_width;
    sprite->rect.h = rect_height;
    sprite->point.x = x;
    sprite->point.y = y;
    SDL_FreeSurface(sprite->surface);
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
