NAME = so_long

all: alli
	cc -Wall -Wextra -Werror *.o libft/libft.a -o $(NAME) \
	 -Imlx -framework OpenGL -framework AppKit minilibx_opengl_20191021/libmlx.a
	
alli: ekke
	cc -c -Wall -Wextra -Werror *.c

ekke : ekkke
	Make -C libft/

ekkke:
	Make -C minilibx_opengl_20191021/

fclean: 
	rm *.o $(NAME)
	Make fclean -C libft/
	Make clean -C minilibx_opengl_20191021/