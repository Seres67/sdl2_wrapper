#ifndef SDL2_WRAPPER_HEALTH_H
#define SDL2_WRAPPER_HEALTH_H

typedef struct
{
    int curr_health;
    int max_health;
    _Bool active;
} wrapper_health;

void entity_add_health_component(int entity);

#endif // !SDL2_WRAPPER_HEALTH_H
