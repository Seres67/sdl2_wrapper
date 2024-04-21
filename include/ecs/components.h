#ifndef SDL2_WRAPPER_COMPONENTS_H
#define SDL2_WRAPPER_COMPONENTS_H

#include "ecs/components/drawable.h"
#include "ecs/components/gravity.h"
#include "ecs/components/health.h"
#include "ecs/components/input.h"
#include "ecs/components/position.h"

typedef struct
{
    wrapper_pos position[100];
    wrapper_health health[100];
    wrapper_drawable drawable[100];
    wrapper_input input[100];
    wrapper_gravity gravity[100];
    int total_pos_components;
    int total_health_components;
    int total_drawable_components;
    int total_input_components;
    int total_gravity_components;
} wrapper_component_list;

#endif // !SDL2_WRAPPER_COMPONENTS_H
