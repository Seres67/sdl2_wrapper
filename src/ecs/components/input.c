#include <ecs/components/input.h>
#include <ecs/entity.h>

void entity_add_input_component(int entity)
{
    COMPONENT_LIST.input[entity].active = 1;
    COMPONENT_LIST.total_input_components += 1;
}
