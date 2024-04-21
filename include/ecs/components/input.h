#ifndef SDL2_WRAPPER_INPUT_H
#define SDL2_WRAPPER_INPUT_H

typedef struct
{
    _Bool active;
} wrapper_input;

void entity_add_input_component(int entity);

#endif // !SDL2_WRAPPER_INPUT_H
