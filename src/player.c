#include "sprite.h"
#include "window.h"
#include <include/player.h>

player_t *create_player(char *sprite_path, SDL_Rect display_rect,
                        window_t *window)
{
    player_t *player = (player_t *)malloc(sizeof(player_t));
    if (!player) {
        fprintf(stderr, "couldn't alloc player\n");
        return NULL;
    }
    player->position = (point_t){display_rect.x, display_rect.y};
    player->sprite = sprite_create(sprite_path, display_rect, window);
    return player;
}
