#include <ecs/components/health.h>
#include <ecs/entity.h>

void entity_add_health_component(int entity)
{
    COMPONENT_LIST.health[entity].curr_health = 100;
    COMPONENT_LIST.health[entity].max_health = 100;
    COMPONENT_LIST.health[entity].active = 1;
    COMPONENT_LIST.total_health_components += 1;
}
