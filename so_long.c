/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:33:38 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/19 18:58:05 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_pressed(int button, t_struct *mlx)
{
    static int i = 0;
    ft_printf("button_pressed:%d\n",button);
    ft_printf("[%s]:[%d] mlx->map.real_map[mlx->player.y][mlx->player.x]:%c\n",__FUNCTION__ ,__LINE__, mlx->map.real_map[mlx->player.y][mlx->player.x]);
    if (button == KEY_ESC)
    {
        mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
        mlx_destroy_image(mlx->mlx_ptr, mlx->player.img_mario);
        mlx_destroy_image(mlx->mlx_ptr, mlx->map.img_wall);
        mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
        exit(0);
    }
    else if ((button == ARROW_LEFT || button == KEY_A))
    {
        ft_printf("[%s]:[%d] mlx->map.real_map[mlx->player.y][mlx->player.x - 1]:%c\n",__FUNCTION__ ,__LINE__, mlx->map.real_map[mlx->player.y][mlx->player.x - 1]);
        if (mlx->map.real_map[mlx->player.y][mlx->player.x - 1] == 'E' \
            && mlx->finished)
            destroy_win(mlx);
        if (mlx->map.real_map[mlx->player.y][mlx->player.x - 1] != '1' \
            && mlx->map.real_map[mlx->player.y][mlx->player.x - 1] != 'E')
        {
            mlx->map.real_map[mlx->player.y][mlx->player.x] = '0';
            mlx->player.x--;
            if (mlx->map.real_map[mlx->player.y][mlx->player.x] == 'C')
                mlx->col.flag_c--;
            mlx->map.real_map[mlx->player.y][mlx->player.x] = 'P';
            mlx->player.f_counter++;
        }
        ft_printf("mlx->x:%d\n",mlx->player.x);
        ft_printf("button :%d exit\n",button);
        ft_printf("%d\n", mlx->player.f_counter);
    }
    else if ((button == ARROW_RIGHT || button == KEY_D))
    {
        ft_printf("[%s]:[%d] mlx->map.real_map[mlx->player.y][mlx->player.x + 1]:%c\n",__FUNCTION__ ,__LINE__, mlx->map.real_map[mlx->player.y][mlx->player.x + 1]);
        if (mlx->map.real_map[mlx->player.y][mlx->player.x + 1] == 'E' \
            && mlx->finished)
            destroy_win(mlx);
        else if (mlx->map.real_map[mlx->player.y][mlx->player.x + 1] != '1' \
            && mlx->map.real_map[mlx->player.y][mlx->player.x + 1] != 'E')
        {
            mlx->map.real_map[mlx->player.y][mlx->player.x] = '0';
            mlx->player.x++;
            if (mlx->map.real_map[mlx->player.y][mlx->player.x] == 'C')
                mlx->col.flag_c--;
            mlx->map.real_map[mlx->player.y][mlx->player.x] = 'P';
            mlx->player.f_counter++;
        }
        ft_printf("mlx->x:%d\n",mlx->player.x);
        ft_printf("button :%d exit\n", button);
        ft_printf("%d\n", mlx->player.f_counter);
    }
    else if ((button == ARROW_DOWN || button == KEY_S))
    {
        ft_printf("[%s]:[%d] mlx->map.real_map[mlx->player.y + 1][mlx->player.x]:%c\n",__FUNCTION__ ,__LINE__, mlx->map.real_map[mlx->player.y + 1][mlx->player.x]);
        if (mlx->map.real_map[mlx->player.y + 1][mlx->player.x] == 'E' \
            && mlx->finished)
            destroy_win(mlx);
        else if (mlx->map.real_map[mlx->player.y + 1][mlx->player.x] != '1' \
            && mlx->map.real_map[mlx->player.y + 1][mlx->player.x] != 'E')
        {
            mlx->map.real_map[mlx->player.y][mlx->player.x] = '0';
            mlx->player.y++;
            if (mlx->map.real_map[mlx->player.y][mlx->player.x] == 'C')
                mlx->col.flag_c--;
            mlx->map.real_map[mlx->player.y][mlx->player.x] = 'P';
            mlx->player.f_counter++;
        }
        ft_printf("mlx->y:%d\n",mlx->player.y);
        ft_printf("button :%d exit\n", button);
        ft_printf("%d\n", mlx->player.f_counter);
    }
    else if ((button == ARROW_UP || button == KEY_W))
    {
        ft_printf("[%s]:[%d] mlx->map.real_map[mlx->player.y - 1][mlx->player.x]:%c\n",__FUNCTION__ ,__LINE__, mlx->map.real_map[mlx->player.y - 1][mlx->player.x]);
        if (mlx->map.real_map[mlx->player.y - 1][mlx->player.x] == 'E' \
            && mlx->finished)
            destroy_win(mlx);
        else if (mlx->map.real_map[mlx->player.y - 1][mlx->player.x] != '1' \
            && mlx->map.real_map[mlx->player.y - 1][mlx->player.x] != 'E')
        {
            mlx->map.real_map[mlx->player.y][mlx->player.x] = '0';
            mlx->player.y--;
            if (mlx->map.real_map[mlx->player.y][mlx->player.x] == 'C')
                mlx->col.flag_c--;
            mlx->map.real_map[mlx->player.y][mlx->player.x] = 'P';
            mlx->player.f_counter++;
        }
        ft_printf("mlx->y:%d\n",mlx->player.y);
        ft_printf("button :%d exit\n", button);
        ft_printf("%d\n", mlx->player.f_counter);
    }
    else if (button == 35)
    {
        ft_printf("i :%d\n", i);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_wall, i, 0);
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

void inito(t_struct *mlx)
{
    int i;
    int j;

    j = 0;
    i = 0;
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_font, 0, 0);
    while (i < X)
    {
        if (i == ((X / 64 + 1) * 32))
            mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_wall, i - 1, 0);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_wall, i, 0);
        i += 32;
    }
    i -= 32;
    while (j + (32 * (int)(16/9.0)) < YW)
    {
        if (j == ((YW / 64 + 1) * 32))
            mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_wall, i, j - 1);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_wall, i, j);
        j += 32;
    }
    j -= 32;
    while (i > 0)
    {
        if (i == ((X / 64 + 1) * 32))
            mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_wall, i - 1, j);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_wall, i, j);
        i -= 32;
    }
    while (j > 0)
    {
        if (j == ((YW / 64 + 1) * 32))
            mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_wall, 0, j - 1);
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_wall, 0, j);
        j -= 32;
    }
}

// anim_counter : 10 000 = 1sec
int anim(t_struct *mlx)
{    
    if (mlx->anim_counter == 0 && !mlx->finished)
    {
        mlx->img_col = mlx->col.img_col1;
        if (mlx->finished == 0)
            mlx->img_end = mlx->end.img_end1;
        render_map(mlx);
    }
    else if (mlx->anim_counter == 1500)
    {
        mlx->img_col = mlx->col.img_col2;
        render_map(mlx);
    }
    else if (mlx->anim_counter == 3000)
    {
        mlx->img_col = mlx->col.img_col3;
        if (mlx->finished == 1)
        {
            mlx->finished = 2;
            mlx->img_end = mlx->end.img_end2;
        }
        render_map(mlx);
    }
    else if (mlx->anim_counter == 4500)
    {
        mlx->img_col = mlx->col.img_col4;
        render_map(mlx);
    }
    else if (mlx->anim_counter == 6000)
    {
        mlx->img_col = mlx->col.img_col5;
        render_map(mlx);
    }
    else if (mlx->anim_counter == 7500)
    {
        mlx->img_col = mlx->col.img_col6;
        if (mlx->finished == 2)
            mlx->img_end = mlx->end.img_end3;
        render_map(mlx);
        mlx->anim_counter = 0;
    }
    if (!mlx->col.flag_c && mlx->finished < 2)
        mlx->finished = 1;
    mlx->anim_counter++;

    return (0);
}

void render_all_map(t_struct *mlx)
{
    
}

int render_map(t_struct *mlx)
{
    char *temp;
    int i;
    int j;
    int i2;
    int j2;
    
    fill_min_max(mlx);
    i2 = 0;
    j2 = 0;
    i = mlx->map.min_x;
    j = mlx->map.min_y;
    // ft_printf("[%s]:[%d] mlx->map.min_x:%d\n",__FUNCTION__ ,__LINE__, mlx->map.min_x);
    // ft_printf("[%s]:[%d] mlx->map.min_y:%d\n",__FUNCTION__ ,__LINE__, mlx->map.min_y);
    // ft_printf("[%s]:[%d] mlx->map.max_x:%d\n",__FUNCTION__ ,__LINE__, mlx->map.max_x);
    // ft_printf("[%s]:[%d] mlx->map.max_y:%d\n",__FUNCTION__ ,__LINE__, mlx->map.max_y);
    mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_font, 0, 0);
    while (j < mlx->map.max_y)
    {
        while (i < mlx->map.max_x)
        {
            // ft_printf("[%s]:[%d] mlx->map.real_map[j][i]:%c\n",__FUNCTION__ ,__LINE__, mlx->map.real_map[j][i]);
            if (mlx->map.real_map[j][i] == '1')
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_wall, i2 * 32, j2 * 32);
            else if (mlx->map.real_map[j][i] == 'P')
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player.img_mario, i2 * 32, j2 * 32);
            else if (mlx->map.real_map[j][i] == 'E')
            {
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->end.img_end4, i2 * 32, j2 * 32);
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_end, i2 * 32, j2 * 32);
            }
            else if (mlx->map.real_map[j][i] == 'C')
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_col, i2 * 32, j2 * 32);
                i++;
                i2++;
        }
        j++;
        j2++;
        i = mlx->map.min_x;
        i2 = 0;
    }
    temp = ft_itoa(mlx->player.f_counter);
    mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 16, 20, 0x00FFFFFF, temp);
    free (temp);
    return (0);
}

// int render_map(t_struct *mlx)
// {
//     char *temp;

//     mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
//     inito(mlx);
//     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->end.img_end4, 320, (Y(320) - (Y(320)) % 32));
//     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_end, 320, (Y(320) - (Y(320)) % 32));
//     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_col, 160, (Y(160) - (Y(160)) % 32));
//     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_col, 352, (Y(352) - (Y(352)) % 32));
//     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_col, 64, (Y(296) - (Y(296)) % 32));
//     mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player.img_mario, mlx->player.x, mlx->player.y);
//     temp = ft_itoa(mlx->player.f_counter);
//     mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 16, 20, 0x00FFFFFF, temp);
//     free (temp);
//     return (0);
// }

void    check_x_max(t_struct *mlx, int test)
{
    int a;

    a = mlx->map.move_x;
    if (mlx->map.flag_x_min == 0 || test)
    {
        if ((mlx->map.size_x - mlx->player.x) - (mlx->win_size_x / 2) > 0 && a)
        {
            mlx->map.flag_x_max = 0;
            mlx->map.max_x = mlx->player.x + (mlx->win_size_x / 2);
        }
        else
        {
            mlx->map.flag_x_max = 1;
            mlx->map.max_x = mlx->map.size_x;
        }
    }
    else 
        mlx->map.max_x = mlx->win_size_x;
        ft_printf("\n[%s]:[%d] mlx->player.x :%d\n",__FUNCTION__ ,__LINE__, mlx->player.x);
        ft_printf("[%s]:[%d]+mlx->win_size_x / 2 :%d\n",__FUNCTION__ ,__LINE__, (mlx->win_size_x / 2));
        ft_printf("[%s]:[%d] mlx->map.max_x :%d\n",__FUNCTION__ ,__LINE__, mlx->map.max_x);
        ft_printf("[%s]:[%d] mlx->map.size_x :%d\n",__FUNCTION__ ,__LINE__, mlx->map.size_x);
}

void    check_x_min(t_struct *mlx, int test)
{
    int a;

    a = mlx->map.move_x;
    if (mlx->map.flag_x_max == 0 || test)
    {
        if (mlx->player.x - (mlx->win_size_x / 2) > 0 && a)
        {
            mlx->map.flag_x_min = 0;
            mlx->map.min_x = mlx->player.x - (mlx->win_size_x / 2);
        }
        else
        {
            mlx->map.flag_x_min = 1;
            mlx->map.min_x = 0;
        }
        ft_printf("\n[%s]:[%d] mlx->player.x :%d\n",__FUNCTION__ ,__LINE__, mlx->player.x);
        ft_printf("[%s]:[%d]-mlx->win_size_x / 2 :%d\n",__FUNCTION__ ,__LINE__, (mlx->win_size_x / 2));
        ft_printf("[%s]:[%d] mlx->map.min_x :%d\n",__FUNCTION__ ,__LINE__, mlx->map.min_x);
    }    
}

void    check_y_min(t_struct *mlx, int test)
{
    int a;

    a = mlx->map.move_y;
    if (mlx->map.flag_y_max == 0 || test)
    {
        if (mlx->player.y - (mlx->win_size_y / 2) > 0 && a)
        {
            mlx->map.flag_y_min = 0;
            mlx->map.min_y = mlx->player.y - (mlx->win_size_y / 2);
        }
        else
        {
            mlx->map.flag_y_min = 1;
            mlx->map.min_y = 0;
        }
        ft_printf("\n[%s]:[%d] mlx->player.y :%d\n",__FUNCTION__ ,__LINE__, mlx->player.y);
        ft_printf("[%s]:[%d]-mlx->win_size_y / 2 :%d\n",__FUNCTION__ ,__LINE__, (mlx->win_size_y / 2));
        ft_printf("[%s]:[%d] mlx->map.min_y :%d\n",__FUNCTION__ ,__LINE__, mlx->map.min_y);
    }
}

void    check_y_max(t_struct *mlx, int test)
{
    int a;

    a = mlx->map.move_y;
    if (mlx->map.flag_y_min == 0 || test)
    {
        if ((mlx->map.size_y - mlx->player.y) - (mlx->win_size_y / 2) > 0 && a)
        {
            mlx->map.flag_y_max = 0;
            mlx->map.max_y = mlx->player.y + (mlx->win_size_y / 2);
        }
        else
        {
            mlx->map.flag_y_max = 1;
            mlx->map.max_y = mlx->map.size_y;
        }
    }
    else 
        mlx->map.max_y = mlx->win_size_y;
        ft_printf("\n[%s]:[%d] mlx->player.y :%d\n",__FUNCTION__ ,__LINE__, mlx->player.y);
        ft_printf("[%s]:[%d]+mlx->win_size_y / 2 :%d\n",__FUNCTION__ ,__LINE__, (mlx->win_size_y / 2));
        ft_printf("[%s]:[%d] mlx->map.size_y :%d\n",__FUNCTION__ ,__LINE__, mlx->map.size_y);
        ft_printf("[%s]:[%d] mlx->map.max_y :%d\n",__FUNCTION__ ,__LINE__, mlx->map.max_y);
}

void init_min_max(t_struct *mlx)
{
    ft_printf("\n[%s]:[%d] \n",__FUNCTION__ ,__LINE__);
    check_x_min(mlx, 1);
    check_x_max(mlx, 1);
    check_y_min(mlx, 1);
    check_y_max(mlx, 1);
}

void fill_min_max(t_struct *mlx)
{
    check_x_min(mlx, 0);
    check_x_max(mlx, 0);
    check_y_min(mlx, 0);
    check_y_max(mlx, 0);

    // ft_printf("[%s]:[%d] px:%d\n",__FUNCTION__ ,__LINE__, px);
    // ft_printf("[%s]:[%d] py:%d\n",__FUNCTION__ ,__LINE__, py);
    // ft_printf("[%s]:[%d] mlx->win_size_x:%d\n",__FUNCTION__ ,__LINE__, mlx->win_size_x);
    // ft_printf("[%s]:[%d] mlx->win_size_y:%d\n",__FUNCTION__ ,__LINE__, mlx->win_size_y);
    // ft_printf("[%s]:[%d] mlx->map.min_x:%d\n",__FUNCTION__ ,__LINE__, mlx->map.min_x);
    // ft_printf("[%s]:[%d] mlx->map.min_y:%d\n",__FUNCTION__ ,__LINE__, mlx->map.min_y);
}

void fill_pos(t_struct *mlx, char c, int i, int j)
{
    int col_index;
    
    col_index = mlx->col.flag_c - mlx->col.flag_c_counter;
    // ft_printf("[%s]:[%d]\n",__FUNCTION__ ,__LINE__);
    if (c == 'C')
    {
        mlx->col.x[col_index] = i;
        mlx->col.y[col_index] = j;
        mlx->col.flag_c_counter--;
    }
    else if (c == 'P')
    {
        mlx->player.x = i;
        mlx->player.y = j;
    }
    else if (c == 'E')
    {
        mlx->end.x = i;
        mlx->end.y = j;
    }
    // ft_printf("[%s]:[%d]\n",__FUNCTION__ ,__LINE__);
}

void find_pos(t_struct *mlx)
{
    int     i;
    int     j;
    char    c;

    i = 0;
    j = 0;
    // ft_printf("[%s]:[%d]\n",__FUNCTION__ ,__LINE__);
    while (j < mlx->map.size_y)
    {
        while (i < mlx->map.size_x)
        {
            // ft_printf("[%s]:[%d]\n",__FUNCTION__ ,__LINE__);
            c = mlx->map.real_map[j][i];
            fill_pos(mlx, c, i, j);
            i++;
        }
        j++;
        i = 0;
    }
}

void init_player(t_struct *mlx)
{
    char	*pa;
    int iw;
    int ih;

	pa = "Mario/player/mario1.png";
    mlx->player.img_mario = mlx_png_file_to_image(mlx->mlx_ptr, pa, &iw, &ih);
    mlx->player.f_counter = 0;
}

void init_end(t_struct *mlx)
{
    char	*path1;
    char	*path2;
    char	*path3;
    char	*path4;
    int iw;
    int ih;

    path1 = "Mario/end/end1.png";
    mlx->end.img_end1 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);    
    path1 = "Mario/end/end2.png";
    mlx->end.img_end2 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
    path1 = "Mario/end/end3.png";
    mlx->end.img_end3 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
    path1 = "Mario/end/end4.png";
    mlx->end.img_end4 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
    mlx->img_end = mlx->end.img_end1;
}

void init_col(t_struct *mlx)
{
    char	*path1;
    int iw;
    int ih;

    mlx->col.flag_c_counter = mlx->col.flag_c;
    path1 = "Mario/col/col1.png";
    mlx->col.img_col1 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
    path1 = "Mario/col/col2.png";
    mlx->col.img_col2 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
    path1 = "Mario/col/col3.png";
    mlx->col.img_col3 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
    path1 = "Mario/col/col4.png";
    mlx->col.img_col4 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
    path1 = "Mario/col/col5.png";
    mlx->col.img_col5 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
    path1 = "Mario/col/col6.png";
    mlx->col.img_col6 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
    mlx->img_col = mlx->col.img_col1;
    mlx->col.x = (int *)malloc(sizeof(int) * mlx->col.flag_c);
    mlx->col.y = (int *)malloc(sizeof(int) * mlx->col.flag_c);
    if (!mlx->col.x || !mlx->col.y)
    {
        free_map(mlx->map.real_map);
        exit(1);
    }
}

void init_win(t_struct *mlx)
{
    char	*path;
    int iw;
    int sx;
    int sy;

    if (mlx->map.size_x * 32 < X)
        mlx->win_size_x = mlx->map.size_x;
    else 
    {
        mlx->map.move_x = 1;
        mlx->win_size_x = X / 32;
    }
    if (mlx->map.size_y * 32 < YW)
        mlx->win_size_y = mlx->map.size_y;
    else 
    {
        mlx->map.move_y = 1;
        mlx->win_size_y = YW / 32;
    }
    sx = mlx->win_size_x * 32;
    sy = mlx->win_size_y * 32;
    mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, sx, sy, "Grand Theft Auto");
    path = "Mario/wall1.png";
    mlx->map.img_wall = mlx_png_file_to_image(mlx->mlx_ptr, path, &iw, &iw);
    path = "Mario/font.png";
    mlx->map.img_font = mlx_png_file_to_image(mlx->mlx_ptr, path, &iw, &iw);
    mlx->finished = 0;
    mlx->anim_counter = 0;
}

void init_map(t_struct *mlx)
{
    int i;
    int sy;

    i = 1;
    sy = mlx->win_size_y / 32;
    // ft_printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map);
    mlx->map.little_map = (char **)malloc (sizeof(char *) * sy + 1);
    if (!mlx->map.little_map)
        exit (1);
    // ft_printf("[%s]:[%d] mlx->map.little_map:%p\n",__FUNCTION__ ,__LINE__, mlx->map.little_map[i]);
    
    while (i < sy)
    {
        if (!mlx->map.little_map[i])
            exit (1);
        i++;
        // ft_printf("[%s]:[%d] mlx->map.little_map:%p\n",__FUNCTION__ ,__LINE__, mlx->map.little_map[i]);
    }
    mlx->map.little_map[sy] = 0;
    // ft_printf("[%s]:[%d] mlx->map.little_map:%p\n",__FUNCTION__ ,__LINE__, mlx->map.little_map);
    mlx->map.flag_x_min = 0;
    mlx->map.flag_y_min = 0;
    mlx->map.flag_x_max = 0;
    mlx->map.flag_y_max = 0;
    mlx->map.move_x = 0;
    mlx->map.move_y = 0;
}

void init(int argc, char **argv, t_struct *mlx)
{
    mlx->player.flag_p = 0;
    mlx->end.flag_e = 0;
    mlx->col.flag_c = 0;
    mlx->map.size_x = 0;
    mlx->map.size_y = 0;
    parsing(argc, argv, mlx);
    // ft_printf("[%s]:[%d]\n",__FUNCTION__ ,__LINE__);
    init_win(mlx);
    // ft_printf("[%s]:[%d]\n",__FUNCTION__ ,__LINE__);
    init_player(mlx);
    // ft_printf("[%s]:[%d]\n",__FUNCTION__ ,__LINE__);
    init_end(mlx);
    // ft_printf("[%s]:[%d]\n",__FUNCTION__ ,__LINE__);
    init_col(mlx);
    // ft_printf("[%s]:[%d]\n",__FUNCTION__ ,__LINE__);
    find_pos(mlx);
    init_min_max(mlx);
}

int main(int argc, char **argv)
{
    // char	*path_mario = "Mario/player/mario1.png";
    // char	*path_wall = "Mario/wall1.png";
    // char	*path_font = "Mario/font.png";
    // char	path_col[6][30] = {
    //     "Mario/col/col1.png",
    //     "Mario/col/col2.png",
    //     "Mario/col/col3.png",
    //     "Mario/col/col4.png",
    //     "Mario/col/col5.png",
    //     "Mario/col/col6.png"
    //     };
    // char	path_end[4][30] = {"Mario/end/end1.png", "Mario/end/end2.png", "Mario/end/end3.png", "Mario/end/end4.png"};
    int xwin = 0;
    int ywin = 0;
    ft_printf("X:%d\n",X);
    ft_printf("Y:%d\n",YW);
    
    t_struct mlx;
    
    init(argc, argv, &mlx);
    ft_printf("[%s]:[%d] mlx.map.size_x:%d\n",__FUNCTION__ ,__LINE__, mlx.map.size_x);
    ft_printf("[%s]:[%d] mlx.map.size_y:%d\n",__FUNCTION__ ,__LINE__, mlx.map.size_y);
    
    ft_printf("[%s]:[%d] mlx->col.flag_c:%d\n",__FUNCTION__ ,__LINE__, mlx.col.flag_c);
    ft_printf("[%s]:[%d] player X:%d\n",__FUNCTION__ ,__LINE__, mlx.player.x);
    ft_printf("[%s]:[%d] player Y:%d\n",__FUNCTION__ ,__LINE__, mlx.player.y);
    ft_printf("[%s]:[%d] end X:%d\n",__FUNCTION__ ,__LINE__, mlx.end.x);
    ft_printf("[%s]:[%d] end Y:%d\n",__FUNCTION__ ,__LINE__, mlx.end.y);
    
    // int img_width, img_height;
    // mlx.player.x += 32;
    // mlx.player.y += 32;

    // mlx.mlx_ptr = mlx_init();
    // mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, X, YW, "Grand Theft Auto");
    // mlx.finished = 0;
    // mlx.anim_counter = 0;
    // mlx.player.img_mario = mlx_png_file_to_image(mlx.mlx_ptr, path_mario, &img_width, &img_height);
    // mlx.map.img_wall = mlx_png_file_to_image(mlx.mlx_ptr, path_wall, &img_width, &img_height);
    // mlx.map.img_font = mlx_png_file_to_image(mlx.mlx_ptr, path_font, &img_width, &img_height);
    // mlx.end.img_end1 = mlx_png_file_to_image(mlx.mlx_ptr, path_end[0], &img_width, &img_height);
    // mlx.end.img_end2 = mlx_png_file_to_image(mlx.mlx_ptr, path_end[1], &img_width, &img_height);
    // mlx.end.img_end3 = mlx_png_file_to_image(mlx.mlx_ptr, path_end[2], &img_width, &img_height);
    // mlx.end.img_end4 = mlx_png_file_to_image(mlx.mlx_ptr, path_end[3], &img_width, &img_height);

    // mlx.col.img_col1 = mlx_png_file_to_image(mlx.mlx_ptr, path_col[0], &img_width, &img_height);
    // mlx.col.img_col2 = mlx_png_file_to_image(mlx.mlx_ptr, path_col[1], &img_width, &img_height);
    // mlx.col.img_col3 = mlx_png_file_to_image(mlx.mlx_ptr, path_col[2], &img_width, &img_height);
    // mlx.col.img_col4 = mlx_png_file_to_image(mlx.mlx_ptr, path_col[3], &img_width, &img_height);
    // mlx.col.img_col5 = mlx_png_file_to_image(mlx.mlx_ptr, path_col[4], &img_width, &img_height);
    // mlx.col.img_col6 = mlx_png_file_to_image(mlx.mlx_ptr, path_col[5], &img_width, &img_height);

    // mlx.img_col = mlx.col.img_col1;

    ft_printf("real X map:%d\n",mlx.map.size_x);
    ft_printf("real Y map:%d\n",mlx.map.size_y);
    // mlx.map.size_x = 0;
    // mlx.map.size_y = 0;
    // inito(&mlx);
    // mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.player.img_mario, mlx.player.x, mlx.player.y);
    // mlx_key_hook(mlx.win_ptr,key_pressed, &mlx);
    mlx_loop_hook(mlx.mlx_ptr, anim, &mlx);
    mlx_hook(mlx.win_ptr, 3, (1L<<1), key_pressed, &mlx);
    mlx_hook(mlx.win_ptr, 17, 0L, destroy_win, &mlx);
    mlx_loop(mlx.mlx_ptr);
    free_map(mlx.map.real_map);
    return (0);
}
