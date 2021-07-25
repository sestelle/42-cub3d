NAME	=	cub3D

CC	=	gcc
CFLAGS	=	-I ./include -I ./common/libft -I ./common/libmlx -Wall -Wextra -Werror

FRAMEWORKS	=	-framework OpenGL -framework AppKit

LIBS	=	./common/libft/libft.a ./common/libmlx/libmlx.a

INCLUDES	=	$(addprefix ./include/, cub3d.h engine.h events.h read_config.h structs.h)

SRC_ENGINE	=	$(addprefix engine/, screenshot/create_screenshot.c $(addprefix events/, events_press.c events_release.c events.c events_rotations.c events_movements.c close_button.c ) $(addprefix rendering/, rendering_background.c rendering.c $(addprefix rendering_sprites/, calculations.c draw_sprite_textures.c find_sprites.c rendering_sprites.c sort_sprites.c) \
				$(addprefix rendering_walls/, calculations.c dda_alg.c draw_textures.c rendering_walls.c tex_num.c)) $(addprefix utilities/, load_textures.c pixel_put.c) engine.c)

SRC_PARSER	=	$(addprefix read_config/, read_color.c read_config.c read_map.c read_plr.c read_resolution.c read_texture.c $(addprefix utilities/, convert_rgb.c find_line.c open_file.c split_size.c) $(addprefix check_map/, recreate_map.c check_map.c flood_fill.c))

SRC_MAIN	=	$(addprefix main/, main.c check_args.c)

SRC_UTILITIES	=	$(addprefix utilities/, print_error.c)

SRC		=	$(addprefix source/, $(SRC_MAIN) $(SRC_PARSER) $(SRC_ENGINE) $(SRC_UTILITIES))

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./common/libft && make -C ./common/libmlx
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS) $(FRAMEWORKS)

clean:
	make -C ./common/libft clean && make -C ./common/libmlx clean
	rm -f $(OBJ)

fclean: clean
	make -C ./common/libft fclean && make -C ./common/libmlx fclean
	rm -f $(NAME)

re: fclean all

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@
