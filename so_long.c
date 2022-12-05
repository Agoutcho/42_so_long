#include "so_long.h"
#define X 1920
#define Y ((int)(X/(16/9.0)))

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_struct {
    void *mlx_ptr;
    void *win_ptr;
}              t_struct;

int key_pressed(int button, int x, int y, void *param)
{
    t_struct *mlx;

    mlx = param;
    printf("button_pressed:%d\n",button);
    if (button == 1)
        mlx_pixel_put (mlx->mlx_ptr, mlx->win_ptr, x, y, 0x0E400FF);
    else if (button == 2)
        mlx_clear_window ( mlx->mlx_ptr, mlx->win_ptr );

    return (0);
}

int main(int argc, char **argv)
{
    printf("X:%d\n",X);
    printf("Y:%d\n",Y);
    
    t_data	img;
    t_struct mlx;
    mlx.mlx_ptr = mlx_init();
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, X, Y, "Test");
    img.img = mlx_new_image(mlx.mlx_ptr, X, Y);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    printf("img.bits_per_pixel:%d, img.line_length:%d, img.endian:%d\n", img.bits_per_pixel, img.line_length, img.endian);
    mlx_string_put (mlx.mlx_ptr, mlx.win_ptr, X/2, Y/2, 0x0FFFFFF, "Hello" );
    mlx_string_put (mlx.mlx_ptr, mlx.win_ptr, X*0.95, Y*0.05, 0x0E400FF, "You" );
    mlx_mouse_hook(mlx.win_ptr, key_pressed, &mlx);
    mlx_loop(mlx.mlx_ptr);

    return (0);
}
