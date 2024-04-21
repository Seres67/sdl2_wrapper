#include <SDL_image.h>
#include <ecs/components/drawable.h>
#include <ecs/entity.h>
#include <stdio.h>

void entity_add_drawable_component(int entity, char *texture_path,
                                   wrapper_window *window)
{
    SDL_Surface *surface = IMG_Load(texture_path);
    if (!surface)
        return;
    COMPONENT_LIST.drawable[entity].texture =
        SDL_CreateTextureFromSurface(window->renderer, surface);
    if (!COMPONENT_LIST.drawable[entity].texture)
        return;
    SDL_FreeSurface(surface);
    COMPONENT_LIST.drawable[entity].rect = (SDL_Rect){0, 0, 0, 0};
    COMPONENT_LIST.drawable[entity].active = 1;
    COMPONENT_LIST.total_drawable_components += 1;
    printf("adding drawable to %d\n", entity);
}
