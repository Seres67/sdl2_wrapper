#include <ecs/components/position.h>
#include <ecs/entity.h>

void entity_add_position_component(int entity, int x, int y)
{
    COMPONENT_LIST.position[entity].x = x;
    COMPONENT_LIST.position[entity].y = y;
    COMPONENT_LIST.position[entity].active = 1;
    COMPONENT_LIST.total_pos_components += 1;
}
