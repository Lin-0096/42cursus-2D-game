NAME := so_long
CC := cc
CFLAG := -Wall -Wextra -Werror

INCLUDES := -I includes -I libft -I MLX42/include

SRCS := src/main.c \
		src/parse_map.c \
		src/validate_map.c \
		src/map_utils.c \
		src/check_path.c \
		src/game_utils.c \
		src/render_game.c \
		src/new_play_game.c
#src/handle_input.c
OBJS := $(SRCS:.c=.o)

LIBFT_DIR := libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

MLX_REPO := https://github.com/codam-coding-college/MLX42.git
MLX_DIR := MLX42
MLX_LIB := $(MLX_DIR)/build/libmlx42.a
MLX_FLAGS := -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm
#-L linker search path
#-l link with library

all: $(LIBFT_LIB) $(MLX_LIB) $(NAME)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
		@$(CC) $(CFLAG) $(OBJS) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

$(LIBFT_LIB):
		@make -C $(LIBFT_DIR)

$(MLX_LIB):
		@if [ ! -d "$(MLX_DIR)" ]; then \
			git clone $(MLX_REPO) $(MLX_DIR); \
		fi;
		@cmake -B $(MLX_DIR)/build -S $(MLX_DIR)
		@cmake --build $(MLX_DIR)/build --parallel 4

#MLX42 is a graphics library that uses CMake as its build system generator(like libft uses make)
#-B build, build dir (put all generated files in MLX_42/build); -S source
#means using the CMakeLists.txt in MLX_42, and put all generated files in MLX_42/build
#--build : after configration process, actually builds the graphical library (libmlx42.a)
#-d DIR ture if dir exists and is a dir
#if [ ! -d "my_folder" ]; then \ \ fi;
#do i need -j4 / --parallel 4: compile up to 4 files simultaneously, which can speed up the build—especially on machines with multiple CPU cores.

%.o: %.c
		@$(CC) $(CFLAG) $(INCLUDES) -c $< -o $@

clean:
		@rm -f $(OBJS)
		@make clean -C $(LIBFT_DIR)

fclean: clean
		@rm -rf $(NAME) $(MLX_DIR)
		@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
