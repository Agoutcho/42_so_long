all:
	cc so_long.c -o so_long libmlx.dylib -I minilibx_mms_20200219 \
	-L minilibx_mms_20200219 -lmlx -framework OpenGL -framework AppKit
	