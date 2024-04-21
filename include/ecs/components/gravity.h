#ifndef SDL2_WRAPPER_GRAVITY_H
#define SDL2_WRAPPER_GRAVITY_H

typedef struct
{
    float multiplier;
    _Bool active;
} wrapper_gravity;

void entity_add_gravity_component(int entity, float multiplier);

#endif // !SDL2_WRAPPER_GRAVITY_H
