#include "so_long.h"


int key_pressed(int button, t_struct *mlx)
{
    // t_struct *mlx;

    // mlx = param;
    printf("button_pressed:%d\n",button);
    if (button == KEY_ESC)
    {
        mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
        mlx_destroy_image(mlx->mlx_ptr, mlx->player.img_mario);
        mlx_destroy_image(mlx->mlx_ptr, mlx->img_wall);
        mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
        exit(0);
    }
    else if ((button == ARROW_LEFT || button == KEY_A) && mlx->player.xpos - 32 > 0)
    {        
        // init(mlx);
        
        mlx->player.xpos -= 32;
        printf("mlx->xpos:%d\n",mlx->player.xpos);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player.img_mario, mlx->player.xpos, mlx->player.ypos);
        mlx_sync(2, mlx->win_ptr);
        mlx_sync(1, mlx->player.img_mario);
        
        mlx_sync(3, mlx->win_ptr);
        printf("button :%d exit\n",button);
    }
    else if ((button == ARROW_RIGHT || button == KEY_D) && (mlx->player.xpos + 64) < X)
    {
        init(mlx);
        mlx->player.xpos += 32;
        printf("mlx->xpos:%d\n",mlx->player.xpos);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player.img_mario, mlx->player.xpos, mlx->player.ypos);
        printf("button :%d exit\n", button);
    }
    else if ((button == ARROW_DOWN || button == KEY_S) && (mlx->player.ypos + 64 + (32 * (int)(16/9.0)) < Y))
    {
        init(mlx);
        mlx->player.ypos += 32;
        printf("mlx->ypos:%d\n",mlx->player.ypos);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player.img_mario, mlx->player.xpos, mlx->player.ypos);
        printf("button :%d exit\n", button);
    }
    else if ((button == ARROW_UP || button == KEY_W) && mlx->player.ypos - 32 > 0)
    {
        init(mlx);
        mlx->player.ypos -= 32;
        printf("mlx->ypos:%d\n",mlx->player.ypos);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player.img_mario, mlx->player.xpos, mlx->player.ypos);
        printf("button :%d exit\n", button);
    }
    else if (button == 36)
    {
        finished(mlx);
    }

    return (0);
}

int destroy_win(t_struct *mlx)
{
    mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
    exit(0);

    return (0);
}

void change(t_struct *mlx)
{
    mlx->player.xpos += 50;
    mlx->player.ypos += 50;
    printf("mlx->xpos:%d\n",mlx->player.xpos);
}

void init(t_struct *mlx)
{
    mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    int i;
    int j;

    j = 0;
    i = 0;
    while (i < X)
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall, i, 0);
        i += 32;
    }
    i -= 32;
    while (j + (32 * (int)(16/9.0)) <= Y)
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall, i, j);
        j += 32;
    }
    j -= 32;
    while (i > 0)
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall, i, j);
        i -= 32;
    }
    while (j > 0)
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall, 0, j);
        j -= 32;
    }
}

void counting()
{
    unsigned int i;

    i = 1;
    while (i)
    {i++;}
}

void finished(t_struct *mlx)
{
    // static int nbr = 0;

    // mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    // if (nbr == 0)
    //     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_end1, 300, 200);
    // if (nbr == 1)
    //     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_end2, 300, 200);
    // if (nbr == 2)
    //     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_end3, 300, 200);
    // nbr++;
    // nbr %= 3;
    // printf("nbr:%d\n",nbr);

    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_end1, 300, 200);
    mlx_sync(1, mlx->img_end2);
    mlx_sync(2, mlx->win_ptr);
    mlx_sync(3, mlx->win_ptr);
    // mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_end2, 300, 200);
    // mlx_sync(1, mlx->win_ptr);
    // mlx_sync(2, mlx->win_ptr);
    // // mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    // mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_end3, 300, 200);
}

int main(int argc, char **argv)
{
    char	*path_mario = "Mario/mario1.png";
    char	*path_wall = "Mario/wall1.png";
    char	path_end[3][15] = {"Mario/end1.png", "Mario/end2.png", "Mario/end3.png"};
    printf("X:%d\n",X);
    printf("Y:%d\n",Y);
    
    t_struct mlx;
    int img_width, img_height;
    mlx.player.xpos = 32;
    mlx.player.ypos = 32;

    mlx.mlx_ptr = mlx_init();
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, X, Y, "Test");

    mlx.player.img_mario = mlx_png_file_to_image(mlx.mlx_ptr, path_mario, &img_width, &img_height);
    mlx.img_wall = mlx_png_file_to_image(mlx.mlx_ptr, path_wall, &img_width, &img_height);
    mlx.img_end1 = mlx_png_file_to_image(mlx.mlx_ptr, path_end[0], &img_width, &img_height);
    mlx.img_end2 = mlx_png_file_to_image(mlx.mlx_ptr, path_end[1], &img_width, &img_height);
    mlx.img_end3 = mlx_png_file_to_image(mlx.mlx_ptr, path_end[2], &img_width, &img_height);
    printf("img_width:%d\n",img_width);
    printf("img_height:%d\n",img_height);
    init(&mlx);
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.player.img_mario, mlx.player.xpos, mlx.player.ypos);
    // mlx_key_hook(mlx.win_ptr,key_pressed, &mlx);
    mlx_hook(mlx.win_ptr, 3, (1L<<1), key_pressed, &mlx);
    mlx_hook(mlx.win_ptr, 17, 0L, destroy_win, &mlx);
    mlx_loop(mlx.mlx_ptr);

    return (0);
}
