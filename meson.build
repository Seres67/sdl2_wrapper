project('game_engine', 'c', default_options: ['warning_level=3','b_sanitize=none', 'c_std=c11'])
include_dir = include_directories('include')
src = ['src/main.c', 'src/game_engine.c', 'src/window.c', 'src/sprite.c', 'src/player.c']
cc = meson.get_compiler('c')
sdl2 = dependency('sdl2', required: true)
sdl2_gfx = dependency('SDL2_gfx', required: true)
sdl2_image = dependency('sdl2_image', required: true)
math = cc.find_library('m', required: true)
executable('game_engine', src, c_args: '-fms-extensions', include_directories: include_dir, dependencies: [sdl2, sdl2_gfx, sdl2_image, math])
