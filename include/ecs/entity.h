#ifndef SDL2_WRAPPER_ENTITY_H
#define SDL2_WRAPPER_ENTITY_H

#include "SDL_events.h"
#include "ecs/components.h"
#include "window.h"

extern int ENTITIES;
extern wrapper_component_list COMPONENT_LIST;

int entity_create(void);
void entity_delete(int entity);
void entity_update_health_component(void);
void entity_update_drawable_component(wrapper_window *window);
void entity_update_input_component(SDL_Event event);
#endif // !SDL2_WRAPPER_ENTITY_H
