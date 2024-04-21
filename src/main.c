#include "ecs/components/drawable.h"
#include "ecs/components/health.h"
#include "ecs/components/input.h"
#include "ecs/components/position.h"
#include "ecs/entity.h"
#include "point.h"
#include "window.h"
#include <SDL2/SDL_events.h>

_Bool handle_events(void)
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        entity_update_input_component(e);
        switch (e.type) {
        case SDL_QUIT:
            return 1;
            break;
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    wrapper_window *window = wrapper_create_window(
        "test", (wrapper_vector_2d){0, 0}, (wrapper_vector_2d){720, 480});

    entity_create();
    int entity = entity_create();
    entity_add_position_component(entity, 0, 0);
    entity_add_health_component(entity);
    entity_add_drawable_component(entity, "test.png", window);
    entity_add_input_component(entity);
    while (1) {
        wrapper_window_clear(window, (wrapper_vector_4d){0, 0, 0, 255});
        if (handle_events())
            break;
        entity_update_health_component();
        entity_update_drawable_component(window);
        wrapper_window_render(window);
    }
    entity_delete(0);
    entity_delete(1);
    wrapper_window_close(window);
    return 0;
}
