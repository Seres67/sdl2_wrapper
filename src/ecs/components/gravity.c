#include "ecs/entity.h"
#include <ecs/components/gravity.h>

void entity_add_gravity_component(int entity, float multiplier)
{
    COMPONENT_LIST.gravity[entity].active = 1;
    COMPONENT_LIST.gravity[entity].multiplier = multiplier;
    COMPONENT_LIST.total_gravity_components += 1;
}
