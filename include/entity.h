#ifndef GAME_ENGINE_ENTITY_H
#define GAME_ENGINE_ENTITY_H

#include <include/components/position.h>
#include <include/sprite.h>

struct entity_s
{
    sprite_t *sprite;
    point_t position;
};

typedef struct entity_s entity_t;

#endif // !GAME_ENGINE_ENTITY_H
