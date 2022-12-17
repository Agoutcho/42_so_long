/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:33:38 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/12 20:36:00 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_pressed(int button, t_struct *mlx)
{
    static int i = 0;
    printf("button_pressed:%d\n",button);
    if (button == KEY_ESC)
    {
        mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
        mlx_destroy_image(mlx->mlx_ptr, mlx->player.img_mario);
        mlx_destroy_image(mlx->mlx_ptr, mlx->img_wall);
        mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
        exit(0);
    }
    else if ((button == ARROW_LEFT || button == KEY_A) && mlx->player.x - 32 > 0)
    {
        mlx->player.x -= 32;
        printf("mlx->x:%d\n",mlx->player.x);
        printf("button :%d exit\n",button);
        mlx->player.f_counter++;
        printf("%d\n", mlx->player.f_counter);
    }
    else if ((button == ARROW_RIGHT || button == KEY_D) && (mlx->player.x + 64) < X)
    {
        mlx->player.x += 32;
        printf("mlx->x:%d\n",mlx->player.x);
        printf("button :%d exit\n", button);
        mlx->player.f_counter++;
        printf("%d\n", mlx->player.f_counter);
    }
    else if ((button == ARROW_DOWN || button == KEY_S) && (mlx->player.y + 64 + (32 * (int)(16/9.0)) < Y(X)))
    {
        mlx->player.y += 32;
        printf("mlx->y:%d\n",mlx->player.y);
        printf("button :%d exit\n", button);
        mlx->player.f_counter++;
        printf("%d\n", mlx->player.f_counter);
    }
    else if ((button == ARROW_UP || button == KEY_W) && mlx->player.y - 32 > 0)
    {
        mlx->player.y -= 32;
        printf("mlx->y:%d\n",mlx->player.y);
        printf("button :%d exit\n", button);
        mlx->player.f_counter++;
        printf("%d\n", mlx->player.f_counter);
    }
    else if (button == 35)
    {
        printf("i :%d\n", i);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall, i, 0);
        i +=32;
    }
    else if (button == 31)
    {
        mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    }
    render_map(mlx);

    return (0);
}

int destroy_win(t_struct *mlx)
{
    mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
    exit(0);

    return (0);
}

void init(t_struct *mlx)
{
    int i;
    int j;

    j = 0;
    i = 0;
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_font, 0, 0);
    while (i < X)
    {
        if (i == ((X / 64 + 1) * 32))
            mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall, i - 1, 0);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall, i, 0);
        i += 32;
    }
    i -= 32;
    while (j + (32 * (int)(16/9.0)) < YW)
    {
        if (j == ((YW / 64 + 1) * 32))
            mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall, i, j - 1);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall, i, j);
        j += 32;
    }
    j -= 32;
    while (i > 0)
    {
        if (i == ((X / 64 + 1) * 32))
            mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall, i - 1, j);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall, i, j);
        i -= 32;
    }
    while (j > 0)
    {
        if (j == ((YW / 64 + 1) * 32))
            mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall, 0, j - 1);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall, 0, j);
        j -= 32;
    }
}

// anim_counter : 10 000 = 1sec
int anim(t_struct *mlx)
{
    static int anim_counter = 0;
    
    if (anim_counter == 0 && !mlx->finished)
    {
        mlx->img_col = mlx->col.img_col1;
        if (!mlx->finished)
            mlx->img_end = mlx->img_end1;
        render_map(mlx);
    }
    else if (anim_counter == 1500)
    {
        mlx->img_col = mlx->col.img_col2;
        render_map(mlx);
    }
    else if (anim_counter == 3000)
    {
        mlx->img_col = mlx->col.img_col3;
        if (!mlx->finished)
            mlx->img_end = mlx->img_end2;
        render_map(mlx);
    }
    else if (anim_counter == 4500)
    {
        mlx->img_col = mlx->col.img_col4;
        render_map(mlx);
    }
    else if (anim_counter == 6000)
    {
        mlx->img_col = mlx->col.img_col5;
        render_map(mlx);
    }
    else if (anim_counter == 7500)
    {
        mlx->img_col = mlx->col.img_col6;
        if (!mlx->finished)
            mlx->img_end = mlx->img_end3;
        render_map(mlx);
        anim_counter = 0;
        mlx->finished = 1;
    }
    anim_counter++;

    return (0);
}

int render_map(t_struct *mlx)
{
    char temp[15];

    mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    init(mlx);
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_end4, 320, (Y(320) - (Y(320)) % 32));
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_end, 320, (Y(320) - (Y(320)) % 32));
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_col, 160, (Y(160) - (Y(160)) % 32));
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_col, 352, (Y(352) - (Y(352)) % 32));
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_col, 64, (Y(296) - (Y(296)) % 32));
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player.img_mario, mlx->player.x, mlx->player.y);
    sprintf(temp, "%d", mlx->player.f_counter );
    mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 16, 20, 0x00FFFFFF, temp);
    return (0);
}

int main(int argc, char **argv)
{
    char	*path_mario = "Mario/player/mario1.png";
    char	*path_wall = "Mario/wall1.png";
    char	*path_font = "Mario/font.png";
    char	path_col[6][30] = {
        "Mario/col/col1.png",
        "Mario/col/col2.png",
        "Mario/col/col3.png",
        "Mario/col/col4.png",
        "Mario/col/col5.png",
        "Mario/col/col6.png"
        };
    char	path_end[4][30] = {"Mario/end/end1.png", "Mario/end/end2.png", "Mario/end/end3.png", "Mario/end/end4.png"};
    int xwin = 0;
    int ywin = 0;
    printf("X:%d\n",X);
    printf("Y:%d\n",YW);
    
    
    t_struct mlx;
    int img_width, img_height;
    mlx.player.x = 32;
    mlx.player.y = 32;

    mlx.mlx_ptr = mlx_init();
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, X, YW, "Test");
    mlx.finished = 0;
    mlx.anim_counter = 0;
    mlx.player.img_mario = mlx_png_file_to_image(mlx.mlx_ptr, path_mario, &img_width, &img_height);
    mlx.img_wall = mlx_png_file_to_image(mlx.mlx_ptr, path_wall, &img_width, &img_height);
    mlx.img_font = mlx_png_file_to_image(mlx.mlx_ptr, path_font, &img_width, &img_height);
    mlx.img_end1 = mlx_png_file_to_image(mlx.mlx_ptr, path_end[0], &img_width, &img_height);
    mlx.img_end2 = mlx_png_file_to_image(mlx.mlx_ptr, path_end[1], &img_width, &img_height);
    mlx.img_end3 = mlx_png_file_to_image(mlx.mlx_ptr, path_end[2], &img_width, &img_height);
    mlx.img_end4 = mlx_png_file_to_image(mlx.mlx_ptr, path_end[3], &img_width, &img_height);

    mlx.col.img_col1 = mlx_png_file_to_image(mlx.mlx_ptr, path_col[0], &img_width, &img_height);
    mlx.col.img_col2 = mlx_png_file_to_image(mlx.mlx_ptr, path_col[1], &img_width, &img_height);
    mlx.col.img_col3 = mlx_png_file_to_image(mlx.mlx_ptr, path_col[2], &img_width, &img_height);
    mlx.col.img_col4 = mlx_png_file_to_image(mlx.mlx_ptr, path_col[3], &img_width, &img_height);
    mlx.col.img_col5 = mlx_png_file_to_image(mlx.mlx_ptr, path_col[4], &img_width, &img_height);
    mlx.col.img_col6 = mlx_png_file_to_image(mlx.mlx_ptr, path_col[5], &img_width, &img_height);

    mlx.img_col = mlx.col.img_col1;
    printf("img_width:%d\n",img_width);
    printf("img_height:%d\n",img_height);
    mlx_get_screen_size(mlx.mlx_ptr, &xwin, &ywin);
    printf("real X:%d\n",xwin);
    printf("real Y:%d\n",ywin);
    init(&mlx);
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.player.img_mario, mlx.player.x, mlx.player.y);
    // mlx_key_hook(mlx.win_ptr,key_pressed, &mlx);
    mlx_loop_hook(mlx.mlx_ptr, anim, &mlx);
    mlx_hook(mlx.win_ptr, 3, (1L<<1), key_pressed, &mlx);
    mlx_hook(mlx.win_ptr, 17, 0L, destroy_win, &mlx);
    mlx_loop(mlx.mlx_ptr);

    return (0);
}
