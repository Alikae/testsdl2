SRC = src/main.cpp src/init_sdl.c src/game_core.cpp src/sprite.c src/init_game_helper.c src/physical_object.c src/t_sprite_lst.c src/t_object_lst.c src/input_handling.c src/render_screen.c src/t_chunk.c

INCLUDE = -Iinclude -Iinclude/SDL

LIB = -l SDL2

all:
	g++ -Wall -Wextra -x c++ $(SRC) -x c++ $(SRCPP) $(INCLUDE) $(LIB)

debug:
	g++ -g -x c++ $(SRC) -x c++ $(SRCPP) $(INCLUDE) $(LIB)
