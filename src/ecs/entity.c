#include "SDL_events.h"
#include "SDL_render.h"
#include "window.h"
#include <ecs/entity.h>
#include <stdio.h>

int ENTITIES = 0;
wrapper_component_list COMPONENT_LIST;

int entity_create(void) { return ENTITIES++; }

void entity_delete(int entity)
{
    if (COMPONENT_LIST.health[entity].active) {
        COMPONENT_LIST.health[entity].max_health = 0;
        COMPONENT_LIST.health[entity].curr_health = 0;
        COMPONENT_LIST.health[entity].active = 0;
        COMPONENT_LIST.total_health_components--;
    }
    if (COMPONENT_LIST.position[entity].active) {
        COMPONENT_LIST.position[entity].x = 0;
        COMPONENT_LIST.position[entity].y = 0;
        COMPONENT_LIST.position[entity].active = 0;
        COMPONENT_LIST.total_pos_components--;
    }
    if (COMPONENT_LIST.drawable[entity].active) {
        SDL_DestroyTexture(COMPONENT_LIST.drawable[entity].texture);
        COMPONENT_LIST.drawable[entity].active = 0;
        COMPONENT_LIST.total_drawable_components--;
    }
    if (COMPONENT_LIST.input[entity].active == 1) {
        COMPONENT_LIST.input[entity].active = 0;
        COMPONENT_LIST.total_input_components--;
    }
}

void entity_update_health_component(void)
{
    for (int entity = 0; entity <= COMPONENT_LIST.total_health_components;
         ++entity) {
        if (COMPONENT_LIST.health[entity].active &&
            COMPONENT_LIST.health[entity].curr_health <= 0)
            entity_delete(entity);
    }
}

void entity_update_drawable_component(wrapper_window *window)
{
    for (int entity = 0; entity <= COMPONENT_LIST.total_drawable_components;
         ++entity) {
        if (COMPONENT_LIST.drawable[entity].active) {
            if (COMPONENT_LIST.position[entity].active) {
                COMPONENT_LIST.drawable[entity].rect.x =
                    COMPONENT_LIST.position[entity].x;
                COMPONENT_LIST.drawable[entity].rect.y =
                    COMPONENT_LIST.position[entity].y;
                SDL_QueryTexture(COMPONENT_LIST.drawable[entity].texture, NULL,
                                 NULL, &COMPONENT_LIST.drawable[entity].rect.w,
                                 &COMPONENT_LIST.drawable[entity].rect.h);
                SDL_RenderCopy(window->renderer,
                               COMPONENT_LIST.drawable[entity].texture, NULL,
                               &COMPONENT_LIST.drawable[entity].rect);
            } else {
                SDL_RenderCopy(window->renderer,
                               COMPONENT_LIST.drawable[entity].texture, NULL,
                               NULL);
            }
        }
    }
}

void entity_update_input_component(SDL_Event event)
{
    for (int entity = 0; entity <= COMPONENT_LIST.total_input_components;
         ++entity) {
        if (COMPONENT_LIST.input[entity].active) {
            switch (event.type) {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_a:
                    COMPONENT_LIST.position[entity].x += 5;
                    break;
                }
                break;
            default:
                break;
            }
        }
    }
}

void entity_update_gravity_component()
{
    for (int entity = 0; entity <= COMPONENT_LIST.total_gravity_components;
         ++entity) {
        if (COMPONENT_LIST.gravity[entity].active) {
            COMPONENT_LIST.position[entity].y -=
                1.f * COMPONENT_LIST.gravity[entity].multiplier;
        }
    }
}
