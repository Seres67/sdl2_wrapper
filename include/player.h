#ifndef GAME_ENGINE_PLAYER_H
#define GAME_ENGINE_PLAYER_H

#include "SDL_rect.h"
#include <include/entity.h>
#include <include/sprite.h>

struct player_s
{
    entity_t;
};
typedef struct player_s player_t;

player_t *create_player(char *sprite_path, SDL_Rect display_rect,
                        window_t *window);

#endif // !GAME_ENGINE_PLAYER_H
