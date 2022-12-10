/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:26:26 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/10 21:07:41 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>

#define ARROW_LEFT 123
#define ARROW_RIGHT 124
#define ARROW_DOWN 125
#define ARROW_UP 126

#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

#define KEY_ESC 53

#define X 640
#define Y ((int)(X/(16/9.0)))

typedef struct s_player {
    void *img_mario;
    int xpos;
    int ypos;
    int f_counter;
}              t_player;

typedef struct s_col {
    void *img_col;
    int col_counter;
}              t_col;

typedef struct s_struct {
    void *mlx_ptr;
    void *win_ptr;
    void *img_wall;
    void *img_end1;
    void *img_end2;
    void *img_end3;
    t_player player;
    t_col col;
}              t_struct;

int destroy_win(t_struct *mlx);
void change(t_struct *mlx);
void init(t_struct *mlx);
void finished(t_struct *mlx);

#endif
