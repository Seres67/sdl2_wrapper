#include "SDL.h"
#include "SDL_events.h"
#include "SDL_timer.h"
#include "SDL_video.h"
#include "game_engine.h"
#include "player.h"
#include "sprite.h"
#include "window.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

int main(int ac, char *av[])
{
    game_engine_init();
    window_t *win = window_create("testing", 0, 0);
    if (!win) {
        return 1;
    }
    player_t *player =
        create_player("../res/prout.jpg", (SDL_Rect){0, 0, 256, 256}, win);
    if (!player) {
        return 1;
    }
    SDL_Event e;
    while (window_isopen(win)) {
        uint64_t start = SDL_GetPerformanceCounter();
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT:
                window_close(win);
                break;

            default:
                break;
            }
        }
        window_clear(win);
        sprite_render(player->sprite, win);
        window_update(win);
        uint64_t end = SDL_GetPerformanceCounter();
        float elapsed =
            (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.f;
        SDL_Delay(floor(16.333f - elapsed));
    }
    sprite_destroy(player->sprite);
    free(player);
    window_destroy(win);
    SDL_Quit();
    return 0;
}
