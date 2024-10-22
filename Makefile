NAME = so_long

NAMEBONUS = so_long_bonus

SOURCES =	src/ft_so_long.c src/read_map.c src/build_map.c src/move_player.c src/load_images.c src/validate_map.c src/validate_playable.c src/map_errors.c src/free_images.c src/big_map_helper.c \

BONUS = srcbonus/ft_so_long_bonus.c srcbonus/read_map_bonus.c srcbonus/build_map_bonus.c srcbonus/move_player_bonus.c srcbonus/load_images_bonus.c srcbonus/validate_map_bonus.c srcbonus/validate_playable_bonus.c srcbonus/map_errors_bonus.c srcbonus/fill_array_map_bonus.c srcbonus/move_enemy_bonus.c srcbonus/free_images_bonus.c srcbonus/big_map_helper_bonus.c 

OBJECTS = $(SOURCES:%.c=%.o)

OBJECTSBONUS = $(BONUS:%.c=%.o)

MLX_REPO = https://github.com/42Paris/minilibx-linux.git
MLX	=	$(MLX_DIR)/minilibx-linux/libmlx_Linux.a
MLX_DIR = ./mlx

LIBFT_DIR	=	./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC	=	cc
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I $(MLX_DIR)/minilibx-linux/ -I ./libft

MLX_FLAGS = -L $(LIBFT_DIR) -lft -L $(MLX_DIR)/minilibx-linux -Imlx_linux -lmlx -lXext -lX11 -lm -lbsd

all: $(MLX) $(LIBFT) $(NAME)	

$(MLX):
	@if [ ! -d $(MLX_DIR) ]; then \
		echo "Cloning"; \
		mkdir -p $(MLX_DIR); \
		cd $(MLX_DIR) && git clone $(MLX_REPO); \
	fi
	$(MAKE) -C $(MLX_DIR)/minilibx-linux

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS)

bonus: $(MLX) $(LIBFT) $(NAMEBONUS)

$(NAMEBONUS): $(OBJECTSBONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJECTS) $(OBJECTSBONUS)

fclean: clean
	rm -f $(NAME) $(NAMEBONUS)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)/minilibx-linux

re: fclean all

.PHONY: all clean fclean re
