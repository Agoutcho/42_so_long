NAME = so_long

SRCS = 			checker.c \
				error.c \
				fill_min_max.c \
				find_position.c \
				init.c \
				key_pressing.c \
				parsing.c \
				render_map.c \
				route_checker.c \
				so_long.c

BONUS = 		checker_bonus.c \
				error.c \
				fill_min_max.c \
				find_position.c \
				init.c \
				key_pressing.c \
				parsing.c \
				render_map.c \
				route_checker.c \
				so_long.c

HEADER_FILES = so_long.h libft/libft.h minilibx_opengl_20191021/mlx.h

LIBS = minilibx_opengl_20191021/libmlx.a libft/libft.a

OBJS = $(SRCS:.c=.o)

OBJS_DEPS = $(SRCS:.c=.d)

BOBJS_DEPS = $(BONUS:.c=.d)

BOBJS = $(BONUS:.c=.o)

DEPS = so_long.d

CC = gcc
C_FLAGS = -Wall -Wextra -Werror -I. -MD
MLXCC = -Imlx -framework OpenGL -framework AppKit

%.o: %.c $(HEADER_FILES) Makefile
	$(CC) $(C_FLAGS) -c $< -o $@

.PHONY: all
all: libs $(NAME)

.PHONY: libs
libs:
	@$(MAKE) -C ./minilibx_opengl_20191021/
	@$(MAKE) -C ./libft/

$(NAME): $(OBJS) $(HEADER_FILES) Makefile
	@$(CC) $(C_FLAGS) -c $(SRCS)
	@$(CC) $(C_FLAGS) $(MLXCC) -o $(NAME) $(OBJS) $(LIBS)

.PHONY: bonus
bonus: $(BOBJS) $(INCL) libs Makefile
	rm -f $(BOBJS)
	@$(CC) $(C_FLAGS) -c $(BONUS)
	@$(CC) $(C_FLAGS) $(MLXCC) -o $(NAME) $(BOBJS) $(LIBS)

.PHONY: clean
clean:
	$(MAKE) clean -C ./minilibx_opengl_20191021/
	$(MAKE) clean -C ./libft/
	rm -f $(OBJS) $(BOBJS) $(NAME) $(OBJS_DEPS) $(BOBJS_DEPS)

.PHONY: fclean
fclean: clean
	$(MAKE) fclean -C ./libft/
	rm -f $(NAME)

.PHONY: re
re: fclean all

-include $(DEPS)
