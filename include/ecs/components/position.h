#ifndef SDL2_WRAPPER_POSITION_H
#define SDL2_WRAPPER_POSITION_H

typedef struct
{
    int x;
    int y;
    _Bool active;
} wrapper_pos;

void entity_add_position_component(int entity, int x, int y);

#endif // !SDL2_WRAPPER_POSITION_H
