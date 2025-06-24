NAME := so_long
CC := cc
CFLAG := -Wall -Wextra -Werror

SRCS := src/main.c
OBJS := $(SRCS:.c=.o)
INCLUDES := -I includes
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBTS)
		$(CC) $(CFLAG) $(LIBFT) $(OBTS) -o $(NAME)

$(LIBFT):
		make -c $(LIBFT_DIR)

%.o: %.c
		$(CC) $(CFLAG) $(INCLUDES) -c $< -o $@

clean:
		rm -f $(OBTS)
		make clean -C $(LIBFT_DIR)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
